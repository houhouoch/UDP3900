#ifndef _BUTTON_DEVICE_H_
#define _BUTTON_DEVICE_H_

#include "main.h"
// button.h 中修正枚举
enum {
    // Row 0 (X1)
    BUTTON_3 = 0,   BUTTON_6 = 1,   BUTTON_9 = 2,    BUTTON_ESC= 3,
    // Row 1 (X2)
    BUTTON_2 = 4,   BUTTON_5 = 5,   BUTTON_8 = 6,   BUTTON_0 = 7,
    // Row 2 (X3)
    BUTTON_1 = 8,   BUTTON_4 = 9,   BUTTON_7 = 10,  BUTTON_DOT = 11,
    // Row 3 (X4)
    BUTTON_I_SET = 12, BUTTON_R_SET = 13, BUTTON_MENU = 14, BUTTON_RIGHT = 15,
    // Row 4 (X5)
    BUTTON_V_SET = 16, BUTTON_P_SET = 17, BUTTON_HOME = 18, BUTTON_LEFT = 19,
    // Row 5 (X6)
    BUTTON_LOCK = 20, BUTTON_PROTECT = 21, BUTTON_OUTPUT = 22,
    // Row 6 (X7)
    BUTTON_SOURCE = 24, BUTTON_LOAD = 25,
    
    BUTTON_ENTER = 28 // 编码器按键
};


enum {
    KEY_DEFAULT = 0,
    KEY_STATE_RELEASED,                 //按键释放
    KEY_STATE_HOLD,                     //按键保持
    KEY_STATE_CLICKED,                  //按键点击
    KEY_STATE_LONGGP,                   //按键长按
};


//检测按键被按下
uint8_t matrixButton_CalibModeCheck(uint8_t button);



uint8_t keyScan(uint8_t *returnKey);
lv_key_t Button_toKey(uint8_t buttonNum, uint8_t flag);
#endif





