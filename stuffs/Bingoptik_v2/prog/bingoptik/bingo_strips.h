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

#define		MAX_COLORS 	100
#define		REPEAT_COLORS 	4
#define		RED_INC 		5
#define		GREEN_INC 	7
#define		BLUE_INC 		2


#define		BLUE_C			0x0000FF
#define		VIOLET_C		0x00AAAA
#define		YELLOW_C		0xAAAA00
#define		RED_C				0x00FF00

enum Mode {
  SMOOTH,
  INTENSITY,
  BINGO
};


#define SIZE 150  // doit être un multiple de 6

const int violet[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,
    0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,
    0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,
    0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,
    0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0,  0,VIOLET_C,0,0,0,0
};

const int blue[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,
    BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,
    BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,
    BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,
    BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0,  BLUE_C,0,0,0,0,0
};

const int yellow[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,
    0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,
    0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,
    0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,
    0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0,  0,0,YELLOW_C,0,0,0
};

const int red[SIZE] = {
    // 25 blocs de 6 valeurs = 150
    0,0,0,RED_C,0,0,  0,0,0,RED_C,0,0, 	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,
    0,0,0,RED_C,0,0,  0,0,0,RED_C,0,0, 	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,
    0,0,0,RED_C,0,0,  0,0,0,RED_C,0,0, 	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,
    0,0,0,RED_C,0,0,  0,0,0,RED_C,0,0, 	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,
    0,0,0,RED_C,0,0,  0,0,0,RED_C,0,0, 	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0,	0,0,0,RED_C,0,0
};

/* Return a GRB integer from a k-value */
int smooth_rgb(int k);

#endif