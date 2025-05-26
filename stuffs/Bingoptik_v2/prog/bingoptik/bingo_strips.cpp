#include "bingo_strips.h"


int smooth_rgb(int k){
	int 	k_new = k % (MAX_COLORS / REPEAT_COLORS);
	int 	r_new = (k_new * RED_INC) % 256;
	int 	b_new = (k_new * BLUE_INC) % 256;
	int 	g_new = (k_new * GREEN_INC) % 256;
	int 	rgb = (g_new << 16) + (r_new << 8) + b_new;
	return rgb;
}