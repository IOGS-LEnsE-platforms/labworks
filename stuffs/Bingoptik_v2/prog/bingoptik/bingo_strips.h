/* BingOptik project / demo
 *		Developed by LEnsE / Institut d'Optique
 *		lense.institutoptique.fr
 *********************************************************
 *		Author : Julien VILLEMEJANE - 26/may/2025
 *********************************************************
 *		Header file containing strip colors declaration
 */

#ifndef     __BINGO_H_HEADER_H__
#define     __BINGO_H_HEADER_H__

#include "mbed.h"

#define     STRIP_SIZE_MIRROR      110
#define     STRIP_SIZE_BOBINE      10

#define			COLOR_VARIATION					60

#define		SPEED_MAX 	1000		// * 100us


/* Sine Wave */
const uint8_t sine_table[STRIP_SIZE_MIRROR] = {
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,  
	50,  60,
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,  
	50,  60,	
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,  
	50,  60,		
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,  
	50,  60,	
	90, 115, 150, 200, 255, 200, 150, 115,  90,  60,
  50, 	30,  10,   5,   5,   5,   5,   5,  10,  30,  
	50,  60
};

const 	float	 R_val[6] = {1.0, 0.0, 0.1, 0, 0.7, 0.8};
const 	float	 G_val[6] = {0.0, 0.6, 0.4, 0, 0, 0.6};
const 	float	 B_val[6] = {0.0, 0, 0.5, 1.0, 0.7, 0};

/*
Rouge (#FF0000)
Jaune-vert (#AFFF00)
Cyan (#00FFFF)
Bleu (#0033FF)
Magenta (#FF00FF)
Orange (#FF9900)
*/

const float R_trans[COLOR_VARIATION] = {
	1.0, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1,
	0.1, 0.1, 0.07,0.06,0.04,0.02,0.0, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
	0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0
};

const float G_trans[COLOR_VARIATION] = {
	0.0, 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.65, 0.8, 0.9,
	0.9, 0.9, 0.8, 0.8, 0.75,0.75,0.74,0.72,0.71, 0.7,
	0.7, 0.6, 0.5, 0.4, 0.4, 0.3, 0.3, 0.2, 0.2, 0.2, 
	0.2, 0.2,0.15,0.13,0.08, 0.06, 0.02, 0.0, 0.0, 0.0,
	0.0, 0.0, 0.1, 0.1, 0.2, 0.3, 0.4, 0.5, 0.5, 0.6,
	0.6, 0.6, 0.5, 0.4, 0.3, 0.2, 0.2, 0.1, 0.0, 0.0
};


const float B_trans[COLOR_VARIATION] = {
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
	0.0, 0.1, 0.1, 0.2, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
	0.7, 0.7, 0.7, 0.8, 0.8, 0.8, 0.9, 0.9, 0.9, 1.0, 
	1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
	1.0, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.1, 0.0,
	0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};



#define		MAX_COLORS 	100
#define		REPEAT_COLORS 	4
#define		RED_INC 		5
#define		GREEN_INC 	7
#define		BLUE_INC 		2


#define		BLUE_C			0x2222FF
#define		BLUE_CL			0x000055
#define		BLUE_CL2		0x000033
#define		BLUE_CL3		0x000011
#define		VIOLET_C		0x00AAAA
#define		VIOLET_CL		0x004444
#define		VIOLET_CL2	0x002222
#define		VIOLET_CL3	0x001111
#define		YELLOW_C		0xAAAA00
#define		YELLOW_CL		0x444400
#define		YELLOW_CL2	0x222200
#define		YELLOW_CL3	0x111100
#define		RED_C				0x50885B
#define		RED_CL			0x20442B
#define		RED_CL2			0x102215
#define		RED_CL3			0x091108
#define		GREEN_C			0xFF0000
#define		GREEN_CL		0x550000
#define		GREEN_CL2		0x330000
#define		GREEN_CL3		0x110000
#define		PINK_C			0x50885B
#define		ORANGE_C		0x75AA00
#define		ORANGE_CL		0x406600
#define		ORANGE_CL2	0x203300
#define		ORANGE_CL3	0x0A1100

enum Mode {
  SMOOTH,
  INTENSITY,
  BINGO
};


#define SIZE 150  // doit �tre un multiple de 6

const uint32_t blue[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL, 	BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,
    BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL, 	BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,
    BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL, 	BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,
    BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL, 	BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,
    BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL, 	BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL,  BLUE_C,GREEN_CL,0,0,0,YELLOW_CL
};

const uint32_t blue_low[SIZE] = {
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL,  	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 	BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL, 
    BLUE_C,YELLOW_CL,VIOLET_CL2,ORANGE_CL3,RED_CL2,GREEN_CL
};

const uint32_t yellow[SIZE] = {
    BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,
    BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,
    BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,
    BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,
    BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0,  BLUE_CL,YELLOW_C,VIOLET_CL,0,0,0
};

const uint32_t yellow_low[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,  	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2, 	BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2,
    BLUE_CL,YELLOW_C,VIOLET_CL,ORANGE_CL2,RED_CL3,GREEN_CL2
};

const uint32_t violet[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,
    0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,
    0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,
    0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,
    0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0,  0,YELLOW_CL,VIOLET_C,ORANGE_CL,0,0
};

const uint32_t violet_low[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,  	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3, 	BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3,
    BLUE_CL2,YELLOW_CL,VIOLET_C,ORANGE_CL,RED_CL2,GREEN_CL3
};

const uint32_t orange[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    0,0,VIOLET_CL,ORANGE_C,RED_CL,0,  0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0, 	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,
    0,0,VIOLET_CL,ORANGE_C,RED_CL,0,  0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0, 	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,
    0,0,VIOLET_CL,ORANGE_C,RED_CL,0,  0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0, 	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,
    0,0,VIOLET_CL,ORANGE_C,RED_CL,0,  0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0, 	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,
    0,0,VIOLET_CL,ORANGE_C,RED_CL,0,  0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0,	0,0,VIOLET_CL,ORANGE_C,RED_CL,0, 	0,0,VIOLET_CL,ORANGE_C,RED_CL,0
};

const uint32_t orange_low[SIZE] = {    
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,  	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2, 	BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2,
    BLUE_CL3,YELLOW_CL2,VIOLET_CL,ORANGE_C,RED_CL,GREEN_CL2
};

const uint32_t red[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    0,0,0,ORANGE_CL,RED_C,GREEN_CL,  0,0,0,ORANGE_CL,RED_C,GREEN_CL,	0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,
    0,0,0,ORANGE_CL,RED_C,GREEN_CL,  0,0,0,ORANGE_CL,RED_C,GREEN_CL,	0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,
    0,0,0,ORANGE_CL,RED_C,GREEN_CL,  0,0,0,ORANGE_CL,RED_C,GREEN_CL,	0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,
    0,0,0,ORANGE_CL,RED_C,GREEN_CL,  0,0,0,ORANGE_CL,RED_C,GREEN_CL,	0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,
    0,0,0,ORANGE_CL,RED_C,GREEN_CL,  0,0,0,ORANGE_CL,RED_C,GREEN_CL,	0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL,		0,0,0,ORANGE_CL,RED_C,GREEN_CL
};

const uint32_t red_low[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,  	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL, 	BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL,
    BLUE_CL2,YELLOW_CL3,VIOLET_CL2,ORANGE_CL,RED_C,GREEN_CL
};

const uint32_t green[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    BLUE_CL,0,0,0,RED_CL,GREEN_C,  BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,
    BLUE_CL,0,0,0,RED_CL,GREEN_C,  BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,
    BLUE_CL,0,0,0,RED_CL,GREEN_C,  BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,
    BLUE_CL,0,0,0,RED_CL,GREEN_C,  BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,
    BLUE_CL,0,0,0,RED_CL,GREEN_C,  BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C,	BLUE_CL,0,0,0,RED_CL,GREEN_C
};

const uint32_t green_low[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,  	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C, 	BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C,
    BLUE_CL,YELLOW_CL2,VIOLET_CL3,ORANGE_CL2,RED_CL,GREEN_C
};

/* Return a GRB integer from a k-value */
int smooth_rgb(int k);



#endif