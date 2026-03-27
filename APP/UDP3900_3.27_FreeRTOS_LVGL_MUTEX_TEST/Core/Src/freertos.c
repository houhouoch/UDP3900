/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "FreeRTOS.h"
#include "cmsis_os2.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for GUITask */
osThreadId_t GUITaskHandle;
const osThreadAttr_t GUITask_attributes = {
  .name = "GUITask",
  .stack_size = 1024 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
osThreadId_t ledTaskHandle;
const osThreadAttr_t ledTask_attr = {
    .name = "LedTask",
    .stack_size = 256 * 4,
    .priority = osPriorityNormal,
};

/* 1. LED 显示任务 */
void StartLedTask(void *argument) {
    for(;;) {
    LED_TOGGLE();
    V_SET_LED(1);
    osDelay(500);
    V_SET_LED(0);
    osDelay(500);

    }
}

/* USER CODE END FunctionPrototypes */

void GUI_Task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);
void vApplicationStackOverflowHook(xTaskHandle xTask, char *pcTaskName);
void vApplicationMallocFailedHook(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, char *pcTaskName)
{
   /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */
}
/* USER CODE END 4 */

/* USER CODE BEGIN 5 */
void vApplicationMallocFailedHook(void)
{
   /* vApplicationMallocFailedHook() will only be called if
   configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
   function that will get called if a call to pvPortMalloc() fails.
   pvPortMalloc() is called internally by the kernel whenever a task, queue,
   timer or semaphore is created. It is also called by various parts of the
   demo application. If heap_1.c or heap_2.c are used, then the size of the
   heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
   FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
   to query the size of free heap space that remains (although it does not
   provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of GUITask */
  GUITaskHandle = osThreadNew(GUI_Task, NULL, &GUITask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
   ledTaskHandle      = osThreadNew(StartLedTask,      NULL, &ledTask_attr);
  /* USER CODE END RTOS_EVENTS */

}
#include "dma2d.h"
#include "lvgl.h"
#include "lv_port_disp.h"
/* USER CODE BEGIN Header_GUI_Task */
#include "dma2d.h"
/**
  * @brief  Function implementing the GUITask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_GUI_Task */

void lv_demo_staggered_boxes_ONE(void)
{
    /* 1. 先创建一个真实的方块对象 */
    lv_obj_t * my_box = lv_obj_create(lv_scr_act()); 
    lv_obj_set_size(my_box, 100, 100);                          // 设置大小 100x100
    lv_obj_set_style_bg_color(my_box, lv_palette_main(LV_PALETTE_RED), 0); // 设置颜色为红色
    lv_obj_align(my_box, LV_ALIGN_LEFT_MID, 0, 0);               // 靠左对齐

    /* 2. 创建并启动动画 */
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, my_box);             // 绑定刚才创建的红色方块
    lv_anim_set_values(&a, 0, 400);          // 设置 X 轴从 0 移动到 400
    lv_anim_set_time(&a, 5000);              // 动画时长 2 秒
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_x); // 动画执行函数：设置 X 坐标
    lv_anim_set_path_cb(&a, lv_anim_path_linear); // 线性运动
    lv_anim_set_playback_time(&a, 2000);     // 往返运动：回来也用 2 秒
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); // 无限循环
    lv_anim_start(&a);                       // 启动！


}

/* --- 配置区域 --- */
#define SCREEN_WIDTH    960     // 屏幕宽度
#define SCREEN_HEIGHT   240     // 屏幕高度
#define BOX_SIZE        40     // 每个小方块的边长 (像素)
#define ANIM_RANGE      40      // 移动幅度 (向下浮动多少像素)
#define ANIM_TIME       1000    // 单程动画时间 (ms)
#define DELAY_STEP_X    50      // X轴方向每延迟一步增加的时间 (ms)
#define DELAY_STEP_Y    100     // Y轴方向每延迟一步增加的时间 (ms)
/**
 * 创建满屏错位移动的小方块
 */
void lv_demo_staggered_boxes(void)
{
    /* 计算行数和列数，确保铺满屏幕 */
    int cols = SCREEN_WIDTH / BOX_SIZE + 1;
    int rows = SCREEN_HEIGHT / BOX_SIZE + 1;

    /* 获取当前活动屏幕作为父对象 */
    lv_obj_t * parent = lv_scr_act();

    /* 为了性能，移除父对象的滚动条和默认样式 */
    lv_obj_remove_style_all(parent);
    lv_obj_set_style_bg_color(parent, lv_color_black(), 0); // 背景设为黑色

    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            
            /* --- 1. 创建方块对象 --- */
            lv_obj_t * box = lv_obj_create(parent);
            lv_obj_set_size(box, BOX_SIZE, BOX_SIZE);
            
            /* 绝对定位：根据行列号计算初始位置 */
            lv_coord_t start_x = x * BOX_SIZE;
            lv_coord_t start_y = y * BOX_SIZE;
            lv_obj_set_pos(box, start_x, start_y);

            /* --- 2. 设置样式 (为了好看，去掉边框和圆角，并根据位置生成渐变色) --- */
            /* 生成颜色：让颜色随着位置变化，形成彩虹墙效果 */
            /* 使用 HSV 颜色空间更容易生成平滑过渡的颜色 */
            // Hue(色相)根据 X 轴变化, Saturation(饱和度)根据 Y 轴变化
            uint8_t hue = (x * 255) / cols;
            uint8_t sat = 150 + (y * 100) / rows; 
            lv_color_t color = lv_color_hsv_to_rgb(hue, sat, 220);

            lv_obj_set_style_bg_color(box, color, 0);
            lv_obj_set_style_bg_opa(box, LV_OPA_COVER, 0); // 确保不透明
            lv_obj_set_style_border_width(box, 1, 0);      // 设置1像素边框方便看清边界
            lv_obj_set_style_border_color(box, lv_color_black(), 0);
            lv_obj_set_style_radius(box, 0, 0);            // 直角方块
            lv_obj_set_scrollbar_mode(box, LV_SCROLLBAR_MODE_OFF); // 关闭内部滚动条

            /* --- 3. 设置错位动画 (核心逻辑) --- */
            /* 计算延迟时间：这是错位效果的灵魂 */
            /* 延迟时间 = 列号 * X步进 + 行号 * Y步进 */
            uint32_t delay = (x * DELAY_STEP_X) + (y * DELAY_STEP_Y);

            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, box); // 绑定当前方块

            /* 设置动画值：在 Y 轴方向上，从当前位置向下移动 ANIM_RANGE 个像素 */
            lv_anim_set_values(&a, start_y, start_y + ANIM_RANGE);
            
            /* 设置执行回调函数：改变 Y 坐标 */
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);

            /* 设置时间参数 */
            lv_anim_set_time(&a, ANIM_TIME);          // 去程时间
            lv_anim_set_playback_time(&a, ANIM_TIME); // 回程时间 (实现往返运动)
            lv_anim_set_delay(&a, delay);             // 【关键】设置启动延迟
            
            /* 设置运动路径：使用 Ease In Out 让运动更顺滑自然 */
            lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
            
            /* 设置无限重复 */
            lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
            
            /* 启动动画 */
            lv_anim_start(&a);
        }
    }
}
__weak void GUI_Task(void *argument)
{
  /* USER CODE BEGIN GUI_Task */
    DMA2D_Mutex_Init();
    
    lv_init();
    lv_port_disp_init();
    
    lv_obj_t * btn = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn, 100, 50);
    
    // 2. 将按钮对齐到左上角 (逻辑坐标 0,0)
    lv_obj_align(btn, LV_ALIGN_TOP_LEFT, 0, 0); 
    
    // 3. 给按钮上色以便观察
    lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_GREEN), 0);

    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "TOP LEFT");
    lv_obj_center(label);
    

    lv_demo_staggered_boxes();
    lv_demo_staggered_boxes_ONE();
  /* Infinite loop */
  for(;;)
  {
     lv_timer_handler();
    osDelay(2);

  }
  /* USER CODE END GUI_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

