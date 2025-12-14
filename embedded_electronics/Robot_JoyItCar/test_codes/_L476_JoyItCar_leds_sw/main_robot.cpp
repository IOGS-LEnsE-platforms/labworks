/*  
 *  Main C++ file for Robot Joy-It Car @ LEnsE
 *
 *****************************************************************
 *  Tested with Nucleo L476RG board / Mbed OS 6.17
 *****************************************************************
 *  Author : J. VILLEMEJANE / LEnsE - Creation 2025/12/14
 *****************************************************************
 *  LEnsE / https://lense.institutoptique.fr/
 *      Based on Mbed OS 6 example : mbed-os-example-blinky-baremetal
 */
 
#include "main_robot.h"
 
// Inputs / Outputs
DigitalOut  	led1(PC_7);
DigitalOut  	led2(PB_13);

InterruptIn		sw1(PA_11);
InterruptIn		sw2(PA_12);
InterruptIn		userB(PC_13);

// HeadLights
WS2812  my_strip1(PC_0, STRIP_SIZE, WS2812_STD);	// Head Light 1
/*
WS2812  my_strip2(PA_10, STRIP_SIZE, WS2812_STD); // Head Light 2
WS2812  my_strip3(PC_5, STRIP_SIZE, WS2812_STD); // Head Light 3
WS2812  my_strip4(PA_13, STRIP_SIZE, WS2812_STD); // Head Light 4
PixelArray my_leds1(STRIP_SIZE, WS2812_STD);
PixelArray my_leds2(STRIP_SIZE, WS2812_STD);
PixelArray my_leds3(STRIP_SIZE, WS2812_STD);
PixelArray my_leds4(STRIP_SIZE, WS2812_STD);
*/

// Motors
PwmOut 				motor_R1(PA_0);
PwmOut 				motor_R2(PA_1);
PwmOut 				motor_L1(PB_4);
PwmOut 				motor_L2(PA_8);
DigitalOut		motor_en(PA_9);	