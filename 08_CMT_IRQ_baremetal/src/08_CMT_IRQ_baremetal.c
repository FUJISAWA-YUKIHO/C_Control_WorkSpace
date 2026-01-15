/***********************************************************************/
/*                                                                     */
/*  FILE        : Main.c                                   */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
//#include "typedefine.h"
#ifdef __cplusplus
//#include <ios>                        // Remove the comment when you use ios
//_SINT ios_base::Init::init_cnt;       // Remove the comment when you use ios
#endif
#include "iodefine.h"


#define S1 PORTH.PIDR.BIT.B2
#define S2 PORTH.PIDR.BIT.B1
#define D2 PORT3.PODR.BIT.B2
#define D1 PORTB.PODR.BIT.B5

#define ICLK 48000000
#define PCLKB 24000000

void main(void);
#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

void main(void)
{
	SYSTEM.PRCR.WORD = 0xA501;
	SYSTEM.SCKCR3.BIT.CKSEL = 1;
	SYSTEM.SCKCR.BIT.ICK = 0;
	SYSTEM.SCKCR.BIT.PCKB = 1;

	PORTH.PCR.BYTE = 0x06;
	PORT3.PDR.BIT.B2 = 1;
	PORTB.PDR.BIT.B5 = 1;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;
	CMT0.CMCR.BIT.CMIE = 1;
	CMT0.CMCR.BIT.CKS = 3;			//1/512PCLK
	CMT0.CMCOR = PCLKB / 512 - 1;	//1sec

	ICU.IR[28].BIT.IR = 0;			//clear CMI IRQ flag
	ICU.IPR[004].BIT.IPR = 15;		//
	ICU.IER[03].BIT.IEN4 = 1;

	CMT.CMSTR0.BIT.STR0 = 1;		//Start CMT0 count
	while(1){
	}
}

// CMT0 CMI0
#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

void Excep_CMT0_CMI0(void){
	D1 ^= 1;
	D2 ^= 1;
}

#ifdef __cplusplus
void abort(void)
{

}
#endif
