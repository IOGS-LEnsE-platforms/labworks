/*  
 *  Structure of a main file for embedded project @ LEnsE
 *****************************************************************
 *  Tested with Nucleo L476RG board / Mbed OS 6
 *****************************************************************
 *  ProTIS / https://lense.institutoptique.fr/
 *      Based on Mbed OS 6 example : mbed-os-example-blinky-baremetal
 */

#include "mbed.h"
#define INCR	0.1
 
PwmOut	led1(PC_7);
PwmOut	led2(PB_13);
DigitalOut led_ld2(LED1);

/*
InterruptIn		sw1(PA_11);
InterruptIn		sw2(PA_12);
*/
InterruptIn		user_b(PC_13);

AnalogIn 		pot(PC_3);

InterruptIn		lineL(PA_7);
InterruptIn		lineC(PB_6);
InterruptIn		lineR(PB_12);

Ticker 	tik;

float 	rc_led1 = 0.5;
float 	rc_led2 = 0.5;



void sw1_ISR(void){
	if(rc_led1 < 1){ rc_led1 += INCR; }
	else{ rc_led1 = 1; }
	led1.write(rc_led1);
}

void sw2_ISR(void){
	if(rc_led1 > 0){ rc_led1 -= INCR; }
	else{ rc_led1 = 0; }
	led1.write(rc_led1);
}

void tik_ISR(void){
	led_ld2 = !led_ld2;
}

int main()
{
  printf("\tLEnsE - L476RG  v%lf\n", 1.0);
	
	led1.period_ms(10);
	led2.period_ms(10);
	led1.write(rc_led1);
	led2.write(rc_led2);
	
	/*
	sw1.rise(&sw1_ISR);
	sw2.rise(&sw2_ISR);
	*/
	
	tik.attach(&tik_ISR, 0.2);

	while (true)
	{
		rc_led2 = pot;
		led2.write(rc_led2);
		printf("L= %d | C = %d | R = %d \n", lineL.read(), lineC.read(), lineR.read());
	}
}
