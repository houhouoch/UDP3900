/**
 ****************************************************************************************************
 * @file        led.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2023-06-12
 * @brief       LED驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 * 
 * 实验平台:正点原子 北极星 H750开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 * 
 ****************************************************************************************************
 */

#ifndef __LED_H
#define __LED_H

#include "main.h"

/* LED 索引定义 (对应 74HC573 的引脚顺序) */
typedef enum {
    LED_LOAD    = 0, // 1Q -> KEY_X1
    LED_SOURCE  = 1, // 2Q -> KEY_X2
    LED_ON_OFF  = 2, // 3Q -> KEY_X3
    LED_V_SET   = 3, // 4Q -> KEY_X4
    LED_P_SET   = 4, // 5Q -> KEY_X5
    LED_I_SET   = 5, // 6Q -> KEY_X6
    LED_R_SET   = 6, // 7Q -> KEY_X7
    LED_ALL     = 7  // 特殊用途
} Panel_LED_t;

/* 锁存器控制引脚 (根据你的实际引脚修改) */
#define LATCH_LE_PORT    GPIOC
#define LATCH_LE_PIN     GPIO_PIN_0  /* 573_LE1 引脚 */

/* 函数声明 */
void Panel_LED_Init(void);
void Panel_LED_Set(Panel_LED_t led, uint8_t state);
void Panel_LED_AllOff(void);

/* 用户快捷调用接口 */
#define V_SET_LED(s)   Panel_LED_Set(LED_V_SET, s)
#define P_SET_LED(s)   Panel_LED_Set(LED_P_SET, s)
#define I_SET_LED(s)   Panel_LED_Set(LED_I_SET, s)
#define R_SET_LED(s)   Panel_LED_Set(LED_R_SET, s)
#define ON_OFF_LED(s)  Panel_LED_Set(LED_ON_OFF, s)
#define SOURCE_LED(s)  Panel_LED_Set(LED_SOURCE, s)
#define LOAD_LED(s)    Panel_LED_Set(LED_LOAD, s)

/* 引脚定义 */
#define LED_GPIO_PORT          GPIOC
#define LED_GPIO_PIN           GPIO_PIN_13
#define LED_GPIO_CLK_ENABLE()  do { __HAL_RCC_GPIOC_CLK_ENABLE(); } while (0)


/* IO操作 */
#define LED(x)                 do { (x) ?                                                              \
                                    HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_SET):     \
                                    HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_RESET);   \
                                } while (0)

                                
#define LED_TOGGLE()           do { HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN); } while (0)


/* 函数声明 */
void led_init(void);    /* 初始化LED */

#endif
