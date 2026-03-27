/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os2.h"
#include "./BSP/MPU/mpu.h"
#include "./BSP/LED/led.h"
#include <stdio.h>
#include "./BSP/LCD/lcd_spi.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define SIGNAL_DMA2D_TC        (1UL << 0)  // 0x01: ???????
#define SIGNAL_DMA2D_ERR       (1UL << 1)  // 0x02: ???????
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY_X7_Pin GPIO_PIN_5
#define KEY_X7_GPIO_Port GPIOB
#define LCD_SCK_Pin GPIO_PIN_3
#define LCD_SCK_GPIO_Port GPIOB
#define LCD_SDA_Pin GPIO_PIN_7
#define LCD_SDA_GPIO_Port GPIOD
#define UART7_T_Pin GPIO_PIN_15
#define UART7_T_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_10
#define LCD_CS_GPIO_Port GPIOG
#define LCD_RST_Pin GPIO_PIN_9
#define LCD_RST_GPIO_Port GPIOG
#define LED_Indicator_Pin GPIO_PIN_13
#define LED_Indicator_GPIO_Port GPIOC
#define KEY_Y4_Pin GPIO_PIN_2
#define KEY_Y4_GPIO_Port GPIOH
#define KEY_Y3_Pin GPIO_PIN_3
#define KEY_Y3_GPIO_Port GPIOH
#define RGN_BK_Pin GPIO_PIN_8
#define RGN_BK_GPIO_Port GPIOC
#define KEY_Y1_Pin GPIO_PIN_4
#define KEY_Y1_GPIO_Port GPIOH
#define UART7_R_Pin GPIO_PIN_6
#define UART7_R_GPIO_Port GPIOF
#define Control_LED_Pin GPIO_PIN_0
#define Control_LED_GPIO_Port GPIOC
#define KEY_Y2_Pin GPIO_PIN_3
#define KEY_Y2_GPIO_Port GPIOC
#define Encoder_B_Pin GPIO_PIN_1
#define Encoder_B_GPIO_Port GPIOA
#define Encoder_A_Pin GPIO_PIN_0
#define Encoder_A_GPIO_Port GPIOA
#define Encoder_Key_Pin GPIO_PIN_2
#define Encoder_Key_GPIO_Port GPIOA
#define KEY_X8_Pin GPIO_PIN_5
#define KEY_X8_GPIO_Port GPIOA
#define KEY_X5_Pin GPIO_PIN_12
#define KEY_X5_GPIO_Port GPIOB
#define KEY_X6_Pin GPIO_PIN_13
#define KEY_X6_GPIO_Port GPIOB
#define BEEP_Pin GPIO_PIN_7
#define BEEP_GPIO_Port GPIOA
#define KEY_X2_Pin GPIO_PIN_1
#define KEY_X2_GPIO_Port GPIOB
#define KEY_X1_Pin GPIO_PIN_0
#define KEY_X1_GPIO_Port GPIOB
#define KEY_X3_Pin GPIO_PIN_10
#define KEY_X3_GPIO_Port GPIOB
#define KEY_X4_Pin GPIO_PIN_11
#define KEY_X4_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
