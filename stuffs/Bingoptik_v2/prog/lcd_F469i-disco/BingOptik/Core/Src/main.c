/**
  ******************************************************************************
  * @file    LCD_Paint/Src/main.c
  * @author  MCD Application Team
  * @brief   This file provides main program functions
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
PINOUT :
D9 / PA7		Random Analog Input (not connected)
					- ADC1_IN / 28 cycles / Channel 2
D13/ PD3		SYNC - Interrupt In / Clk sync
D8 / PG10		LED Strip Mirror
D11/ PB15		LED Strip film

  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "images.h"
#include "gradient_colors.h"

//extern LTDC_HandleTypeDef  hltdc_eval;

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define			NB_OF_SERIES		1
#define			TIMEOUT_MAX			1000		// * 30 ms = 30 s
#define			TIMEOUT_MVT			10			// * 30 ms = 0.3 s
#define			TIMEOUT_SMOOTH		20			// * 30 ms = 0.3 s
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim2;

uint32_t	timeout_cnt;
uint8_t		timeout_mvt;
uint8_t		timeout_smooth;

uint32_t	rand_cnt;
uint8_t		color_cnt;	// 60 different colors from L432KC - SYNC and SYNC0 inputs
enum	Mode		mode = SMOOTH;

WS2812  	led_strip_mirror;
PixelArray	led_array_mirror;
WS2812  	led_strip_film;
PixelArray	led_array_film;

uint8_t* imgs[] = { &im1_1, &im2_1, &im3_1, &im4_1, &im5_1, &im6_1, &im7_1, &im8_1, &im9_1 };

/* Private function prototypes -----------------------------------------------*/
void init_MCU(void);
void init_LCD(void);
void init_strips(void);
void test_strips(void);

void sync_action(void);

uint8_t *rand_number_pic(uint32_t value);
uint16_t read_adc_polling(void);

static void Draw_Image(const volatile uint8_t *pbmp, uint32_t color);
static void Draw_Logo(const volatile uint8_t *pbmp, uint32_t color, int x, int y);
static void Draw_LEnsE();
static void Draw_Bingo(uint32_t color);

static void SystemClock_Config(void);
static void Error_Handler(void);

static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM2_Init(void);

/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	uint8_t 	*img;
	uint32_t	color_img;
	int k;
	init_MCU();
	init_strips();
	init_LCD();

	timeout_cnt = 0;
	timeout_mvt = 0;
	timeout_smooth = 0;
	mode = SMOOTH;

	/* START !! */
	/* Infinite loop */
	while (1)
	{
		__NOP();
		if(mode == BINGO){
			// Color selection
			int color_nb = color_cnt % COLOR_VARIATION;
			uint8_t		R_i, G_i, B_i;
			color_img = 0xFF000000;
			R_i = R_trans[color_nb] * 255;
			G_i = G_trans[color_nb] * 255;
			B_i = B_trans[color_nb] * 255;
			color_img += (R_i & 0xFF) << 16;
			color_img += (G_i & 0xFF) << 8;
			color_img += (B_i & 0xFF);
			if(timeout_mvt !=0){
				img = rand_number_pic(rand_cnt);
				// Display number on LCD
				Draw_Image(img, color_img);
			}
			else{
				if(timeout_cnt != 0){
					color_img = 0xFFAAAAAA;
					Draw_Image(img, color_img);


					float gain = (float)timeout_cnt / TIMEOUT_MAX;
					// Update LED Strip
					for(int k = 0; k < LED_STRIP_MIRROR_NB; k++){
						uint8_t val = sine_table[(k+2*color_cnt)%LED_STRIP_MIRROR_NB] * gain;
						set_pix_RGB(&led_array_mirror, k, val*R_trans[color_nb], val*G_trans[color_nb], val*B_trans[color_nb]);
					}
					send_leds(&led_strip_mirror, get_array(&led_array_mirror));
					for(int k = 0; k < LED_STRIP_FILM_NB; k++){
						uint8_t val = sine_table[(k+2*color_cnt)%LED_STRIP_FILM_NB] * gain;
						set_pix_RGB(&led_array_film, k, val*R_trans[color_nb], val*G_trans[color_nb], val*B_trans[color_nb]);
					}
					send_leds(&led_strip_film, get_array(&led_array_film));

				}
			}

		}
		else{
			// MODE SMOOTH
			if(timeout_smooth == 0){
		        color_cnt++;
				timeout_smooth = TIMEOUT_SMOOTH;

				uint32_t	color_img = 0xFF000000;
				float		R_i, G_i, B_i;
				uint16_t 	color_nb = color_cnt % COLOR_VARIATION_SMOOTH;
				R_i = R_smooth[color_nb];
				G_i = G_smooth[color_nb];
				B_i = B_smooth[color_nb];
				color_img += ((int)(R_i * 255) & 0xFF) << 16;
				color_img += ((int)(G_i * 255) & 0xFF) << 8;
				color_img += ((int)(B_i * 255) & 0xFF);
				Draw_Bingo(color_img);

				// Update LED Strip
				for(int k = LED_STRIP_MIRROR_NB; k >= 0; k--){
					uint8_t val = smooth_table[(k+color_cnt)%LED_STRIP_MIRROR_NB] / 4;
					set_pix_RGB(&led_array_mirror, LED_STRIP_MIRROR_NB-k, val*R_i, val*G_i, val*B_i);
				}
				send_leds(&led_strip_mirror, get_array(&led_array_mirror));
				for(int k = 0; k < LED_STRIP_FILM_NB; k++){
					uint8_t val = smooth_table[(k+color_cnt)%LED_STRIP_FILM_NB] / 4;
					set_pix_RGB(&led_array_film, k, val*R_i, val*G_i, val*B_i);
				}
				send_leds(&led_strip_film, get_array(&led_array_film));

				//HAL_GPIO_TogglePin(LED_M_GPIO_Port, LED_M_Pin);
			}
		}

		//test_strips();
		if((timeout_cnt == 0) && (mode == BINGO)){
			BSP_LCD_Clear(LCD_COLOR_BLACK);
			mode = SMOOTH;
			// Draw LEnsE Logo (Orange)
			Draw_LEnsE();
		}
  }
}

/**
  * @brief  Init the microcontroller Unit.
  * @retval None
  */
void init_MCU(void){
	color_cnt = 0;
	rand_cnt = 0;

	/* STM32F4xx HAL library initialization:
	- Configure the Flash prefetch, instruction and Data caches
	- Configure the Systick to generate an interrupt each 1 msec
	- Set NVIC Group Priority to 4
	- Global MSP (MCU Support Package) initialization
	*/
	HAL_Init();

	/* Configure the system clock to 180 MHz */
	SystemClock_Config();

	/* Configure LED1 and LED3 */
	//BSP_LED_Init(LED1);
	//BSP_LED_Init(LED3);

	MX_GPIO_Init();
	MX_ADC1_Init();
	MX_TIM2_Init();
	HAL_TIM_Base_Start_IT(&htim2);
}

/**
  * @brief  Init the LCD screen.
  * @retval None
  */
void init_LCD(void){
	uint8_t  sdram_status = SDRAM_OK;
	uint8_t  lcd_status = LCD_OK;

	/*##-1- Initialize the SDRAM ###############################################*/
	sdram_status = BSP_SDRAM_Init();
	if(sdram_status != SDRAM_OK){	Error_Handler();	}
	/*##-2- LCD Initialization #################################################*/
	/* Initialize the LCD DSI */
	lcd_status = BSP_LCD_Init() ;
	if(lcd_status != LCD_OK){		Error_Handler();	}
	lcd_status = BSP_LCD_InitEx(LCD_ORIENTATION_LANDSCAPE);
	if(lcd_status != LCD_OK){		Error_Handler(); 	}
	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER_BACKGROUND, LCD_FB_START_ADDRESS);
	/* Clear the LCD Background layer */
	BSP_LCD_Clear(LCD_COLOR_BLACK);

	// Draw LEnsE Logo (Orange)
	Draw_LEnsE();
	// Wait
	for(int zz = 0; zz < 1000000; zz++){
	  for(int zx = 0; zx < 25; zx++){
		  __NOP();
	  }
	}
	// Draw Bingo (Blue)
	Draw_Bingo(LCD_COLOR_BLUE);
	// Wait
	for(int zz = 0; zz < 1000000; zz++){
	  for(int zx = 0; zx < 25; zx++){
		  __NOP();
	  }
	}
}

/**
  * @brief  Init the LED strips.
  * @retval None
  */
void init_strips(void){
	init_ws2812(&led_strip_mirror, LED_M_GPIO_Port, LED_M_Pin, LED_STRIP_MIRROR_NB, 24);
	init_array(&led_array_mirror, LED_STRIP_MIRROR_NB, 24);
	init_ws2812(&led_strip_film, LED_F_GPIO_Port, LED_F_Pin, LED_STRIP_FILM_NB, 32);
	init_array(&led_array_film, LED_STRIP_FILM_NB, 32);

	set_timings(&led_strip_mirror, 3, 6, 6, 4);
	break_trame(&led_strip_mirror);
	blackout(&led_strip_mirror);
	set_timings(&led_strip_film, 3, 6, 6, 4);
	break_trame(&led_strip_film);
	blackout(&led_strip_film);
}

/**
  * @brief  Test the LED strips.
  * @retval None
  */
void test_strips(void){
	int k;
	for(k = 0; k < 10000000; k++)
		__NOP();
	//break_trame(&led_strip_mirror);
	set_all_RGB(&led_array_mirror, 92, 0, 48);
	send_leds(&led_strip_mirror, get_array(&led_array_mirror));
	//break_trame(&led_strip_film);
	set_all_RGB(&led_array_film, 128, 0, 0);
	send_leds(&led_strip_film, get_array(&led_array_film));
	for(k = 0; k < 10000000; k++)
		__NOP();
	//break_trame(&led_strip_mirror);
	set_all_RGB(&led_array_mirror, 0, 128, 0);
	send_leds(&led_strip_mirror, get_array(&led_array_mirror));
	//break_trame(&led_strip_film);
	set_all_RGB(&led_array_film, 0, 64, 64);
	send_leds(&led_strip_film, get_array(&led_array_film));
}

/**
  * @brief  Callback function on CLK SYNC input.
  * @retval None
  */
void sync_action(void){
	rand_cnt++;
	color_cnt++;
	mode = BINGO;
	timeout_cnt = TIMEOUT_MAX;
	// Color selection
	int color_nb = color_cnt % COLOR_VARIATION;

	// Update LED Strip
	for(int k = 0; k < LED_STRIP_MIRROR_NB; k++){
		uint8_t val = sine_table[(k+2*color_cnt)%LED_STRIP_MIRROR_NB];
		set_pix_RGB(&led_array_mirror, LED_STRIP_MIRROR_NB-k, val*R_trans[color_nb], val*G_trans[color_nb], val*B_trans[color_nb]);
	}
	send_leds(&led_strip_mirror, get_array(&led_array_mirror));
	for(int k = 0; k < LED_STRIP_FILM_NB; k++){
		uint8_t val = sine_table[(k+2*color_cnt)%LED_STRIP_FILM_NB];
		set_pix_RGB(&led_array_film, k, val*R_trans[color_nb], val*G_trans[color_nb], val*B_trans[color_nb]);
	}
	send_leds(&led_strip_film, get_array(&led_array_film));
}

/**
  * @brief  Random choice.
  * @retval None
  */
uint8_t *rand_number_pic(uint32_t value){
	// Conversion of RANDOM analog input
	uint16_t ADC_VAL = read_adc_polling();
	// Random selection
	uint32_t rd_nb = (ADC_VAL + value) % (NB_OF_SERIES * 9);
	return imgs[rd_nb];
}

/**
  * @brief  Start a conversion on D5 (PA_2)
  * @retval None
  */
uint16_t read_adc_polling(void) {
	uint16_t adc_value = 100;

    HAL_ADC_Start(&hadc1);
    // Waiting end of conversion
    if (HAL_ADC_PollForConversion(&hadc1, 100) == HAL_OK) {
        // Lecture de la valeur convertie
    	adc_value = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);
    return adc_value;
}

/**
  * @brief  Interrupt action on TIM2
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim->Instance == TIM2) {
    	if(timeout_mvt != 0)	timeout_mvt--;
    	if(timeout_cnt != 0)	timeout_cnt--;
    	if(timeout_smooth != 0)	timeout_smooth--;
    }
}

/**
  * @brief  Draws the images.
  * @param  pbmp: Pointer to Bmp picture address in the internal Flash
  * @param  color: Color in ARGB8888 format
  * @retval None
  */
static void Draw_Image(const volatile uint8_t *pbmp, uint32_t color)
{
	/* Display a binary image on the LCD (Zoom x4) */
	//BSP_LCD_Clear(LCD_COLOR_BLACK);

	for(int i = 0; i < IMAGE_HEIGHT; i++){
		for(int j = 0; j < IMAGE_WIDTH; j++){
			int pixel_nb = j%8;
			int pixel_block_nb = j/8;
			int pixel_value = pbmp[pixel_block_nb + i * IMAGE_WIDTH_B] >> (7-pixel_nb);

			if((pixel_value & 0x01) == 0x01){
				for(int k = 0; k < 4; k++){
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+0, color);
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+1, color);
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+2, color);
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+3, color);
				}
			}
			else{
				for(int k = 0; k < 4; k++){
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+0, LCD_COLOR_BLACK);
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+1, LCD_COLOR_BLACK);
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+2, LCD_COLOR_BLACK);
					BSP_LCD_DrawPixel(4*(pixel_block_nb * 8 + pixel_nb)+k, 4*i+3, LCD_COLOR_BLACK);
				}
			}
	 }
  }
}

/**
  * @brief  Draws a logo.
  * @param  pbmp: Pointer to Bmp picture address in the internal Flash
  * @param  color: Color in ARGB8888 format
  * @retval None
  */
static void Draw_Logo(const volatile uint8_t *pbmp, uint32_t color, int x, int y)
{
	/* Display a binary image on the LCD */
	//BSP_LCD_Clear(LCD_COLOR_BLACK);

	for(int i = 0; i < IMAGE_HEIGHT; i++){
		for(int j = 0; j < IMAGE_WIDTH; j++){
			int pixel_nb = j%8;
			int pixel_block_nb = j/8;
			int pixel_value = pbmp[pixel_block_nb + i * IMAGE_WIDTH_B] >> (7-pixel_nb);

			if((pixel_value & 0x01) == 0x01){
				BSP_LCD_DrawPixel((pixel_block_nb * 8 + pixel_nb)+x, i+y, color);
			}
			else{
				BSP_LCD_DrawPixel((pixel_block_nb * 8 + pixel_nb)+x, i+y, LCD_COLOR_BLACK);
			}
		}
	}
}

/**
  * @brief  Draws the LEnsE logo in orange.
  * @retval None
  */
static void Draw_LEnsE(){
	Draw_Logo(&imlogo_lense_0_0, LCD_COLOR_ORANGE, 1*200, 2*120);
	Draw_Logo(&imlogo_lense_0_200, LCD_COLOR_ORANGE, 2*200, 2*120);
	Draw_Logo(&imlogo_lense_120_0, LCD_COLOR_ORANGE, 1*200, 3*120);
	Draw_Logo(&imlogo_lense_120_200, LCD_COLOR_ORANGE, 2*200, 3*120);
}

/**
  * @brief  Draws the Bing'Optik logo in a specific color.
  * @param  color: Color in ARGB8888 format
  * @retval None
  */
static void Draw_Bingo(uint32_t color){
	Draw_Logo(&imlogo_bingo_0_0, color, 0, 0);
	Draw_Logo(&imlogo_bingo_0_200, color, 200, 0);
	Draw_Logo(&imlogo_bingo_0_400, color, 400, 0);
	Draw_Logo(&imlogo_bingo_0_600, color, 600, 0);
	Draw_Logo(&imlogo_bingo_120_0, color, 0, 120);
	Draw_Logo(&imlogo_bingo_120_200, color, 200, 120);
	Draw_Logo(&imlogo_bingo_120_400, color, 400, 120);
	Draw_Logo(&imlogo_bingo_120_600, color, 600, 120);
}

/**
  * @brief  EXT Interrupt Callback Function
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == SYNC_Pin) // If The INT Source Is EXTI Line9 (A9 Pin)
    {
    	mode = BINGO;
    	timeout_mvt = TIMEOUT_MVT;
    	sync_action();
    }
}


const uint8_t sine_table[LED_STRIP_MIRROR_NB] = {
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,
	50,  60,
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,
	50,  60,
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,
	50,  60,
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,
	50,  60,
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,
	50,  60
};

const uint8_t smooth_table[LED_STRIP_MIRROR_NB] = {
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255, 	0, 	0, 255, 255, 	0, 	0,  255, 255, 0, 	0,
	255, 255
};


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* Turn LED3 on */
  BSP_LED_On(LED3);
  while(1)
  {
  }
}


/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 180000000
  *            HCLK(Hz)                       = 180000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 360
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            PLL_R                          = 6
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  RCC_OscInitStruct.PLL.PLLR = 6;

  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }

  /* Activate the OverDrive to reach the 180 MHz Frequency */
  ret = HAL_PWREx_EnableOverDrive();
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
}


/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */

static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  __HAL_RCC_ADC1_CLK_ENABLE();
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_7;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOK_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();


  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_M_GPIO_Port, LED_M_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : SYNC_Pin */
  GPIO_InitStruct.Pin = SYNC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SYNC_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  /*Configure GPIO pin : PA7 (ADC1_IN7) */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_M_Pin */
  GPIO_InitStruct.Pin = LED_M_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_M_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_F_Pin */
  GPIO_InitStruct.Pin = LED_F_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_F_GPIO_Port, &GPIO_InitStruct);
}


/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 3000;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV2;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */
/**
  * @}
  */
