/*
 * util.cpp
 *
 *  Created on: 2023/02/01
 *      Author: Yukiho
 */

extern "C" {
#include "r_smc_entry.h"
}
#include "util.h"

//CMT11
void delay(int ms)
{
	CMT0.CMCNT = 0;
	IR(CMT0, CMI0) = 0;
	R_Config_CMT0_Start();

	while(ms >= 0){
		while(IR(CMT0, CMI0) == 0);
		ms--;
		IR(CMT0, CMI0) = 0;
	}
	R_Config_CMT0_Stop();
}


