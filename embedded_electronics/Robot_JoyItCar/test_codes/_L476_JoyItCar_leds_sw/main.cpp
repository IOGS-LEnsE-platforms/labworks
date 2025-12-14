/*  
 *  Structure of a main file for embedded project @ LEnsE
 *****************************************************************
 *			Joy-It car robot / LEDs and Switches test
 *****************************************************************
 *  Tested with Nucleo L476RG board / Mbed OS 6.17
 *****************************************************************
 *  ProTIS / https://lense.institutoptique.fr/
 *      Based on Mbed OS 6 example : mbed-os-example-blinky-baremetal
 */

#include "mbed.h"
#include "main_robot.h"

#include "leds_sw_test.h"
 
DigitalOut led_ld2(LED1);


int main()
{
  printf("\tLEnsE - L476RG  v%lf\n", 1.0);
  printf("\tTest 2\n");
		
	test_switch_leds_init();
	
	while (true)
	{
		led_ld2 = !led_ld2;
		//test_switch_leds_loop();
		thread_sleep_for(300);	// 300 ms
	}
}
