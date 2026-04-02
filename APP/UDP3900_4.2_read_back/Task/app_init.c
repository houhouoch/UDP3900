#include "app_init.h"
#include "cmsis_os2.h"
#include "stdio.h"

/* 包含各个模块的头文件 */
#include "can_manager.h"
#include "Gui_Task.h"
#include "main.h" // 用于访问硬件控制如 LED_TOGGLE

/* ------------------ [1. 任务句柄与属性定义] ------------------ */

// 管理器任务
static osThreadId_t AppManagerHandle;
static const osThreadAttr_t AppManager_attr = {
    .name = "AppManager",
    .stack_size = 512 * 4,
    .priority = osPriorityHigh, 
};

// LED 监控任务
static osThreadId_t ledTaskHandle;
static const osThreadAttr_t ledTask_attr = {
    .name = "LedTask",
    .stack_size = 256 * 4,
    .priority = osPriorityLow,
};

/* ------------------ [2. 业务任务函数实现] ------------------ */

/**
 * @brief LED 闪烁任务 (系统心跳监控)
 */
void StartLedTask(void *argument) {
    
    type_can_message heartbeat;
    heartbeat.can_id.id = 0; // 先清零
    heartbeat.can_id.id_bit.addr = 1;         // 从机地址 1
    heartbeat.can_id.id_bit.comm_type = 0;    // ORDER_NULL (心跳)
    heartbeat.can_id.id_bit.dir = 1;          // 从机发送
    heartbeat.can_id.id_bit.device_type = 1;  // BUCK

    CANFD_Send_Extended(heartbeat.can_id.id, (uint8_t*)"HEARTBIT");
    for(;;) {
        LED_TOGGLE();    
        osDelay(500);
    }
}

/**
 * @brief APP 管理器任务 (带头大哥)
 */
void StartAppManager(void *argument) {
    printf(">>> [System] Booting App Manager...\r\n");

    // 1.确保你的 DMA2D Mutex 已经创建完毕
    DMA2D_Mutex_Init();

    // 2. 启动 CAN 业务逻辑 (调用你写的 can_manager 接口)
    CAN_Task_App_Start();

    // 3. 启动 LED 监控任务
    ledTaskHandle = osThreadNew(StartLedTask, NULL, &ledTask_attr);

    // 4. 启动 GUI 任务
    extern void GUI_Task(void *argument);
    extern const osThreadAttr_t GUITask_attributes;
    osThreadNew(GUI_Task, NULL, &GUITask_attributes);

    printf(">>> [System] All components started successfully!\r\n");

    // 5. 自杀，释放 Manager 任务占用的堆栈空间
    osThreadTerminate(osThreadGetId());
}


