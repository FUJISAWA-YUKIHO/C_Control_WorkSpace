/***********************************************************************
*
*  FILE        : 4_1_I2C_LCD_ccrx.cpp
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

#include "lcd.h"

char msg[9] = {"        "};

void main(void);

void main(void)
{
	int n = 0;

	R_Config_RIIC0_Start();


	LCD_initialize();
	LCD_print(0, 0, "01234567", 8);
	delay(100);
	LCD_print(1, 0, "abcdefgh", 8);
	delay(100);

	while(1){
		delay(1000);
		sprintf(msg, "%d",n);
		LCD_print(0, 0, msg, 8);
		n++;
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
