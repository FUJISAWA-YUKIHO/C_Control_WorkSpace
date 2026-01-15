/*
 * S13683_FullColorSensor.h
 *
 *  Created on: 2023/02/06
 *      Author: Yukiho
 */

extern "C"{
#include "r_smc_entry.h"
}
#define S13683_ADRESS 0x2A	//7bit address

int S13683_initialize(void);
int get_colorData(unsigned char *buff);




