/***********************************************************************
*
*  FILE        : 4_1_I2C_Temperature_ccrx.cpp
*  DATE        : 2023-02-02
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#ifdef __cplusplus
//#include <ios>                        // Remove the comment when you use ios
//_SINT ios_base::Init::init_cnt;       // Remove the comment when you use ios
extern "C" {
#endif
#include "r_smc_entry.h"

#ifdef __cplusplus
void abort(void);
}
#endif
#include "A3D01S_Thermopile.h"
#include "util.h"

unsigned char temperature[6];
float temp_a, temp_o;

void main(void);

void main(void)
{
	R_Config_RIIC0_Start();

	while(1){
		get_ThermoData(&temperature[0]);
		temp_a = (float)(temperature[0] | (temperature[1]<<8)) * 0.125 -20.0;
		temp_o = (float)(temperature[3] | (temperature[4]<<8)) * 0.125 -30.0;

		delay(1000);
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
