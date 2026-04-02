#ifndef _HOMEPAGE_H_
#define _HOMEPAGE_H_
#include "lvgl.h"
#include "Gui_Task.h"
#include "HomePage_LED.h"
#include "power_interface.h"
#include "Home_Page_Editor.h"


void HomePage_Refresh_All_Data(void);

#define NumberInput_Process(maxLen, SetFunction, cfg_ptr, is_neg) \
    static uint8_t inputIdx = 0;                                \
    static char inputBuf[32] = {0};                             \
    static uint8_t numInput_flag = 0;                           \
                                                                \
    lv_event_code_t _code = lv_event_get_code(e);               \
    lv_obj_t * _obj = lv_event_get_target(e);                   \
                                                                \
    if(_code == LV_EVENT_KEY) {                                 \
        lv_key_t key = lv_event_get_key(e);                     \
                                                                \
        /* 1. 处理数字和小数点输入 */                                \
        if((key == '.') || (('0' <= key) && (key <= '9'))) {    \
            if(numInput_flag == 0) {                            \
                inputIdx = 0;                                   \
                memset(inputBuf, 0, sizeof(inputBuf));          \
                numInput_flag = 1;                              \
            }                                                   \
            if(inputIdx < maxLen) {                             \
                inputBuf[inputIdx++] = (char)key;               \
                inputBuf[inputIdx] = '\0';                      \
                /* 刷新显示 */                                    \
                if(is_neg) {                                    \
                    char tmp[34];                               \
                    sprintf(tmp, "-%s", inputBuf);              \
                    lv_label_set_text(_obj, tmp);               \
                } else {                                        \
                    lv_label_set_text(_obj, inputBuf);          \
                }                                               \
                lv_label_set_text_sel_start(_obj, LV_LABEL_TEXT_SELECTION_OFF); \
            }                                                   \
            return;                                             \
        }                                                       \
                                                                \
        /* 2. 在打字模式下的功能按键处理 */                            \
        if(numInput_flag == 1) {                                \
            /* --- 新增：左键删除 (退格) 逻辑 --- */                 \
            if(key == LV_KEY_LEFT) {                            \
                if(inputIdx > 0) {                              \
                    inputBuf[--inputIdx] = '\0';                \
                    /* 重新刷新显示 */                             \
                    if(is_neg) {                                \
                        char tmp[34];                           \
                        sprintf(tmp, "-%s", inputBuf);          \
                        lv_label_set_text(_obj, tmp);           \
                    } else {                                    \
                        lv_label_set_text(_obj, inputBuf);      \
                    }                                           \
                }                                               \
                /* 如果删光了，可以选择显示 0 或者保持空，建议保持 numInput_flag=1 */ \
                if(inputIdx == 0) {                             \
                    lv_label_set_text(_obj, is_neg ? "-" : "0");\
                }                                               \
                return;                                         \
            }                                                   \
                                                                \
            /* 3. 处理 Enter 确认键 */                            \
            if(key == LV_KEY_ENTER || key == LV_KEY_ENCODER) {  \
                double val = atof(inputBuf);                    \
                if(is_neg) val = -fabs(val);                    \
                                                                \
                if(val > cfg_ptr->max_val) val = cfg_ptr->max_val; \
                if(val < cfg_ptr->min_val) val = cfg_ptr->min_val; \
                                                                \
                SetFunction(val);                               \
                numInput_flag = 0;                              \
                inputIdx = 0;                                   \
                memset(inputBuf, 0, sizeof(inputBuf));          \
                Set_RefreshUI(_obj, &idx, cfg_ptr->fmt, cfg_ptr->get_val()); \
                return;                                         \
            }                                                   \
                                                                \
            /* 4. 如果在打字时按了 UP/DOWN/RIGHT，视为取消/退出打字 */ \
            if(key == LV_KEY_UP || key == LV_KEY_DOWN ) { \
                numInput_flag = 0;                              \
                Set_RefreshUI(_obj, &idx, cfg_ptr->fmt, cfg_ptr->get_val()); \
                return;                                         \
            }                                                   \
        }                                                       \
    }                              \

void volSet_handler(lv_event_t * e);
void ampSet_handler(lv_event_t * e);
void ampSet_handler_neg(lv_event_t * e);
void HomePage_Enter(void);
void HomePage_Exit(void);
void HomePage_GroupCreate(void);
void Set_RefreshUI(lv_obj_t *obj, uint8_t *editIndex, const char *dispfmt, double value);
#endif
