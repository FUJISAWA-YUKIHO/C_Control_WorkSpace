/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_PORT.c
* Component Version: 2.4.1
* Device(s)        : R5F51403AxFM
* Description      : This file implements device driver for Config_PORT.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_PORT_Create(void)
{
    /* Set PORT3 registers */
    PORT3.PODR.BYTE = _00_Pm2_OUTPUT_0;
    PORT3.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm2_CMOS_OUTPUT;
    PORT3.ODR1.BYTE = _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORT3.PMR.BYTE = _00_Pm2_PIN_GPIO;
    PORT3.PDR.BYTE = _04_Pm2_MODE_OUTPUT | _18_PDR3_DEFAULT;

    /* Set PORTB registers */
    PORTB.PODR.BYTE = _00_Pm5_OUTPUT_0;
    PORTB.ODR0.BYTE = _00_Pm0_CMOS_OUTPUT | _00_Pm1_CMOS_OUTPUT | _00_Pm3_CMOS_OUTPUT;
    PORTB.ODR1.BYTE = _00_Pm5_CMOS_OUTPUT | _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORTB.PMR.BYTE = _00_Pm5_PIN_GPIO;
    PORTB.PDR.BYTE = _20_Pm5_MODE_OUTPUT | _14_PDRB_DEFAULT;

    /* Set PORTH registers */
    PORTH.PCR.BYTE = _02_Pm1_PULLUP_ON | _04_Pm2_PULLUP_ON;
    PORTH.PMR.BYTE = _00_Pm1_PIN_GPIO | _00_Pm2_PIN_GPIO;
    PORTH.PDR.BYTE = _00_Pm1_MODE_INPUT | _00_Pm2_MODE_INPUT | _F0_PDRH_DEFAULT;

    R_Config_PORT_Create_UserInit();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
