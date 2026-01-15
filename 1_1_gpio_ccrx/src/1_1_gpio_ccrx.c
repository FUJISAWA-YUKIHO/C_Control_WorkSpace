/***********************************************************************
*
*  FILE        : 1_gpio_ccrx.c
*  DATE        : 2023-01-31
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"

#include "common.h"
#include "cpu_board.h"
#include "io_board.h"

void main(void);

void main(void)
{
	while(1){
		LED_R = ~SW1;
		LED_G = ~SW2;
	}
}

