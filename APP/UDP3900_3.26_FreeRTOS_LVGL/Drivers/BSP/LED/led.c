#include "./BSP/LED/led.h"

/* 静态影子寄存器，保存当前 8 个位元的显示状态 */
static uint8_t g_led_shadow = 0x00;

/**
 * @brief  私有函数：将 KEY_X 总线引脚设为指定电平
 * @note   请在此处填入你 KEY_X1~X8 对应的 GPIO 操作
 */
static void Panel_Write_Bus(uint8_t data) {
    HAL_GPIO_WritePin(KEY_X1_GPIO_Port, KEY_X1_Pin, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_X2_GPIO_Port, KEY_X2_Pin, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_X3_GPIO_Port, KEY_X3_Pin, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_X4_GPIO_Port, KEY_X4_Pin, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_X5_GPIO_Port, KEY_X5_Pin, (data & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_X6_GPIO_Port, KEY_X6_Pin, (data & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_X7_GPIO_Port, KEY_X7_Pin, (data & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(KEY_X8_GPIO_Port, KEY_X8_Pin, (data & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

/**
 * @brief  初始化锁存器 LE 引脚和 KEY 总线
 */
void Panel_LED_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE(); // LE 所在时钟

    /* 初始化 LE 引脚 */
    HAL_GPIO_WritePin(LATCH_LE_PORT, LATCH_LE_PIN, GPIO_PIN_RESET); // 默认锁存
    GPIO_InitStruct.Pin = LATCH_LE_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LATCH_LE_PORT, &GPIO_InitStruct);
    

}

/**
 * @brief  核心同步函数：将影子状态刷入 74HC573
 */
static void Panel_LED_Sync(void) {
    /* 1. 准备硬件数据：阴极驱动，低电平点亮，故取反 */
    uint8_t hardware_data = ~g_led_shadow;

    /* 2. 写总线数据 */
    Panel_Write_Bus(hardware_data);

    /* 3. 锁存脉冲 (H750 高速适配) */
    HAL_GPIO_WritePin(LATCH_LE_PORT, LATCH_LE_PIN, GPIO_PIN_SET);
    __DSB(); // 数据同步屏障，确保建立时间
    HAL_GPIO_WritePin(LATCH_LE_PORT, LATCH_LE_PIN, GPIO_PIN_RESET);
}

/**
 * @brief  设置单个 LED 状态
 * @param  led: LED 索引
 * @param  state: 1 亮, 0 灭
 */
void Panel_LED_Set(Panel_LED_t led, uint8_t state) {
    if (state) {
        g_led_shadow |= (1 << led);
    } else {
        g_led_shadow &= ~(1 << led);
    }
    Panel_LED_Sync();
}

/**
 * @brief  全灭所有指示灯
 */
void Panel_LED_AllOff(void) {
    g_led_shadow = 0x00;
    Panel_LED_Sync();
}











/**
 * @brief   初始化系统LED
 * @param   无
 * @retval  无
 */
void led_init(void)
{
    GPIO_InitTypeDef gpio_init_struct = {0};
    
    /* 使能GPIO端口时钟 */
    LED_GPIO_CLK_ENABLE();
    
    /* 配置LED0控制引脚 */
    gpio_init_struct.Pin = LED_GPIO_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init_struct.Pull = GPIO_PULLDOWN;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_GPIO_PORT, &gpio_init_struct);
        
    
    
    /* 关闭LED */
    LED(1);
    Panel_LED_Init();    
    Panel_LED_AllOff(); // 初始全灭
    
}


