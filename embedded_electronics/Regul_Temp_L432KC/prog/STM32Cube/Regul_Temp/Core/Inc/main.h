/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define MESURE_Pin GPIO_PIN_0
#define MESURE_GPIO_Port GPIOA
#define CONSIGNE_Pin GPIO_PIN_1
#define CONSIGNE_GPIO_Port GPIOA
#define HORLOGE_Pin GPIO_PIN_2
#define HORLOGE_GPIO_Port GPIOA
#define ERREUR_Pin GPIO_PIN_4
#define ERREUR_GPIO_Port GPIOA
#define MESUREA5_Pin GPIO_PIN_5
#define MESUREA5_GPIO_Port GPIOA
#define PWM2_Pin GPIO_PIN_0
#define PWM2_GPIO_Port GPIOB
#define PWM_MOT_Pin GPIO_PIN_1
#define PWM_MOT_GPIO_Port GPIOB
#define MODE_Pin GPIO_PIN_11
#define MODE_GPIO_Port GPIOA
#define SIGNE_Pin GPIO_PIN_12
#define SIGNE_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA
#define LD3_Pin GPIO_PIN_3
#define LD3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
