#include "HomePage.h"

/* HomePage.c */

/**
 * @brief 核心函数：根据内部数据结构同步所有 UI 部件
 * @note  只有在非编辑状态下才会强制覆盖
 */
void HomePage_Refresh_All_Data(void)
{
    // 1. 合法性检查：如果控件还没创建，直接返回，防止崩溃
    if (ui.HOME_PAGE_label_Vout == NULL || ui.HOME_PAGE_label_Iout == NULL) {
        return;
    }
    char buf[32];

    // 2. 刷新电压回读 (使用标准 set_text，不要用 _static)
        sprintf(buf, "%0.3f", PowerInfo.Read.volt_read);
        lv_label_set_text(ui.HOME_PAGE_label_Vout, buf);

        // 3. 刷新电流回读
        sprintf(buf, "%0.3f", PowerInfo.Read.curr_read);
        lv_label_set_text(ui.HOME_PAGE_label_Iout, buf);
}

void UI_Refresh_Task(void *argument) {
    for(;;) {
        // 1. 获取全局 LVGL 互斥锁（确保线程安全）           
        HomePage_Refresh_All_Data();
        // 4. 控制刷新率：回读值一般 100ms~200ms 刷一次，视觉最舒服
        osDelay(100); 
    }
}

/**
 * @brief 主页菜单图标触摸点击回调
 */
static void homepage_menu_icon_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    
    if(code == LV_EVENT_CLICKED) 
    {
        //printf("[Touch] Menu Icon Clicked -> Switching to Menu Page\n");        
        // 核心：直接调用页面切换函数，进入菜单页面
        // 这和按下物理 MENU 键的效果是一模一样的
        UI_Switch_Page(PAGE_MENU);
    }
}

void HomePage_Enter(void)
{
    lv_obj_clear_flag(ui.HOME_PAGE_cont_Set,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_PAGE_cont_menu,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_PAGE_cont_read_back_value,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_PAGE_cont_2,LV_OBJ_FLAG_HIDDEN);

    ui_led_start(ui.HOME_PAGE_led_1);
  
}
void HomePage_Exit(void)
{       
    lv_obj_add_flag(ui.HOME_PAGE_cont_Set,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_cont_menu,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_cont_read_back_value,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_cont_2,LV_OBJ_FLAG_HIDDEN);
    // 手动停止该对象的所有动画，节省系统开销
   // lv_anim_del(ui.HOME_PAGE_led_1, NULL);
  
}

// @brief 辅助函数：刷新 UI 显示
static char stringSet[64] = {0};
void Set_RefreshUI(lv_obj_t *obj, uint8_t *editIndex, const char *dispfmt, double value)
{
    if(obj == NULL) {
        return ;
    }
    //
    sprintf(stringSet, dispfmt, value);
    if(editIndex != NULL) {
        label_setSelNum(obj, *editIndex, stringSet);
    } else {
    }
    lv_label_set_text(obj, stringSet);
    //
    if(editIndex == NULL) 
        {
          lv_obj_add_state(obj, LV_STATE_DEFAULT);
        lv_label_set_text_sel_start(obj, LV_LABEL_TEXT_SELECTION_OFF);
        lv_label_set_text_sel_end(obj, LV_LABEL_TEXT_SELECTION_OFF);
    } else {
        lv_obj_add_state(obj, LV_STATE_FOCUSED);
    }
}

/**
 * @brief 主页数字区域触摸点击回调
 */
static void homepage_touch_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    
    // 关键：获取触发该事件的输入设备
    lv_indev_t * indev = lv_event_get_indev(e);

    if(code == LV_EVENT_CLICKED) 
    {
        /* 只有当 indev != NULL 时，说明这是物理触摸产生真实事件。
           如果 indev == NULL，说明是 Tree_UI_Sel_Enter 内部手动模拟的事件，直接跳过，防止递归。
        */
        if(indev == NULL) return; 

        // 1. 如果点击的是电压设置区域
        if(obj == ui.HOME_PAGE_edit_Vset) {
            if(tree_VSet != NULL) {               
                Tree_UI_Sel_Enter(tree_VSet, 0);
            }
        }
        // 2. 电流区域逻辑同理
        else if(obj == ui.HOME_PAGE_edit_Iset_pos) {
            if(tree_ISet != NULL) {              
                Tree_UI_Sel_Enter(tree_ISet, 0);
            }
        }
        else if(obj == ui.HOME_PAGE_edit_Iset_neg) {
            if(tree_ISet_neg != NULL) {             
                Tree_UI_Sel_Enter(tree_ISet_neg, 0);
            }
        }
    }
}


void HomePage_GroupCreate(void)
{
    
    {//初始化
    /* 1. 先创建屏幕对象 */
    setup_scr_HOME_PAGE(&ui);    
    /* 2. 调整父级关系 */
    lv_obj_set_parent(ui.HOME_PAGE_cont_Set, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_PAGE_cont_menu, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_PAGE_cont_read_back_value, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_PAGE_cont_2, ui.Back_cont_back);
    /* 进入页面逻辑 */
    
    } 

    // --- 【新增：触摸联动代码】 ---
    
    // 给电压 Label 开启点击并绑定
    lv_obj_add_flag(ui.HOME_PAGE_edit_Vset, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui.HOME_PAGE_edit_Vset, homepage_touch_handler, LV_EVENT_CLICKED, NULL);

    // 给电流 Label 开启点击并绑定 (实现触摸版 F1)
    lv_obj_add_flag(ui.HOME_PAGE_edit_Iset_pos, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui.HOME_PAGE_edit_Iset_pos, homepage_touch_handler, LV_EVENT_CLICKED, NULL);    

    // 给电流 Label 开启点击并绑定 (实现触摸版 F1)
    lv_obj_add_flag(ui.HOME_PAGE_edit_Iset_neg, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui.HOME_PAGE_edit_Iset_neg, homepage_touch_handler, LV_EVENT_CLICKED, NULL);    
      
    // 2. 处理按钮：绑定进入菜单的逻辑
    if(ui.HOME_PAGE_btn_Menu != NULL) 
    {
        // 按钮默认就是 CLICKABLE 的，不需要额外 add_flag
        
        // 绑定回调函数（复用你之前的处理函数）
        lv_obj_add_event_cb(ui.HOME_PAGE_btn_Menu, homepage_menu_icon_handler, LV_EVENT_CLICKED, NULL);
        
        // 如果你的按钮是全透明盖在上面的，确保它没有被 Hidden 掉
        lv_obj_clear_flag(ui.HOME_PAGE_btn_Menu, LV_OBJ_FLAG_HIDDEN);
        
        // 提高扩展点击区域（可选）
        lv_obj_set_ext_click_area(ui.HOME_PAGE_btn_Menu, 10);
    }
    
    
    
    
    
    //初始隐藏
    
    lv_obj_add_flag(ui.HOME_PAGE_label_CV, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_label_CC, LV_OBJ_FLAG_HIDDEN);  

    lv_obj_add_flag(ui.HOME_PAGE_img_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_img_3, LV_OBJ_FLAG_HIDDEN);     
    lv_obj_add_flag(ui.HOME_PAGE_img_5, LV_OBJ_FLAG_HIDDEN);  
    
    //初始状态
    IF_Power_Set_OutOnOff(PowerInfo.outSet.onoff);
    
    HomePage_Enter();

}


