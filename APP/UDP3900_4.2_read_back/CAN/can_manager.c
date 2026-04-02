/**
 ****************************************************************************************************
 * @file        can_manager.c
 * @brief       CAN业务逻辑管理层：负责协议解析、数据分发与任务调度
 ****************************************************************************************************
 */
#include "can_manager.h"

/* --- 全局监控变量 (供 UI 包含 can_manager.h 后读取) --- */
float g_read_volt = 0.0f;
float g_read_curr = 0.0f;


/* ------------------ [私有资源] ------------------ */
/* --- [2. 任务句柄与属性定义] --- */
static osThreadId_t canRxTaskHandle;
static osThreadId_t canTxTaskHandle;

// 接收解析任务属性：优先级稍高，确保及时处理队列，防止溢出
static const osThreadAttr_t canRxTask_attr = {
    .name = "CanRxTask",
    .stack_size = 512 * 4,
    .priority = osPriorityAboveNormal,
};

// 定时查询任务属性：优先级普通即可
static const osThreadAttr_t canQueryTask_attr = {
    .name = "CanQueryTask",
    .stack_size = 256 * 4,
    .priority = osPriorityNormal,
};

/* ------------------ [内部工具函数] ------------------ */
/**
 * @brief  私有工具函数：将大端序字节数组解析为 float (Big-Endian to Float)
 */
static inline float _Unpack_Float_BE(const uint8_t *p_source) {
    union {
        float f;
        uint8_t b[4];
    } conv;
    
    conv.b[3] = p_source[0];
    conv.b[2] = p_source[1];
    conv.b[1] = p_source[2];
    conv.b[0] = p_source[3];
    
    return conv.f;
}
/**
 * @brief 小端序解析 (针对你提供的 90 03 9B 3F 案例)
 * @param p_source 指向 Data[4] 的指针
 */
static inline float _Decode_Float_LE(const uint8_t *p_source) {
    union {
        float f;
        uint8_t b[4];
    } conv;
    
    // 直接按顺序拷贝：Data[4]->b[0], Data[5]->b[1], Data[6]->b[2], Data[7]->b[3]
    // 这样 90 03 9B 3F 会被正确识别为 0x3F9B0390
    memcpy(conv.b, p_source, 4); 
    
    return conv.f;
}
/**
 * @brief 使用位域联合体构造并发送查询指令
 * @param data_index: CDATA_ADJ_VOUT 或 CDATA_ADJ_IOUT
 */
void Protocol_Send_Query_Command(e_can_data data_index) {
    type_can_message tx_msg = {0};

    // 1. 构造 ID (完全使用位域，后期修改结构体 bits 即可自动适配)
    tx_msg.can_id.id_bit.addr        = CANID_ADDR1;         // 设备地址 1
    tx_msg.can_id.id_bit.ch_num      = CANID_CHALL;         // 所有通道
    tx_msg.can_id.id_bit.device_type = CANID_DBUCK_DCDC;    // 设备类型
    tx_msg.can_id.id_bit.mode        = CANID_ADJ_MODE;      // 模式
    tx_msg.can_id.id_bit.comm_type   = ORDER_DATA_READ;     // 指令类型: 6 (读取)
    tx_msg.can_id.id_bit.dir         = CANID_DIR_RX;        // 方向: 0 (发给DSP)

    // 2. 构造 Data (使用 union)
    tx_msg.can_data.u8_data[0] = (uint8_t)data_index; 
    
    // 3. 调用底层驱动发送扩展帧
    CANFD_Send_Extended(tx_msg.can_id.id, tx_msg.can_data.u8_data);
}

/**
 * @brief 发送侧：轮询查询任务
 */
void CAN_Query_Polling_Task(void *argument) {
    for(;;) {
        // 轮流查询电压和电流，中间给 DSP 留出响应时间
        Protocol_Send_Query_Command(CDATA_ADJ_VOUT);
        osDelay(100); 

        Protocol_Send_Query_Command(CDATA_ADJ_IOUT);
        osDelay(100);
    }
}

/* ------------------ [核心解析任务] ------------------ */
/**
 * @brief 接收侧：协议解析任务
 */
void CAN_Msg_Process_Task(void *argument) {
    CAN_Msg_t rx_raw;
    type_can_message msg;

    for(;;) {
        // 阻塞等待接收队列
        if (osMessageQueueGet(can_rx_queue_handle, &rx_raw, NULL, osWaitForever) == osOK) {
            msg.can_id.id = rx_raw.Identifier;
            memcpy(msg.can_data.u8_data, rx_raw.Data, 8);
            
            // A. 处理来自 DSP 的回传数据 (dir == 1)
            if(msg.can_id.id_bit.dir == CANID_DIR_TX) {     
                
                if(msg.can_id.id_bit.comm_type == ORDER_DATA_READ) {
                    float val = _Decode_Float_LE(&msg.can_data.u8_data[4]);
                                     
                    if(msg.can_data.u8_data[0] == CDATA_ADJ_VOUT) {
                       PowerInfo.Read.volt_read = (double)val; // 只管写数据，像写数据库一样
                        // 调试打印：不使用 %f，使用 %d 打印整数部分和小数部分
//                    int v_int = (int)val;
//                    int v_dec = (int)((val - v_int) * 1000);
//                    printf("CAN_RX -> Volt: %d.%03d V\r\n", v_int, abs(v_dec));
                    } 
                    else if(msg.can_data.u8_data[0] == CDATA_ADJ_IOUT) {
                      PowerInfo.Read.curr_read = (double)val;
                    }                  
                }
            }
            
            // B. 处理上位机下发的动作指令监听 (dir == 0)
            else if(msg.can_id.id_bit.comm_type == ORDER_CONTROL) {
                // 原有的动作处理逻辑...
            }
        }
    }
}


/* --- [5. 导出启动接口] --- */
void CAN_Task_App_Start(void) {
    // 1. 初始化底层资源 (队列、锁、FDCAN硬件)
    CAN_Hardware_Resources_Init(); 
    
    // 2. 创建解析任务 (RX)
    canRxTaskHandle = osThreadNew(CAN_Msg_Process_Task, NULL, &canRxTask_attr);
    
    // 3. 创建查询任务 (TX)
    canTxTaskHandle = osThreadNew(CAN_Query_Polling_Task, NULL, &canQueryTask_attr);

    // 检查创建结果
    if (canRxTaskHandle == NULL || canTxTaskHandle == NULL) {
        printf("[Error] CAN Service Tasks Start Failed!\r\n");
    }
}
