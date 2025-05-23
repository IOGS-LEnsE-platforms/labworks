/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "ssd1306.h"
#include "ssd1306_constants.h"
#include "WS2812.h"
#include "PixelArray.h"

#define     STRIP_SIZE_MIRROR      20
#define     STRIP_SIZE_BOBINE      10

WS2812  strip_mirror(PA_6, STRIP_SIZE_MIRROR, WS2812_STD);
PixelArray leds_mirror(STRIP_SIZE_MIRROR, WS2812_STD);
WS2812  strip_bobine(PA_7, STRIP_SIZE_BOBINE, WS2812_STD);
PixelArray leds_bobine(STRIP_SIZE_BOBINE, WS2812_STD);


#define WAIT_TIME_MS 500 
DigitalOut led1(LED1);

DigitalIn   mode_in(PA_11);

Ticker tik;
DigitalOut  cnt_tik(PA_2);

I2C         my_i2c(PB_7, PB_6);
SSD1306     my_lcd(&my_i2c, MAX_X, MAX_Y);

float   t_consigne_f = 0.0;
float   t_mesure_f = 0.0;
float   t_erreur_f = 0.0;


void tik_ISR(void){
    
}

int main()
{
    printf("BingOptik - v %.1lf\r\n", 2.1);

    my_lcd.init();
		my_lcd.clear_screen();
    thread_sleep_for(200);
	
		strip_mirror.set_timings(6, 13, 14, 5);
		strip_bobine.set_timings(6, 13, 14, 5);

    strip_mirror.break_trame();
    strip_mirror.send_leds(leds_mirror.get_array()); 
    strip_bobine.break_trame();
    strip_bobine.send_leds(leds_bobine.get_array()); 
	

    tik.attach(&tik_ISR, 100us);
    led1 = 1;

    my_lcd.fill_rect(10, 20, 20, 30, SSD1306_WHITE);
    my_lcd.set_position(50, 20);
    my_lcd.draw_string("BingOptik v2.1", SSD1306_WHITE, NORMAL);
    my_lcd.display();

    while (true)
    {
        
				/*
			  my_strip.break_trame();
        wait_us(200000);
        my_leds.set_all_RGB(255, 0, 128);
        my_strip.send_leds(my_leds.get_array());
				*/
			
        thread_sleep_for(WAIT_TIME_MS);
    }
}
