/*
 * A3D01S_Thermopile.cpp
 *
 *  Created on: 2023/02/02
 *      Author: Yukiho
 */

#include "A3D01S_Thermopile.h"
#include "util.h"

unsigned char thp_buff[8];

int A3D01S_initialize(void)
{
	int ret = 0;

	return ret;
}


int get_ThermoData(unsigned char *buff)
{
	int ret = 0;


	thp_buff[0] = 0x70;	// register
	R_Config_RIIC0_Master_Send_Without_Stop(A3D01S_ADRESS, thp_buff, 1);
	delay(1);

	R_Config_RIIC0_Master_Receive(A3D01S_ADRESS, buff, 3);
	delay(1);

	thp_buff[0] = 0x71;	// register
	R_Config_RIIC0_Master_Send_Without_Stop(A3D01S_ADRESS, thp_buff, 1);
	delay(1);

	R_Config_RIIC0_Master_Receive(A3D01S_ADRESS, &buff[3], 3);
	delay(1);

	return ret;
}

