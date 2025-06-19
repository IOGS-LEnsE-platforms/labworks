/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "ssd1306.h"
#include "ssd1306_constants.h"
#define     K_GAIN  3
#define			LCD_REFRESH 	1000

#define WAIT_TIME_MS 5 
DigitalOut led1(LED1);

AnalogIn    t_consigne(PA_1);
AnalogIn    t_mesure(PA_0);

InterruptIn   mode_in(PA_11);

AnalogOut   comp_erreur(PA_4);
AnalogOut   mesure_out(PA_5);
DigitalOut  led_signe(PB_0);  // PA_12 normalement

PwmOut      moteur_1(PB_1);  
//PwmOut      moteur_2(PB_0);  

Ticker tik;

I2C         my_i2c(PB_7, PB_6);
SSD1306     my_lcd(&my_i2c, MAX_X, MAX_Y);
bool 		lcd_update = true;
char		lcd_disp[32];
int 		lcd_refresh_cnt = 0;

float   t_consigne_f = 0.0;
float   t_consigne_f_old = 0.0;
float   t_consigne_f_new = 0.0;
float   t_mesure_f = 0.0;
float   t_erreur_f = 0.0;


void mode_detect(void){
	lcd_update = true;
}



void tik_ISR(void){
	if(mode_in == 1){
		t_consigne_f = t_consigne.read() - 0.5;
		t_mesure_f = t_mesure.read() - 0.5;
		mesure_out.write(t_mesure_f + 0.5);
		t_erreur_f = t_consigne_f - t_mesure_f;

		/* Update Analog outputs and PWM outputs */
		if(t_erreur_f >= 0){    
			comp_erreur.write(t_erreur_f); 
			led_signe = 0; 
			moteur_1.write(K_GAIN*t_erreur_f);  
			//moteur_2.write(0); 
		}
		else{    
			comp_erreur.write(-t_erreur_f); 
			led_signe = 1; 
			moteur_1.write(0);  
			//moteur_2.write(-K_GAIN*t_erreur_f);   
		}
	}
	else{
		// Following mode
		t_consigne_f = t_consigne.read();
		comp_erreur.write(t_consigne_f);
		t_mesure_f = t_mesure.read();			
		mesure_out.write(t_mesure_f);
		moteur_1.write(t_consigne_f);  
		//moteur_2.write(t_consigne_f);
	}
	lcd_refresh_cnt++;
}

void lcd_refresh_consigne(void){
	printf("OK ");
	sprintf(lcd_disp, "#######");
	my_lcd.set_position(40, 40);	
	my_lcd.draw_string(lcd_disp, SSD1306_BLACK, LARGE);
	t_consigne_f_new = t_consigne_f;
	sprintf(lcd_disp, "%0.2lf", t_consigne_f_new);
	my_lcd.set_position(40, 40);	
	my_lcd.draw_string(lcd_disp, SSD1306_WHITE, LARGE);
	t_consigne_f_old = t_consigne_f_new;
	my_lcd.display();	
}

int main()
{
    printf("Test REGUL - signe erreur + PWM + OLED  %.1lf\r\n", 1.4);

    moteur_1.period_ms(10);
    //moteur_2.period_ms(10);
    moteur_1.write(0.0);
    //moteur_2.write(0.5);
	
    my_lcd.init();
		my_lcd.clear_screen();
    thread_sleep_for(200);
	
    tik.attach(&tik_ISR, 100us);
    led1 = 1;
	
		mode_in.rise(&mode_detect);
		mode_in.fall(&mode_detect);
	
    while (true)
    {
			if(lcd_refresh_cnt >= LCD_REFRESH){
				lcd_refresh_consigne();
				t_consigne_f_old = t_consigne_f;
				lcd_refresh_cnt = 0;
			}
			if(lcd_update){
				my_lcd.clear_screen();
				my_lcd.set_position(30, 30);	
				sprintf(lcd_disp, "Consigne");				
				my_lcd.draw_string(lcd_disp, SSD1306_WHITE, NORMAL);
				/*
				my_lcd.set_position(20, 50);	
				sprintf(lcd_disp, "%0.2lf", t_consigne_f);
				my_lcd.draw_string(lcd_disp, SSD1306_WHITE, LARGE);
				*/
				if(mode_in == 1){
					my_lcd.set_position(10, 15);					
					my_lcd.draw_string("Mode", SSD1306_WHITE, NORMAL);
					my_lcd.set_position(10, 1);	
					my_lcd.draw_string("REGULATION", SSD1306_WHITE, LARGE);
				}
				else{
					my_lcd.set_position(10, 15);					
					my_lcd.draw_string("Mode", SSD1306_WHITE, NORMAL);
					my_lcd.set_position(10, 1);	
					my_lcd.draw_string("SUIVEUR N.", SSD1306_WHITE, LARGE);
				}
				my_lcd.display();
				lcd_update = false;
			}
      thread_sleep_for(WAIT_TIME_MS);
    }
}
