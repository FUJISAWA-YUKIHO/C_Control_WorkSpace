/*
 * cpu_board.h
 *
 *  Created on: 2025/10/22
 *      Author: Yukiho
 */

#ifndef CPU_BOARD_H_
#define CPU_BOARD_H_

#define S1 PORTH.PIDR.BIT.B2
#define S2 PORTH.PIDR.BIT.B1
#define D2 PORT3.PODR.BIT.B2
#define D1 PORTB.PODR.BIT.B5

#endif /* CPU_BOARD_H_ */
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

 */
