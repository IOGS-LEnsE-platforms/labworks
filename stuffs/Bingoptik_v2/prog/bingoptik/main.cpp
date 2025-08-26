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

#define		TIMING		10


I2C         my_i2c(PB_7, PB_6);
SSD1306     my_lcd(&my_i2c, MAX_X, MAX_Y);


void tik_ISR(void){
  cnt_tik = !cnt_tik;
	tik_cnt++;
	mvt_speed_cnt++;
}

void mvt_ISR(void){
	mvt_cnt++;
	if(mode == SMOOTH){
		if(mvt_cnt % SMOOTH_NB == 0){
			tik_cnt_smooth++;
		}
	}
	mvt_detected = true;
	mvt_speed_cnt_old = mvt_speed_cnt;
	mvt_speed_cnt = 0;
}



/* Défilement couleur sur 3 LEDs uniquement - OK pour bobine ? A modifier ? */
void test3(int cnt){
	int val = cnt % STRIP_SIZE_MIRROR;
	int led_nb = mvt_cnt % COLOR_VARIATION;
	for(int k = val; k < val+BOBINE_NB_LED; k++){
		leds_mirror.set_pix_RGB(k, 0, 0, 0);
		leds_mirror.set_pix_RGB(k+BOBINE_NB_LED, R_trans[led_nb], G_trans[led_nb], B_trans[led_nb]);
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
	strip_bobine.set_timings(3, 10, 8, 5);

	strip_mirror.break_trame();
	strip_mirror.send_leds(leds_mirror.get_array()); 
	strip_bobine.break_trame();
	strip_bobine.send_leds(leds_bobine.get_array());
	printf("\tEnd of STRIPS Init\r\n"); 
	
	// Timing counter Init
	tik.attach(&tik_ISR, 100us);
	tik_smooth.attach(&mvt_ISR, 36ms);
	led1 = 1;
	
	/*
	// Display / Welcome message
	my_lcd.fill_rect(10, 20, 20, 30, SSD1306_WHITE);
	my_lcd.set_position(50, 20);
	my_lcd.draw_string((char *)"BingOptik v2.1", SSD1306_WHITE, NORMAL);
	my_lcd.display();
	*/
	
	//mvt_detect_in.rise(&mvt_ISR);

	// MAIN LOOP
	while (true)
	{
		if(mvt_detected){ 
			//bingo_mirror();
			smooth_mirror();
			mvt_detected = false;
		}
		else{
			__asm__("nop");
			__asm__("nop");
			__asm__("nop");
		}

		/* Mode auto si non détection de mouvement - TIMER A FAIRE */
		
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
