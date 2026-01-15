/*
 * S13683_FullColorSensor.cpp
 *
 *  Created on: 2023/02/06
 *      Author: Yukiho
 */

#include "S13683_FullColorSensor.h"
#include "util.h"


static volatile unsigned char fcs_buff[8];

int S13683_initialize(void)
{
	int ret = 0;

	fcs_buff[0] = 0;	//Control register
	fcs_buff[1] = 0x89;	//
	R_Config_RIIC0_Master_Send(S13683_ADRESS, (uint8_t *)fcs_buff, 2);
	delay(1);

	fcs_buff[0] = 0;	//Control register
	fcs_buff[1] = 0x09;	//
	R_Config_RIIC0_Master_Send(S13683_ADRESS, (uint8_t *)fcs_buff, 2);
	delay(1);

	return ret;
}


int get_colorData(unsigned char *buff)
{
	int ret = 0;

	fcs_buff[0] = 3;	//Control register
	R_Config_RIIC0_Master_Send_Without_Stop(S13683_ADRESS, (uint8_t *)fcs_buff, 1);
	delay(1);

	R_Config_RIIC0_Master_Receive(S13683_ADRESS, (uint8_t *)buff, 8);
	delay(1);

	return ret;
}
