#include "./BSP/KEY/key.h"
#include "stdio.h"
#include "string.h"
#include "./BSP/GPIO_Device.h"
#include "main.h"
#include "lvgl.h"

//按键映射
typedef struct {
    uint8_t buttonNum;
    uint8_t key_short;
    uint8_t key_long;
    uint8_t key_hold;
} Button_KeyTable_Def;

static const Button_KeyTable_Def Btn_KeyTable[] = {
    /* 1. 数字键盘区 (对应标准的 ASCII 字符) */
    {BUTTON_0,      '0',                '0',                LV_KEY_DEFAULT},
    {BUTTON_1,      '1',                '1',                LV_KEY_DEFAULT},
    {BUTTON_2,      '2',                '2',                LV_KEY_DEFAULT},
    {BUTTON_3,      '3',                '3',                LV_KEY_DEFAULT},
    {BUTTON_4,      '4',                '4',                LV_KEY_DEFAULT},
    {BUTTON_5,      '5',                '5',                LV_KEY_DEFAULT},
    {BUTTON_6,      '6',                '6',                LV_KEY_DEFAULT},
    {BUTTON_7,      '7',                '7',                LV_KEY_DEFAULT},
    {BUTTON_8,      '8',                '8',                LV_KEY_DEFAULT},
    {BUTTON_9,      '9',                '9',                LV_KEY_DEFAULT},
    {BUTTON_DOT,    '.',                '.',                LV_KEY_DEFAULT},

    /* 2. 核心设置区 (V/I/P/R 参数快捷键) */
    {BUTTON_V_SET,  LV_KEY_V_SET,       LV_KEY_V_SET,       LV_KEY_DEFAULT},
    {BUTTON_I_SET,  LV_KEY_I_SET,       LV_KEY_I_SET,       LV_KEY_DEFAULT},
    {BUTTON_P_SET,  LV_KEY_P_SET,       LV_KEY_P_SET,       LV_KEY_DEFAULT},
    {BUTTON_R_SET,  LV_KEY_R_SET,       LV_KEY_R_SET,       LV_KEY_DEFAULT},
    {BUTTON_SOURCE, LV_KEY_Source_SET,  LV_KEY_Source_SET,  LV_KEY_DEFAULT},
    {BUTTON_LOAD,   LV_KEY_Load_SET,    LV_KEY_Load_SET,    LV_KEY_DEFAULT},
    {BUTTON_PROTECT,LV_KEY_Protect_SET, LV_KEY_Protect_SET, LV_KEY_DEFAULT},

    /* 3. 导航与交互区 (菜单、返回、确认、上下左右) */
    {BUTTON_ENTER,  LV_KEY_ENTER,       LV_KEY_ENTER_LONGP, LV_KEY_DEFAULT},
    {BUTTON_ESC,    LV_KEY_ESC,         LV_KEY_ESC_LONGP,   LV_KEY_DEFAULT},
    {BUTTON_HOME,   LV_KEY_HOME,        LV_KEY_HOME,        LV_KEY_DEFAULT},
    {BUTTON_MENU,   LV_KEY_MENU,        LV_KEY_MENU_LONGP,  LV_KEY_DEFAULT},
    {BUTTON_LEFT,   LV_KEY_LEFT,        LV_KEY_LEFT,        LV_KEY_DEFAULT},
    {BUTTON_RIGHT,  LV_KEY_RIGHT,       LV_KEY_RIGHT,       LV_KEY_DEFAULT},

    /* 4. 系统控制区 (电源/输出锁定) */
    {BUTTON_OUTPUT, LV_KEY_OUTPUT,      LV_KEY_OUTPUT,      LV_KEY_DEFAULT},
    {BUTTON_LOCK,   LV_KEY_LOCK,        LV_KEY_LOCK_LONGP,  LV_KEY_DEFAULT},
};


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
    {KEY_Y2_GPIO_Port, KEY_Y2_Pin},
    {KEY_Y3_GPIO_Port, KEY_Y3_Pin},
    {KEY_Y4_GPIO_Port, KEY_Y4_Pin},
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


/*
 * @brief       lv_key_t Encoder_Get(void)
 * @details     将编码器值转化LV_KEY
 */
#include "TIM.h"
static lv_key_t Encoder_Get(void)
{
#define ENCODER_OFFSET (2000ul)
    static uint8_t flag = 0;
    if(flag == 0)
    {
        flag = 1;
        HAL_TIM_Base_Start(&htim2);
        htim2.Instance->CNT = ENCODER_OFFSET;
    }
    lv_key_t key = LV_KEY_DEFAULT;
    SCB_CleanInvalidateDCache();
    int32_t count = ENCODER_OFFSET - __HAL_TIM_GET_COUNTER(&htim2);
    __HAL_TIM_SET_COUNTER(&htim2, ENCODER_OFFSET);
    static int32_t diffCount = 0;
    diffCount += count;
    if(diffCount > 5) {
        diffCount = 5;
    }
    if(diffCount < -5) {
        diffCount = -5;
    }
    if(diffCount > 0)
    {
        key =LV_KEY_UP ;
        --diffCount;
    }
    else
        if(diffCount < 0)
        {
            key =LV_KEY_DOWN ;
            ++diffCount;
        }
    return key;
}


/*
 * @brief       lv_key_t Button_toKey(uint8_t buttonNum,uint8_t flag)
 * @details     将实体按键转为LV_KEY事件
 */
lv_key_t Button_toKey(uint8_t buttonNum, uint8_t flag)
{
    static uint8_t waitCount = 0;
    if(buttonNum == 0xff) {
    } else {
        //实体按键
        uint16_t tablesize = sizeof(Btn_KeyTable) / sizeof(Btn_KeyTable[0]);
        for(uint8_t i = 0; i < tablesize; ++i)
        {
            if(buttonNum == Btn_KeyTable[i].buttonNum)
            {
                lv_key_t key = LV_KEY_DEFAULT;
                switch(flag)
                {
                    case KEY_STATE_HOLD:
                        key = Btn_KeyTable[i].key_hold;
                        break;
                    case KEY_STATE_CLICKED:
                        key = Btn_KeyTable[i].key_short;
                        break;
                    case KEY_STATE_LONGGP:
                        key = Btn_KeyTable[i].key_long;
                        break;
                    default:
                        key = LV_KEY_DEFAULT;
                        break;
                }
                //                if((key == LV_KEY_ENCODER) || (key == LV_KEY_ENCODER_LONGP))
                {
                    waitCount = 5;
                }
                return key;
            }
        }
    }
    //编码器转换
    lv_key_t encoderKey = Encoder_Get();
    //防止按下编码器 误触发旋转
    if(waitCount == 0) {
        if(encoderKey != LV_KEY_DEFAULT)
        {
            return encoderKey;
        }
    } else {
        waitCount--;
    }
    return LV_KEY_DEFAULT;
}


