/***********************************************************************
*
*  FILE        : 4_3_I2C_ColorSensor_ccrx.cpp
*  DATE        : 2023-02-06
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
#include "S13683_FullColorSensor.h"
#include "util.h"

unsigned char color[8];
volatile int red, green, blue;

void main(void);

void main(void)
{
	R_Config_CMT0_Start();
	R_Config_RIIC0_Start();

	S13683_initialize();

	while(1){
		get_colorData((uint8_t *)color);

		delay(10);
		red = ((int)color[0]<<8) + color[1];
		green = ((int)color[2]<<8) + color[3];
		blue = ((int)color[4]<<8) + color[5];

		delay(1000);
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
