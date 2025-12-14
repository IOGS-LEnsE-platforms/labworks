
#include "main_robot.h"
#include "leds_sw_test.h"

void sw1_ISR_LED_test(void){
	led1 = !led1;
}


void sw2_ISR_LED_test(void){
	led2 = !led2;
}


void test_switch_leds_init(void){
  printf("\tJoy-It / LED and SW test\n");
	sw1.rise(&sw1_ISR_LED_test);
	sw2.rise(&sw2_ISR_LED_test);
}

void test_switch_leds_loop(void){
	
}
	