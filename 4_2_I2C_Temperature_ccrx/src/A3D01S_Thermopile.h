/*
 * A3D01S_Thermopile.h
 *
 *  Created on: 2023/02/02
 *      Author: Yukiho
 */


#ifndef A3D01S_THERMOPILE_H_
#define A3D01S_THERMOPILE_H_

extern "C" {
#include "r_smc_entry.h"
}

#define A3D01S_ADRESS 0x3D	//7bit address

int A3D01S_initialize(void);
int get_ThermoData(unsigned char *buff);



#endif /* A3D01S_THERMOPILE_H_ */
