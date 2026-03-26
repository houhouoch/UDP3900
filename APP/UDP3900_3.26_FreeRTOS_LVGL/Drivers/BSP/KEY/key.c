#include "./BSP/KEY/key.h"
#include "stdio.h"
#include "string.h"
#include "./BSP/GPIO_Device.h"
#include "main.h"
static const GPIO_Def Key_X[] = {
    {KEY_X1_GPIO_Port, KEY_X1_Pin},
    {KEY_X2_GPIO_Port, KEY_X2_Pin},
    {KEY_X3_GPIO_Port, KEY_X3_Pin},
    {KEY_X4_GPIO_Port, KEY_X4_Pin},
    {KEY_X5_GPIO_Port, KEY_X5_Pin},
    {KEY_X6_GPIO_Port, KEY_X6_Pin},
    {KEY_X7_GPIO_Port, KEY_X7_Pin},
};

static const GPIO_Def Key_Y[] = {
    {KEY_Y1_GPIO_Port, KEY_Y1_Pin},
    {KEY_Y1_GPIO_Port, KEY_Y2_Pin},
    {KEY_Y1_GPIO_Port, KEY_Y3_Pin},
    {KEY_Y1_GPIO_Port, KEY_Y4_Pin},
};


static void delay(void)
{
    uint16_t i;
    for(i = 0; i < 50; i++);
}
#define ROW_COUNT    (sizeof(Key_X) / sizeof(Key_X[0]))   /* 7 */
#define COL_COUNT    (sizeof(Key_Y) / sizeof(Key_Y[0]))   /* 4 */
#define NO_KEY       0xFF

uint8_t matrixButton_Scan(void)
{
    uint8_t key = 0xff;
    static uint32_t last_press_tick = 0;
    const uint32_t debounce_ms = 20;   /* 消抖时间 20ms */
     
    if ((HAL_GetTick() - last_press_tick) < debounce_ms)
        return NO_KEY;
    
   if(HAL_GPIO_ReadPin(Encoder_Key_GPIO_Port, Encoder_Key_Pin) != 0) {
        key = COL_COUNT * ROW_COUNT;
    }   
    for (uint8_t row = 0; row < ROW_COUNT; row++)
    {
        /* 1. 当前行强驱低 */
        gpio_set(Key_X[row], 0);
        delay();
        /* 2. 读取所有列 */
        for (uint8_t col = 0; col < COL_COUNT; col++)
        {
            if (gpio_get(Key_Y[col]) == 0)   /* 检测到按下 */
            {
                /* 立即恢复当前行高电平 */
                gpio_set(Key_X[row], 1);              
                key =(row * COL_COUNT + col );   /* 返回0~34*/             
            }
        }

        /* 3. 恢复当前行高电平（未检测到按键时也要恢复） */
        gpio_set(Key_X[row], 1); 
            if(key != 0xff) {
            break;
            }
        delay();
    }

    return key;   /* 无按键 */
}


//检测按键被按下
uint8_t matrixButton_CalibModeCheck(uint8_t button)
{
    uint8_t flag = 0;
    uint8_t buttonCnt = 0;
    for(uint8_t i = 0; i < 10; ++i) {
        if(matrixButton_Scan() == button) {
            if(buttonCnt < 3) {
                buttonCnt++;
            } else {
                flag = 1;
                break;
            }
        }
        HAL_Delay(10);
    }
    return flag;
}



#define LONGPPRESS_TIME 1500
#define SHORTPRESS_TIME 50
//长按键自动跳出
#define BUTTON_LONGPRESS_AUTO_RETURN 1

static uint32_t timeDiff(uint16_t t0, uint16_t t1)
{
    uint32_t time = 0;
    if(t0 > t1) {
        time = 65536 + t1 - t0;
    } else {
        time = t1 - t0;
    }
    return time;
}


uint8_t keyScan(uint8_t *pkey)
{
    if(pkey == NULL)
    { return KEY_STATE_RELEASED; }
    //返回值(按键状态)
    uint8_t keystate = KEY_DEFAULT;
    *pkey = 0xff;
    //开始矩阵扫描
    uint8_t keyValue = matrixButton_Scan();
    static uint8_t lastKey = 0xff;
    static uint8_t triggerFlag = 0;
    static uint8_t holdSendFlag = 0;
    //计算时间差
    static uint16_t t0 = 0;
    uint16_t t1 = HAL_GetTick();
    uint32_t count = timeDiff(t0, t1);
    *pkey = 0xff;
    {
        //按键状态发生变化
        if(lastKey != keyValue)
        {
            //按下记录时间
            if(lastKey == 0xff) {
                triggerFlag = 0;
                holdSendFlag = 0;
                //锚定时间
                t0 = HAL_GetTick();
            }
            if((lastKey != 0xff) && (keyValue == 0xff))
            {
                if(triggerFlag == 0)
                {
                    //释放计算时间
                    if((count  < LONGPPRESS_TIME) && (count  > SHORTPRESS_TIME))
                    {
                        //短按
                        triggerFlag = 1;
                        printf("ShortPress %d \r\n", lastKey);
                        *pkey = lastKey;
                        keystate = KEY_STATE_CLICKED;
                    } else
                        if(count > LONGPPRESS_TIME) {
                            //长按
                            triggerFlag = 1;
                            printf("LongPress %d \r\n", lastKey);
                            *pkey = lastKey;
                            keystate = KEY_STATE_LONGGP;
                        }
                }
            }
            lastKey = keyValue;
        } else
            if(keyValue != 0xff)     //按键已被按下
            {
                if(triggerFlag == 0)
                {
                    //已按下,超过长按时间自动跳出
                    #if (BUTTON_LONGPRESS_AUTO_RETURN != 0)
                    if(count >= LONGPPRESS_TIME) {
                        triggerFlag = 1;
                        printf("LongPress H %d\r\n", lastKey);
                        *pkey = lastKey;
                        keystate = KEY_STATE_LONGGP;
                    }
                    #endif
                }
                if(holdSendFlag == 0)
                {
                    if(count > (SHORTPRESS_TIME + 1)) {
                        *pkey = lastKey;
                        keystate = KEY_STATE_HOLD;
                        holdSendFlag = 1;
                    }
                }
            }
    }
    return keystate;
}
