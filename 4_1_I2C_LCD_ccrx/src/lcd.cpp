/*
 * lcd.cpp
 *
 *  Created on: 2023/02/02
 *      Author: Yukiho
 */

#include "lcd.h"

static volatile unsigned char lcd_buff[16];

	int LCD_initialize(void)
{
	int ret;

	ret = 0;
	delay(200);
	WriteCMD_I2C_LCD(0x38);	//Function set
	delay(200);
	WriteCMD_I2C_LCD(0x38);	//Function set
	delay(1);
	WriteCMD_I2C_LCD(0x39);	//Function set
	delay(1);
	WriteCMD_I2C_LCD(0x04);	//Set cursor move direction
	delay(1);
	WriteCMD_I2C_LCD(0x14);	//Internal OSC frequency
	delay(1);
	WriteCMD_I2C_LCD(0x70);	//Contrast set(LSB)
	delay(1);
	WriteCMD_I2C_LCD(0x56);	//Power/Icon/contrast set
	delay(1);
	WriteCMD_I2C_LCD(0x6C);	//Follower control
	delay(200);
	WriteCMD_I2C_LCD(0x38);	//Function set
	delay(1);
	WriteCMD_I2C_LCD(0x0C);	//Display ON/OFF control
	delay(1);
	WriteCMD_I2C_LCD(0x01);	//Clear displays
	delay(1);
	return( ret );
}


int LCD_print(int line, int pos, char *buff, unsigned num)
{
	int ret;

	lcd_buff[0] = 0;	//Co = 0(Last control byte),RS = 0(Control register)
	lcd_buff[1] = 0x80 + line * 0x40 + pos;	//set DDRAM address
	R_Config_RIIC0_Master_Send(AQM0802_ADDRESS, (uint8_t *)lcd_buff, 2);
	delay(1);

	WriteDATA_I2C_LCD((unsigned char *)buff, num);
	return( ret );
}


static int WriteCMD_I2C_LCD(unsigned char cmd)
{
	int ret;

	ret = 0;
	lcd_buff[0] = 0;	//Co = 0(Last control byte),RS = 0(Control register)
	lcd_buff[1] = cmd;
	R_Config_RIIC0_Master_Send(AQM0802_ADDRESS, (uint8_t *)lcd_buff, 2);
	delay(1);
	return( ret );
}


static int WriteDATA_I2C_LCD(unsigned char *buff, unsigned char num)
{
	int ret;
	int i;

	lcd_buff[0] = 0x40;	//Co = 0, RS = 1

	for(i=0;i<num;i++){
		lcd_buff[i+1] = buff[i];
	}
	R_Config_RIIC0_Master_Send(AQM0802_ADDRESS, (uint8_t *)lcd_buff, num+1);
	delay(1);

	return( ret );
}
