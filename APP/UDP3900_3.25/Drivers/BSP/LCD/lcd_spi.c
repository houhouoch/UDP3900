#include "./BSP/LCD/lcd_spi.h"

/**
 * @brief  初始化 LCD SPI 相关的 GPIO
 */
void LCD_SPI_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* 使能 GPIO 时钟 */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();

    /* 配置 CS, SCK, SDA, RST 为推挽输出 */
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH; // H750 建议设为最高速以减小上升沿损耗

    /* 配置 CS  */
    GPIO_InitStruct.Pin = LCD_SPI_CS_PIN;
    HAL_GPIO_Init(LCD_SPI_CS_PORT, &GPIO_InitStruct);

    /* 配置 SCK  和 SDA  */
    GPIO_InitStruct.Pin = LCD_SPI_SCK_PIN | LCD_SPI_SDA_PIN;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* 配置 RST   */
    GPIO_InitStruct.Pin = LCD_SPI_RST_PIN;
    HAL_GPIO_Init(LCD_SPI_RST_PORT, &GPIO_InitStruct);

    /* 初始状态：CS拉高，RST拉高 */
    LCD_CS_HIGH();
    LCD_RST_HIGH();
}

/**
 * @brief  ST7701S 硬件复位时序
 */
void ST7701S_Hardware_Reset(void) {
    LCD_RST_HIGH();
    HAL_Delay(10);
    LCD_RST_LOW();
    HAL_Delay(20); // 复位拉低保持 20ms
    LCD_RST_HIGH();
    HAL_Delay(120); // 复位结束后需等待 120ms 才能发送命令
}

/**
 * @brief  ST7701S 3线9位模拟SPI发送函数
 * @param  is_data: 0-命令(Command), 1-数据(Parameter)
 * @param  value:   要发送的8位字节数据
 */
void ST7701S_SPI_Write(uint8_t is_data, uint8_t value) {
    LCD_CS_LOW();
    __DSB(); // 数据同步，确保电平稳定

    // 1. 发送第1位: D/C Bit (0为命令，1为数据)
    LCD_SCLK_LOW();
    if (is_data) LCD_SDA_HIGH(); else LCD_SDA_LOW();
    __DSB(); // H750 高频补偿
    LCD_SCLK_HIGH();
    __DSB();

    // 2. 循环发送后续8位数据 (MSB优先)
    for (int i = 0; i < 8; i++) {
        LCD_SCLK_LOW();
        if (value & 0x80) LCD_SDA_HIGH(); else LCD_SDA_LOW();
        value <<= 1;
        __DSB();
        LCD_SCLK_HIGH();
        __DSB();
    }

    __DSB();
    LCD_CS_HIGH();
}

/**
 * @brief  ST7701S 厂家初始化序列
 */
void ST7701S_Init_Sequence(void) {
    SPI_WriteComm (0xff);
    SPI_WriteData (0x77);
    SPI_WriteData (0x01);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x13);
    SPI_WriteComm (0xef);
    SPI_WriteData (0x08);
    SPI_WriteComm (0xff);
    SPI_WriteData (0x77);
    SPI_WriteData (0x01);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x10);
    SPI_WriteComm (0xc0);
    SPI_WriteData (0x77);
    SPI_WriteData (0x00);
    SPI_WriteComm (0xc1);
    SPI_WriteData (0x11);
    SPI_WriteData (0x0c);
    SPI_WriteComm (0xc2);
    SPI_WriteData (0x07);
    SPI_WriteData (0x02);
    SPI_WriteComm (0xcc);
    SPI_WriteData (0x30);
    SPI_WriteComm (0xB0);
    SPI_WriteData (0x06);
    SPI_WriteData (0xCF);
    SPI_WriteData (0x14);
    SPI_WriteData (0x0C);
    SPI_WriteData (0x0F);
    SPI_WriteData (0x03);
    SPI_WriteData (0x00);
    SPI_WriteData (0x0A);
    SPI_WriteData (0x07);
    SPI_WriteData (0x1B);
    SPI_WriteData (0x03);
    SPI_WriteData (0x12);
    SPI_WriteData (0x10);
    SPI_WriteData (0x25);
    SPI_WriteData (0x36);
    SPI_WriteData (0x1E);
    SPI_WriteComm (0xB1);
    SPI_WriteData (0x0C);
    SPI_WriteData (0xD4);
    SPI_WriteData (0x18);
    SPI_WriteData (0x0C);
    SPI_WriteData (0x0E);
    SPI_WriteData (0x06);
    SPI_WriteData (0x03);
    SPI_WriteData (0x06);
    SPI_WriteData (0x08);
    SPI_WriteData (0x23);
    SPI_WriteData (0x06);
    SPI_WriteData (0x12);
    SPI_WriteData (0x10);
    SPI_WriteData (0x30);
    SPI_WriteData (0x2F);
    SPI_WriteData (0x1F);
    SPI_WriteComm (0xff);
    SPI_WriteData (0x77);
    SPI_WriteData (0x01);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x11);
    SPI_WriteComm (0xb0);
    SPI_WriteData (0x73);
    SPI_WriteComm (0xb1);
    SPI_WriteData (0x7C);
    SPI_WriteComm (0xb2);
    SPI_WriteData (0x83);
    SPI_WriteComm (0xb3);
    SPI_WriteData (0x80);
    SPI_WriteComm (0xb5);
    SPI_WriteData (0x49);
    SPI_WriteComm (0xb7);
    SPI_WriteData (0x87);
    SPI_WriteComm (0xb8);
    SPI_WriteData (0x33);
    SPI_WriteComm (0xb9);
    SPI_WriteData (0x10);
    SPI_WriteData (0x1f);
    SPI_WriteComm (0xbb);
    SPI_WriteData (0x03);
    SPI_WriteComm (0xc1);
    SPI_WriteData (0x08);
    SPI_WriteComm (0xc2);
    SPI_WriteData (0x08);
    SPI_WriteComm (0xd0);
    SPI_WriteData (0x88);
    SPI_WriteComm (0xe0);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x02);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x0c);
    SPI_WriteComm (0xe1);
    SPI_WriteData (0x05);
    SPI_WriteData (0x96);
    SPI_WriteData (0x07);
    SPI_WriteData (0x96);
    SPI_WriteData (0x06);
    SPI_WriteData (0x96);
    SPI_WriteData (0x08);
    SPI_WriteData (0x96);
    SPI_WriteData (0x00);
    SPI_WriteData (0x44);
    SPI_WriteData (0x44);
    SPI_WriteComm (0xe2);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x03);
    SPI_WriteData (0x03);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x02);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x02);
    SPI_WriteData (0x00);
    SPI_WriteComm (0xe3);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x33);
    SPI_WriteData (0x33);
    SPI_WriteComm (0xe4);
    SPI_WriteData (0x44);
    SPI_WriteData (0x44);
    SPI_WriteComm (0xe5);
    SPI_WriteData (0x0d);
    SPI_WriteData (0xd4);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteData (0x0f);
    SPI_WriteData (0xd6);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteData (0x09);
    SPI_WriteData (0xd0);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteData (0x0b);
    SPI_WriteData (0xd2);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteComm (0xe6);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x33);
    SPI_WriteData (0x33);
    SPI_WriteComm (0xe7);
    SPI_WriteData (0x44);
    SPI_WriteData (0x44);
    SPI_WriteComm (0xe8);
    SPI_WriteData (0x0e);
    SPI_WriteData (0xd5);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteData (0x10);
    SPI_WriteData (0xd7);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteData (0x0a);
    SPI_WriteData (0xd1);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteData (0x0c);
    SPI_WriteData (0xd3);
    SPI_WriteData (0x28);
    SPI_WriteData (0x8c);
    SPI_WriteComm (0xeb);
    SPI_WriteData (0x00);
    SPI_WriteData (0x01);
    SPI_WriteData (0xe4);
    SPI_WriteData (0xe4);
    SPI_WriteData (0x44);
    SPI_WriteData (0x00);
    SPI_WriteComm (0xed);
    SPI_WriteData (0xf3);
    SPI_WriteData (0xc1);
    SPI_WriteData (0xba);
    SPI_WriteData (0x0f);
    SPI_WriteData (0x66);
    SPI_WriteData (0x77);
    SPI_WriteData (0x44);
    SPI_WriteData (0x55);
    SPI_WriteData (0x55);
    SPI_WriteData (0x44);
    SPI_WriteData (0x77);
    SPI_WriteData (0x66);
    SPI_WriteData (0xf0);
    SPI_WriteData (0xab);
    SPI_WriteData (0x1c);
    SPI_WriteData (0x3f);
    SPI_WriteComm (0xef);
    SPI_WriteData (0x10);
    SPI_WriteData (0x0d);
    SPI_WriteData (0x04);
    SPI_WriteData (0x08);
    SPI_WriteData (0x3f);
    SPI_WriteData (0x1f);
    SPI_WriteComm (0xff);
    SPI_WriteData (0x77);
    SPI_WriteData (0x01);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x13);
    SPI_WriteComm (0xe8);
    SPI_WriteData (0x00);
    SPI_WriteData (0x0e);
    SPI_WriteComm (0x11);
    HAL_Delay(120);
    SPI_WriteComm (0xe8);
    SPI_WriteData (0x00);
    SPI_WriteData (0x0c);
    HAL_Delay(10);
    SPI_WriteComm (0xe8);
    SPI_WriteData (0x40);
    SPI_WriteData (0x00);
    SPI_WriteComm (0xff);
    SPI_WriteData (0x77);
    SPI_WriteData (0x01);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteComm (0x36);
    SPI_WriteData (0x00);
    SPI_WriteComm (0x3A);
    SPI_WriteData (0x55);//565
    SPI_WriteComm (0x29);
    HAL_Delay(20);
    /*
    SPI_WriteComm (0xff);
    SPI_WriteData (0x77);
    SPI_WriteData (0x01);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    SPI_WriteData (0x10);
    SPI_WriteComm (0xe5);
    SPI_WriteData (0x00);
    SPI_WriteData (0x00);
    */
}


