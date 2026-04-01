#ifndef MENU_PROTECT_EDITOR_H
#define MENU_PROTECT_EDITOR_H

#include "lvgl.h"
#include "BtnTree.h"
#include "Gui_Task.h"
#include "power_interface.h"
#include "./BSP/LED/led.h"
/**
 * @brief 保护项参数配置结构体
 */
typedef struct {
    const char * fmt;           // 格式化字符串, 如 "%0.3fV"
    const double * steps;       // 指向对应的步进数组 (Prot_V_step 等)
    uint8_t max_index;          // 索引最大值 (左移边界)
    uint8_t init_index;         // 进入编辑模式时的初始位选位置
    double scale;               // 缩放比例 (底层ms转UI秒则为1000.0, 电压为1.0)
    double min_val;    // 最小值限制
    double max_val;    // 最大值限制
    // 函数指针封装底层接口
    double (*get_val)(void);    
    void (*set_val)(double); 
    Panel_LED_t led_id;
} Protect_Item_Cfg_t;

/* --- 核心 UI 工具函数 --- */
void label_setSelNum(lv_obj_t *label, uint16_t numpos, const char *text);

/* --- 节点三：调节处理器 (Handlers) --- */

// OVP (过压)
void prot_ovp_v_set_handler(lv_event_t * e);
void prot_ovp_delay_set_handler(lv_event_t * e);

// OCP (过流)
void prot_ocp_delay_set_handler(lv_event_t * e);
void prot_ocp_pos_i_set_handler(lv_event_t * e);
void prot_ocp_neg_i_set_handler(lv_event_t * e);

// OPP (过功率)
void prot_opp_pos_p_set_handler(lv_event_t * e);
void prot_opp_neg_p_set_handler(lv_event_t * e);
void prot_opp_delay_set_handler(lv_event_t * e);

// UVP (欠压)
void prot_uvp_v_set_handler(lv_event_t * e);
void prot_uvp_warm_set_handler(lv_event_t * e);
void prot_uvp_delay_set_handler(lv_event_t * e);

// UCP (欠流)
void prot_ucp_pos_i_set_handler(lv_event_t * e);
void prot_ucp_neg_i_set_handler(lv_event_t * e); 
void prot_ucp_warm_set_handler(lv_event_t * e);
void prot_ucp_delay_set_handler(lv_event_t * e);
// Foldback (折返)
void prot_fold_delay_set_handler(lv_event_t * e);
void prot_fold_mode_handler(lv_event_t * e);


void Menu_Protect_UI_Full_Sync(void);

#endif /* MENU_PROTECT_EDITOR_H */
