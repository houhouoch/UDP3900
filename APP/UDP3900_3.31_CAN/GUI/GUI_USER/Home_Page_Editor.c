#include "Home_Page_Editor.h"
#include "Menu_Protect_Editor.h" // 引用之前的 Protect_Item_Cfg_t 和 core 逻辑
#include <math.h>
#include "./BSP/LED/led.h"
/* ----------------------------------------------------------------
    1. 步进数组与宏定义 (主页专用)
   ---------------------------------------------------------------- */
const double V_step[]     = {0.001, 0.01, 0.1, 1.0, 10.0};
const double A_step[]     = {0.001, 0.01, 0.1, 1.0, 10.0};
const double A_neg_step[] = {0.001, 0.01, 0.1, 1.0, 10.0};

#define VOL_SET_FORM        "%0.3fV"
#define AMP_SET_FORM        "%0.3fA"
#define AMP_neg_SET_FORM    "-%0.3fA"
#define DEFAULT_HOME_INDEX  3  // 默认指向个位

/* ----------------------------------------------------------------
    2. 主页通用逻辑核心 (基于 volSet_handler 逻辑重写)
   ---------------------------------------------------------------- */
/**
 * @brief 主页项逻辑处理器
 * @param index_ptr 指向静态位选索引
 * @param cfg 配置信息
 * @param is_neg 是否为负值调节
 */
static void home_page_item_logic_core(lv_event_t * e, uint8_t * index_ptr, const Protect_Item_Cfg_t * cfg, bool is_neg)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    
    // 获取当前物理值
    double current_val = cfg->get_val();

    switch(code)
    {
        case LV_EVENT_FOCUSED: {
            *index_ptr = cfg->init_index; // 聚焦时重置位选位置
                       
            //LED亮
            Panel_LED_Set(cfg->led_id, 1);//亮灯
            
            // 刷新 UI：如果是负数调节，传 fabs 绝对值，由 FMT 控制符号
            double disp_val = is_neg ? fabs(current_val) : current_val;
            Set_RefreshUI(obj, index_ptr, cfg->fmt, disp_val);
            break;
        }

        case LV_EVENT_KEY: {
            lv_key_t key = lv_event_get_key(e);
            switch(key) {
                case LV_KEY_UP:
                    current_val += cfg->steps[*index_ptr];
                    break;
                case LV_KEY_DOWN:
                    current_val -= cfg->steps[*index_ptr];
                    break;
                case LV_KEY_LEFT:
                    if(*index_ptr < cfg->max_index) (*index_ptr)++;
                    break;
                case LV_KEY_RIGHT:
                    if(*index_ptr > 0) (*index_ptr)--;
                    break;
                case LV_KEY_ENTER:
                case LV_KEY_ESC:
                    Tree_UI_Sel_Exit(); // 退出编辑模式
                    return;
            }

            // 负值特殊限制：如果是负向调节，确保数值不跨越到正数
            if(is_neg && current_val > 0.0) current_val = 0.0;
            // 正值基础限制：如果是正向调节，确保不低于 0 (可选)
            if(!is_neg && current_val < 0.0) current_val = 0.0;
            
            // 值域限幅
            if(current_val < cfg->min_val) current_val = cfg->min_val;
            if(current_val > cfg->max_val) current_val = cfg->max_val;

            // 写入硬件/底层
            cfg->set_val(current_val);
            
            // 刷新显示
            double disp_val = is_neg ? fabs(current_val) : current_val;
            Set_RefreshUI(obj, index_ptr, cfg->fmt, disp_val);
            break;
        }

        case LV_EVENT_DEFOCUSED: {
            // 失去焦点，隐藏光标刷新
            Panel_LED_Set(cfg->led_id, 0); // 灭灯
            double disp_val = is_neg ? fabs(current_val) : current_val;
            Set_RefreshUI(obj, NULL, cfg->fmt, disp_val);
            break;
        }
        default: break;
    }
}

/* ----------------------------------------------------------------
    3. 底层接口适配器 (Adapters)
   ---------------------------------------------------------------- */
static double _get_h_v(void) { return IF_Power_Get_OutVolt(); }
static void   _set_h_v(double v) { IF_Power_Set_OutVolt(v); }

static double _get_h_i(void) { return IF_Power_Get_OutCurr(); }
static void   _set_h_i(double i) { IF_Power_Set_OutCurr(i); }

static double _get_h_i_neg(void) { return IF_Power_Get_OutCurr_Neg(); }
static void   _set_h_i_neg(double i) { IF_Power_Set_OutCurr_Neg(i); }
/* ----------------------------------------------------------------
    4. 配置对象定义 (Home Page 专用 - 格式优化版)
   ---------------------------------------------------------------- */
/* --- 主页电压配置 --- */
const Protect_Item_Cfg_t CFG_H_VOLT = {
    .fmt        = VOL_SET_FORM,
    .steps      = V_step,
    .max_index  = 4,
    .init_index = 3,
    .scale      = 1.0,
    .min_val    = 0.0,
    .max_val    = 60.0,
    .get_val    = _get_h_v,
    .set_val    = _set_h_v,
    .led_id     = LED_V_SET, // 绑定电压灯
};

/* --- 主页正向电流配置 --- */
const Protect_Item_Cfg_t CFG_H_CURR = {
    .fmt        = AMP_SET_FORM,
    .steps      = A_step,
    .max_index  = 4,
    .init_index = 3,
    .scale      = 1.0,
    .min_val    = 0.0,
    .max_val    = 10.0,
    .get_val    = _get_h_i,
    .set_val    = _set_h_i,
    .led_id     = LED_I_SET, // 绑定电流灯
};

/* --- 主页负向电流配置 --- */
const Protect_Item_Cfg_t CFG_H_CURR_NEG = {
    .fmt        = AMP_neg_SET_FORM,
    .steps      = A_neg_step,
    .max_index  = 4,
    .init_index = 3,
    .scale      = 1.0,
    .min_val    = -10.0,
    .max_val    = 0.0,
    .get_val    = _get_h_i_neg,
    .set_val    = _set_h_i_neg,
    .led_id     = LED_I_SET, 
};

/* ----------------------------------------------------------------
    5. Handler 映射
   ---------------------------------------------------------------- */
void volSet_handler(lv_event_t * e) {
    static uint8_t idx_v = DEFAULT_HOME_INDEX;
    home_page_item_logic_core(e, &idx_v, &CFG_H_VOLT, false);
}

void ampSet_handler(lv_event_t * e) {
    static uint8_t idx_a = DEFAULT_HOME_INDEX;
    home_page_item_logic_core(e, &idx_a, &CFG_H_CURR, false);
}

void ampSet_handler_neg(lv_event_t * e) {
    static uint8_t idx_an = DEFAULT_HOME_INDEX;
    home_page_item_logic_core(e, &idx_an, &CFG_H_CURR_NEG, true);
}


/* ----------------------------------------------------------------
    6. Home Page UI 全量刷新 (上电调用)
   ---------------------------------------------------------------- */
void Home_Page_UI_Full_Sync(void) {
    // 刷新主页电压显示 (假设 ui 成员如下，请根据实际修改)
    Set_RefreshUI(ui.HOME_PAGE_edit_Vset, NULL, VOL_SET_FORM, IF_Power_Get_OutVolt());
    
    // 刷新主页电流显示
    Set_RefreshUI(ui.HOME_PAGE_edit_Iset_pos, NULL, AMP_SET_FORM, IF_Power_Get_OutCurr());
    
    // 刷新主页负向电流显示
    Set_RefreshUI(ui.HOME_PAGE_edit_Iset_neg, NULL, AMP_neg_SET_FORM, fabs(IF_Power_Get_OutCurr_Neg()));
}
