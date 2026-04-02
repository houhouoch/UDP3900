#ifndef __LCD_SPI_H
#define __LCD_SPI_H

#include "stm32h7xx_hal.h"

/* LCD SPI 引脚定义 */
#define LCD_SPI_CS_PORT      GPIOG
#define LCD_SPI_CS_PIN       GPIO_PIN_10

#define LCD_SPI_SCK_PORT     GPIOB
#define LCD_SPI_SCK_PIN      GPIO_PIN_3

#define LCD_SPI_SDA_PORT     GPIOD
#define LCD_SPI_SDA_PIN      GPIO_PIN_7

#define LCD_SPI_RST_PORT     GPIOG
#define LCD_SPI_RST_PIN      GPIO_PIN_9   /* 根据原理图 MCP2518_NI 链路映射 */

/* 引脚操作宏定义 */
#define LCD_CS_LOW()         HAL_GPIO_WritePin(LCD_SPI_CS_PORT, LCD_SPI_CS_PIN, GPIO_PIN_RESET)
#define LCD_CS_HIGH()        HAL_GPIO_WritePin(LCD_SPI_CS_PORT, LCD_SPI_CS_PIN, GPIO_PIN_SET)

#define LCD_SCLK_LOW()       HAL_GPIO_WritePin(LCD_SPI_SCK_PORT, LCD_SPI_SCK_PIN, GPIO_PIN_RESET)
#define LCD_SCLK_HIGH()      HAL_GPIO_WritePin(LCD_SPI_SCK_PORT, LCD_SPI_SCK_PIN, GPIO_PIN_SET)

#define LCD_SDA_LOW()        HAL_GPIO_WritePin(LCD_SPI_SDA_PORT, LCD_SPI_SDA_PIN, GPIO_PIN_RESET)
#define LCD_SDA_HIGH()       HAL_GPIO_WritePin(LCD_SPI_SDA_PORT, LCD_SPI_SDA_PIN, GPIO_PIN_SET)

#define LCD_RST_LOW()        HAL_GPIO_WritePin(LCD_SPI_RST_PORT, LCD_SPI_RST_PIN, GPIO_PIN_RESET)
#define LCD_RST_HIGH()       HAL_GPIO_WritePin(LCD_SPI_RST_PORT, LCD_SPI_RST_PIN, GPIO_PIN_SET)

/* 封装 9-bit SPI 写入接口 */
#define SPI_WriteComm(cmd)  ST7701S_SPI_Write(0, cmd)
#define SPI_WriteData(dat)  ST7701S_SPI_Write(1, dat)

/* 函数声明 */
void LCD_SPI_Init(void);
void ST7701S_Hardware_Reset(void);
void ST7701S_SPI_Write(uint8_t is_data, uint8_t value);
void ST7701S_Init_Sequence(void);
#endif /* __LCD_SPI_H */

