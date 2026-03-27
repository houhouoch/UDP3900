#include "Gui_Task.h"

lv_ui ui;

/* 定义任务句柄，用于后续管理任务（比如删除或挂起） */




static void __Boot_Display_Logo(void)
{
    //  声明和获取图片资源 
    LV_IMG_DECLARE(_Logo_alpha_569x159);    
    LV_IMG_DECLARE(_HY_LOGO_alpha_639x178);  
    //  定义指针并指向想要的图片描述符
   const lv_img_dsc_t *imgSrc = &_Logo_alpha_569x159;  // 切换Logo
    //  设置图片源
   lv_img_set_src(ui.Back_img_Logo, imgSrc);
    // 重置 Image 对象的大小为“自适应内容”
    lv_obj_set_size(ui.Back_img_Logo, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // 5. 对齐方式
    lv_obj_align(ui.Back_img_Logo, LV_ALIGN_CENTER, 0, 0);
    osDelay(200);
    // 6. 循环渐亮背光
    for(uint8_t i = 0; i <= 100; i += 1)
    {
        osDelay(20);  
        lv_task_handler();        
        //打开背光
     __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, i * 2);       
    } 
    
  
//    lv_obj_del(ui.Back_img_Logo); // 彻底删除对象释放内存
//    ui.Back_img_Logo = NULL;

}


/*
 * @brief       static void __Load_Page(void)
 * @details     加载UI页面
 */
static void __Load_Page(void)
{
    // 1. 创建背景和基础容器
    setup_scr_Back(&ui);
    
    // 2. 立即加载背景屏幕
    lv_scr_load(ui.Back); 

    // 3. 执行开机动画和背光渐亮
    __Boot_Display_Logo();

    // 4. 初始化所有页面的 Group 和 Object (预创建)
    // 基础页面
    HomePage_GroupCreate();
//    Home_Menu_GroupCreate();
//    
//    // 菜单子页面 (全员到齐)
//    Menu_Config_GroupCreate();
//    Menu_Protect_GroupCreate();
//    Menu_Measure_GroupCreate();
//    Menu_Trigger_GroupCreate();
//    Menu_Recall_GroupCreate();
//    Menu_Save_GroupCreate();
//    Menu_Meter_GroupCreate();
//    Menu_Recorder_GroupCreate();
//    
//    
//    // 批量初始化 13 个新页面
//    Menu_Function_GroupCreate();
//    Menu_Delays_GroupCreate();
//    Menu_Coupling_GroupCreate();
//    Menu_Group_GroupCreate();
//    Menu_General_GroupCreate();
//    Menu_Digital_IO_GroupCreate();
//    Menu_Preference_GroupCreate();
//    Menu_Log_GroupCreate();
//    Menu_Admin_GroupCreate();
//    Menu_Communication_GroupCreate();
//    Menu_Info_GroupCreate();
//    Menu_Energy_GroupCreate();
//    Menu_Date_GroupCreate();
//    // 5. 强制刷新
//    lv_obj_invalidate(ui.screen_cont_1); 
    


}


//GUI任务--用于开始初始化其他任务&开启图像
void GUI_Task(void *argument)
{
  /* USER CODE BEGIN GUI_Task */    
    // 确保你的 DMA2D Mutex 已经创建完毕
    DMA2D_Mutex_Init();
    //LED任务

    //LVGL初始化
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    
    //开机背景
    __Load_Page();
    //加载显示树
   // UI_Tree_Init();

//    lv_obj_remove_event_cb(ui.Back_cont_back, btnTree_event_handler);
//    lv_obj_add_event_cb(ui.Back_cont_back, btnTree_event_handler, LV_EVENT_ALL, NULL);
    
    for(;;) {
       lv_timer_handler();
        osDelay(5);

    }
  /* Infinite loop */

  /* USER CODE END GUI_Task */
}


