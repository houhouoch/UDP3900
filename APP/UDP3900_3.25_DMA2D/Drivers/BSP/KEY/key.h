#ifndef _BUTTON_DEVICE_H_
#define _BUTTON_DEVICE_H_

#include "main.h"
enum {
    BUTTON_F1 = 3,
    BUTTON_F2 = 1,
    BUTTON_F3 = 2,
    BUTTON_F4 = 0,
    BUTTON_F5 = 5,
    BUTTON_F6 = 30,

    BUTTON_LEFT = 18,
    BUTTON_RIGHT = 13,

    BUTTON_ESC = 27,
    BUTTON_ENCODER = 35,

    BUTTON_LOCK = 31,
    BUTTON_MENU = 6,






    #ifdef HAOYI_VER
    BUTTON_ENTER = 28,
    BUTTON_OUTPUT = 8,
    BUTTON_WAVE = 33,
    BUTTON_LIST = 7,
    BUTTON_DELAYER = 32,
    #else
    BUTTON_OUTPUT = 28,
    BUTTON_PRESET = 33,

    BUTTON_HOME = 7,
    BUTTON_LIST = 32,
    #endif


    BUTTON_1 = 20,
    BUTTON_2 = 21,
    BUTTON_3 = 22,
    BUTTON_4 = 15,
    BUTTON_5 = 16,
    BUTTON_6 = 17,
    BUTTON_7 = 10,
    BUTTON_8 = 11,
    BUTTON_9 = 12,

    BUTTON_DOT = 25,
    BUTTON_0 = 26,
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

#endif
