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

#define		TIMING		10

enum 		Mode 		mode = SMOOTH;

WS2812  strip_mirror(PA_6, STRIP_SIZE_MIRROR, WS2812_STD);
PixelArray leds_mirror(STRIP_SIZE_MIRROR, WS2812_STD);

/*
WS2812  strip_bobine(PA_7, STRIP_SIZE_BOBINE, WS2812_STD);
PixelArray leds_bobine(STRIP_SIZE_BOBINE, WS2812_STD);
*/

DigitalOut led1(LED1);

InterruptIn	mvt_detect_in(PA_7);
int					mvt_cnt = 0;
int					mvt_cnt_old = 0;
bool				mvt_detected = false;
int					mvt_speed_cnt = 0;
int					mvt_speed_cnt_old = 0;


DigitalIn   mode_in(PA_11);
Ticker tik;
DigitalOut  cnt_tik(PA_2);
int					tik_cnt = 0;

I2C         my_i2c(PB_7, PB_6);
SSD1306     my_lcd(&my_i2c, MAX_X, MAX_Y);


void tik_ISR(void){
  cnt_tik = !cnt_tik;
	tik_cnt++;
	mvt_speed_cnt++;
}

void mvt_ISR(void){
	mvt_cnt++;
	mvt_detected = true;
	mvt_speed_cnt_old = mvt_speed_cnt;
	mvt_speed_cnt = 0;
}


void test1(void){
	int color_choice = mvt_cnt % 6;
	printf("\tD %d S = %d \r\n", color_choice, mvt_speed_cnt_old);
	strip_mirror.break_trame();
	switch(color_choice){
		case 0:
			if(mvt_speed_cnt_old > SPEED_MAX){
				printf("L\t");
				strip_mirror.send_leds((int *)blue_low);
			}
			else{
				printf("S\t");
				strip_mirror.send_leds((int *)blue);						
			}
			break;
		case 1:
			if(mvt_speed_cnt_old > SPEED_MAX){
				printf("L\t");
				strip_mirror.send_leds((int *)yellow_low);
			}
			else{
				printf("S\t");
				strip_mirror.send_leds((int *)yellow);					
			}					
			break;
		case 2:
			if(mvt_speed_cnt_old > SPEED_MAX){
				printf("L\t");
				strip_mirror.send_leds((int *)violet_low);
			}
			else{
				printf("S\t");
				strip_mirror.send_leds((int *)violet);				
			}		
			break;
		case 3:
			if(mvt_speed_cnt_old > SPEED_MAX){
				printf("L\t");
				strip_mirror.send_leds((int *)orange_low);
			}
			else{
				printf("S\t");
				strip_mirror.send_leds((int *)orange);				
			}		
			break;
		case 4:
			if(mvt_speed_cnt_old > SPEED_MAX){
				printf("L\t");
				strip_mirror.send_leds((int *)red_low);
			}
			else{
				printf("S\t");
				strip_mirror.send_leds((int *)red);				
			}		
			break;
		case 5:
			if(mvt_speed_cnt_old > SPEED_MAX){
				printf("L\t");
				strip_mirror.send_leds((int *)green_low);
			}
			else{
				printf("S\t");
				strip_mirror.send_leds((int *)green);				
			}		
			break;
		default:
			break;
	}
}


void test2(void){
	strip_mirror.break_trame();
	if(mvt_speed_cnt_old < SPEED_MAX){  // Fast
		for(int k = 0; k < STRIP_SIZE_MIRROR; k++){
			uint8_t val = sine_table[(k+2*mvt_cnt)%110];
			int led_nb = mvt_cnt % COLOR_VARIATION;
			leds_mirror.set_pix_RGB(k, val*R_trans[led_nb], val*G_trans[led_nb], val*B_trans[led_nb]);
		}
		mvt_cnt_old = mvt_cnt;
	}
	else{
		for(int k = 0; k < STRIP_SIZE_MIRROR; k++){
			uint8_t val = sine_table[(k+mvt_cnt_old)%110];
			int led_nb = mvt_cnt_old % 6;
			leds_mirror.set_pix_RGB(k, val*R_val[led_nb], val*G_val[led_nb], val*B_val[led_nb]);
		}
	}
	strip_mirror.send_leds(leds_mirror.get_array());
}

int main()
{
	printf("BingOptik - v %.1lf\r\n", 2.1);
	// LCD Init
	/*
	my_lcd.init();
	my_lcd.clear_screen();
	thread_sleep_for(200);
	printf("\tEnd of Screen Init");
	*/

	// LEDs strip Init - int t0h, int t0l, int t1h, int t1l
	strip_mirror.set_timings(3, 10, 8, 5);
	//strip_bobine.set_timings(3, 10, 8, 5);

	strip_mirror.break_trame();
	strip_mirror.send_leds(leds_mirror.get_array()); 
	//strip_bobine.break_trame();
	//strip_bobine.send_leds(leds_bobine.get_array());
	printf("\tEnd of STRIPS Init\r\n"); 
	
	// Timing counter Init
	tik.attach(&tik_ISR, 100us);
	led1 = 1;
	
	/*
	// Display / Welcome message
	my_lcd.fill_rect(10, 20, 20, 30, SSD1306_WHITE);
	my_lcd.set_position(50, 20);
	my_lcd.draw_string((char *)"BingOptik v2.1", SSD1306_WHITE, NORMAL);
	my_lcd.display();
	*/
	
	mvt_detect_in.rise(&mvt_ISR);

	// MAIN LOOP
	while (true)
	{
		if(mvt_detected){ 
			//test1();
			test2();
			mvt_detected = false;
		}
		else{
			__asm__("nop");
			__asm__("nop");
			__asm__("nop");
		}

		/*
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
		*/
		
	}
}
