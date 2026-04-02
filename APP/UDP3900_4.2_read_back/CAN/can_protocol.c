#include "can_protocol.h"
#include "can.h" 
#include "can_manager.h"


/**
 * @brief  双向DCDC+隔离Buck 开启序列
 * @details 顺序：1. 开启隔离DCDC (11) -> 2. 开启BUCK (1)
 */
void Power_System_Start_Sequence(void) {
    type_can_id  tx_id = {0};
    type_can_data tx_data = {0};

    // 构造 ID: 0x01250001
    tx_id.id_bit.addr        = 1;
    tx_id.id_bit.ch_num      = 0;
    tx_id.id_bit.device_type = CANID_DBUCK_DCDC; // 5
    tx_id.id_bit.mode        = CANID_ADJ_MODE;   // 4
    tx_id.id_bit.comm_type   = ORDER_CONTROL;    // 1
    tx_id.id_bit.dir         = CANID_DIR_RX;     // 0

    // 第一帧：开启隔离 DCDC (CONTROL_DC_EN = 11 / 0x0B)
    memset(tx_data.u8_data, 0, 8);
    tx_data.u16_data[0] = CONTROL_DC_EN; 
    CANFD_Send_Extended(tx_id.id, tx_data.u8_data);
    
   // osDelay(30); // 适当延时，等待 DCDC 稳定

    // 第二帧：开启 BUCK (CONTROL_OUT_EN = 1)
    memset(tx_data.u8_data, 0, 8);
    tx_data.u16_data[0] = CONTROL_OUT_EN; 
    CANFD_Send_Extended(tx_id.id, tx_data.u8_data);
}

/**
 * @brief  双向DCDC+隔离Buck 关闭序列
 * @details 顺序：1. 关闭隔离DCDC (10) -> 2. 关闭BUCK (0)
 */
void Power_System_Stop_Sequence(void) {
    type_can_id  tx_id = {0};
    type_can_data tx_data = {0};

    // 构造相同的 ID: 0x01250001
    tx_id.id_bit.addr        = 1;
    tx_id.id_bit.ch_num      = 0;
    tx_id.id_bit.device_type = CANID_DBUCK_DCDC;
    tx_id.id_bit.mode        = CANID_ADJ_MODE;
    tx_id.id_bit.comm_type   = ORDER_CONTROL;
    tx_id.id_bit.dir         = CANID_DIR_RX;

    // 第一帧：关闭隔离 DCDC (CONTROL_DC_STOP = 10 / 0x0A)
    memset(tx_data.u8_data, 0, 8);
    tx_data.u16_data[0] = CONTROL_DC_STOP; 
    CANFD_Send_Extended(tx_id.id, tx_data.u8_data);
    
    //osDelay(30); 

    // 第二帧：关闭 BUCK (CONTROL_OUT_STOP = 0)
    memset(tx_data.u8_data, 0, 8);
    tx_data.u16_data[0] = CONTROL_OUT_STOP; 
    CANFD_Send_Extended(tx_id.id, tx_data.u8_data);
}


/**
 * @brief  统一发送动作控制指令（带浮点数负载）
 * @param  action: 动作码 (如 CONTROL_SET_OUTV = 0x04)
 * @param  value:  需要设置的浮点数值
 */
void CAN_Protocol_Send_Control_Float(uint16_t action, float value) {
    type_can_id tx_id = {0};
    type_can_data tx_data = {0};

    // 1. 构造 ID: 0x01250001
    // 这里建议使用之前建议的 Context 上下文，目前先按你要求的固定值写死
    tx_id.id_bit.addr        = 1;
    tx_id.id_bit.ch_num      = 0;
    tx_id.id_bit.device_type = CANID_DBUCK_DCDC; // 5
    tx_id.id_bit.mode        = CANID_ADJ_MODE;   // 4
    tx_id.id_bit.comm_type   = ORDER_CONTROL;    // 1
    tx_id.id_bit.dir         = CANID_DIR_RX;     // 0

    // 2. 构造 Data 载荷
    // Byte 0-1: 动作码 (如 0x0004)
    tx_data.u16_data[0] = action; 

    // Byte 4-7: 浮点数 (STM32小端模式下，10.0f 存储为 00 00 20 41)
    tx_data.f32_data[1] = value; 

    // 3. 调用你底层 can.c 的发送函数
    CANFD_Send_Extended(tx_id.id, tx_data.u8_data);
}






