/* BingOptik project / demo
 *		Developed by LEnsE / Institut d'Optique
 *		lense.institutoptique.fr
 *********************************************************
 *		Author : Julien VILLEMEJANE - 26/may/2025
 */

#include "mbed.h"
#include "bingo_strips.h"
#include "ssd1306.h"
#include "ssd1306_constants.h"
#include "WS2812.h"
#include "PixelArray.h"

enum 		Mode 		mode = SMOOTH;

#define     STRIP_SIZE_MIRROR      150
#define     STRIP_SIZE_BOBINE      100

WS2812  strip_mirror(PA_6, STRIP_SIZE_MIRROR, WS2812_STD);
PixelArray leds_mirror(STRIP_SIZE_MIRROR, WS2812_STD);

WS2812  strip_bobine(PA_7, STRIP_SIZE_BOBINE, WS2812_STD);
PixelArray leds_bobine(STRIP_SIZE_BOBINE, WS2812_STD);

DigitalOut led1(LED1);

InterruptIn	mvt_detect(PA_7);
int					mvt_cnt = 0;


DigitalIn   mode_in(PA_11);
Ticker tik;
DigitalOut  cnt_tik(PA_2);
int					tik_cnt = 0;

I2C         my_i2c(PB_7, PB_6);
SSD1306     my_lcd(&my_i2c, MAX_X, MAX_Y);


void tik_ISR(void){
  cnt_tik = !cnt_tik;
	tik_cnt++;
}

void mvt_ISR(void){
	mvt_cnt++;
}


int main()
{
	printf("BingOptik - v %.1lf\r\n", 2.1);
	// LCD Init
	my_lcd.init();
	my_lcd.clear_screen();
	thread_sleep_for(200);

	// LEDs strip Init
	strip_mirror.set_timings(6, 13, 14, 5);
	strip_bobine.set_timings(6, 13, 14, 5);

	strip_mirror.break_trame();
	strip_mirror.send_leds(leds_mirror.get_array()); 
	strip_bobine.break_trame();
	strip_bobine.send_leds(leds_bobine.get_array()); 
	
	// Timing counter Init
	tik.attach(&tik_ISR, 100us);
	led1 = 1;
	
	// Display / Welcome message
	my_lcd.fill_rect(10, 20, 20, 30, SSD1306_WHITE);
	my_lcd.set_position(50, 20);
	my_lcd.draw_string((char *)"BingOptik v2.1", SSD1306_WHITE, NORMAL);
	my_lcd.display();
	
	mvt_detect.rise(&mvt_ISR);

	// MAIN LOOP
	while (true)
	{
		int 	color_choice;
		
		strip_mirror.break_trame();
		switch(mode){
			case BINGO:
				color_choice = mvt_cnt % 6;
				switch(color_choice){
					case 0:
						strip_mirror.send_leds((int *)violet);
						break;
					case 1:
						strip_mirror.send_leds((int *)blue);
						break;
					case 2:
						strip_mirror.send_leds((int *)yellow);
						break;
					case 3:
						strip_mirror.send_leds((int *)red);
						break;
					default:
						break;
				}
				break;
			
			case INTENSITY:
				break;
				
			
			case SMOOTH:
			default:
				color_choice = smooth_rgb(tik_cnt);
				leds_mirror.set_all_RGB_int(color_choice);
				strip_mirror.send_leds(leds_mirror.get_array());
				break;
		}
		
	}
}
