/*
 * lcd.h
 *
 *  Created on: 2023/02/02
 *      Author: Yukiho
 */

#ifndef LCD_H_
#define LCD_H_
extern "C"{
#include "r_smc_entry.h"
}
#include "util.h"

#define AQM0802_ADDRESS	(0x3E)	//7bit

int LCD_initialize(void);
int LCD_print(int line, int pos, char *buff, unsigned num);
static int WriteCMD_I2C_LCD(unsigned char cmd);
static int WriteDATA_I2C_LCD(unsigned char *buff, unsigned char num);

#endif /* LCD_H_ */
