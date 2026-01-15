/***********************************************************************
*
*  FILE        : 5_1_UART_PC_ccrx.cpp
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
#include "util.h"

#define SW1 PORTE.PIDR.BIT.B5
#define SW2 PORT5.PIDR.BIT.B5
#define LED_B PORTA.PODR.BIT.B5
#define LED_G PORTA.PODR.BIT.B2
#define LED_R PORTA.PODR.BIT.B1
#define SW_ON 0
#define SW_OFF 1
#define LED_ON 1
#define LED_OFF 0

void main(void);

char msg_buff[20], rcv_buff[2];
int rcv_flag;
int tend_flag = 1;
int err_flag;

void main(void)
{
	R_Config_SCI1_Start();
	sprintf((char *)msg_buff, "System is Starting\r\n");
	R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 20);
	R_Config_SCI1_Serial_Receive((uint8_t *)rcv_buff, 1);
	while(1){
		if(rcv_flag == 1){
			switch(rcv_buff[0]){
			case '0':
				while(tend_flag == 0);
				tend_flag = 0;
				sprintf((char *)msg_buff, "Hit keyboard 0\r\n");
				R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 16);
				break;
			case '1':
				sprintf((char *)msg_buff, "Hit keyboard 1\r\n");
				R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 16);
				break;
			default:
				while(tend_flag == 0);
				tend_flag = 0;
				sprintf((char *)msg_buff, "Hit other key\r\n");
				R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 15);
				break;
			}
			rcv_flag = 0;
			R_Config_SCI1_Serial_Receive((uint8_t *)rcv_buff, 1);
		}
		if(SW1 == SW_ON){
			while(tend_flag == 0);
			tend_flag = 0;
			sprintf((char *)msg_buff, "SW1=ON\r\n");
			R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 8);
			while(SW1 == SW_ON);
			while(tend_flag == 0);
			tend_flag = 0;
			sprintf((char *)msg_buff, "SW1=OFF\r\n");
			R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 9);
		}
		if(SW2 == SW_ON){
			while(tend_flag == 0);
			tend_flag = 0;
			sprintf((char *)msg_buff, "SW2=ON\r\n");
			R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 8);
			while(SW2 == SW_ON);
			while(tend_flag == 0);
			tend_flag = 0;
			sprintf((char *)msg_buff, "SW2=OFF\r\n");
			R_Config_SCI1_Serial_Send((uint8_t *)msg_buff, 9);
		}
	}
}

#ifdef __cplusplus
void abort(void)
{

}
#endif

/*
CPUボード
USB	P30	RXD1
	P26	TXD1

CAN	P15	CRXD0
	P14	CTXD0

S1	PH2	MTIOC4C/TMRI0
S2	PH1	MTIOC3D/TMO0
D1	P32	MTIOC0C/TMO3
D2	PB5	MTIOC2A/MTIOC1B/TMRI1/POE1#

IOボード
I2C		SCL	P16	TXD1/SMOSI1/SSDA1/MOSIA/SCL0
		SDA	P17	SCK1/MISOA/SDA0
		AREF
		GND
SPI		D13	PC5	MTIOC0C/MTIOC3B/MTCLKD/TMRI2/SCK8/RSPCKA
		D12	PC7	MTIOC3A/MTCLKB/TMO2/LPTO/TXD8/SMOSI/SSDA8/MISOA
		D11	PC6	MTIOC3C/MTCLKA/TMCI2/RXD8/SMISO8/SSCL8/MOSIA
		D10	PC4	MTIOC0A/MTIOC3D/MTCLKC/TMCI1/POE0#/SCK5/CTS8#/RTS8#/SS8#/SSLA0
Servo	D9~	PC2	MTIOC4B/RXD5/SMISO5/SSCL5/SSLA3
		D8	PC3	MTIOC4D/TXD5/SMOSI5/SSDA5

SP		D7	PA1	MTIOC0B/MTIOC3B/MTCLKC/SCK5/SSLA2
			PB6/PC0	MTIOC3D
LED_R	D6~	PA3	MTIOC0D/MTIOC4D/MTIC5V/MTCLKD/RXD5/SMISO5/SSCL5/IRQ6/CMPB1
			PB3	MTIOC0A/MTIOC4A/TMO0/ POE3#/LPTO
LED_G	D5~	PA4	MTIOC4C/MTIC5U/MTCLKA/TMRI0/TXD5/SMOSI5/SSDA5/SSLA0/IRQ5/CVREFB1
SW2		D4	P55	MTIOC4A/MTIOC4D/TMO3/CRXD0
LED_B	D3~	PA0	MTIOC4A/SSLA1/CACREF
SW1		D2	PE5	MTIOC4C/MTIOC2B/IRQ5/AN021/CMPOB0
			PB1	MTIOC0C/MTIOC4C/ TMCI0
		D1	PE1	MTIOC4C/TXD12/TXDX12/SIOX12/SMOSI12/SSDA12/AN017/CMPB0
		D0	PE2	MTIOC4A/RXD12/RXDX12/SMISO12/SSCL12/IRQ7/AN018/CVREFB0


A0	P40	AN000
A1	P41	AN001
A2	P42	AN002
A3	P43	AN003
A4	P44	AN004
A5	P45	AN005

 */

