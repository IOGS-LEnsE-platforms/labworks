/**
  ******************************************************************************
  * @file    Display/LCD_Paint/Inc/save.h 
  * @author  MCD Application Team
  * @brief   This file contains image used for LTDC application.   
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SAVE_H
#define __SAVE_H

#define		IMAGE_WIDTH		32
#define		IMAGE_HEIGHT	10
#define		IMAGE_WIDTH_B	IMAGE_WIDTH / 8

__IO const unsigned char im_1_1[IMAGE_WIDTH_B*IMAGE_HEIGHT]=
{
		0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0x00, 0x00
};

#endif /* __SAVE_H */
