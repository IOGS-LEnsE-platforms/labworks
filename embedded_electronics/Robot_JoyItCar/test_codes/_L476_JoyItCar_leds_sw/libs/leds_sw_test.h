/*  
 *  LEDs and SW test Header file for Robot Joy-It Car @ LEnsE
 *      Specific functions for LED and switch test.
 *****************************************************************
 *  Tested with Nucleo L476RG board / Mbed OS 6.17
 *****************************************************************
 *  Author : J. VILLEMEJANE / LEnsE - Creation 2025/12/14
 *****************************************************************
 *  LEnsE / https://lense.institutoptique.fr/
 *      Based on Mbed OS 6 example : mbed-os-example-blinky-baremetal
 */
 
#ifndef __LEDS_SW_TEST__
#define __LEDS_SW_TEST__	

void sw1_ISR_LED_test(void);

void sw2_ISR_LED_test(void);

void test_switch_leds_init(void);

void test_switch_leds_loop(void);

#endif