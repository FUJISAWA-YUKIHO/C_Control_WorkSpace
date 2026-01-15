/*
* Copyright (c) 2016 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : Config_MTU3_MTU4.c
* Component Version: 1.11.0
* Device(s)        : R5F51403AxFM
* Description      : This file implements device driver for Config_MTU3_MTU4.
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
#include "Config_MTU3_MTU4.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU3_MTU4_Create
* Description  : This function initializes the MTU3 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU3_MTU4_Create(void)
{
    /* Release MTU channel 3 from stop state */
    MSTP(MTU3) = 0U;

    /* Enable read/write to MTU3, MTU4 registers */
    MTU.TRWER.BIT.RWE = 1U;

    /* Stop MTU channel 3 counter */
    MTU.TSTR.BIT.CST3 = 0U;
    MTU.TSTR.BIT.CST4 = 0U;

    /* MTU channel 3 is used as complementary PWM mode 3 */
    MTU3.TIER.BYTE = 0x00U;
    MTU4.TIER.BYTE = 0x00U;
    MTU.TITCR.BIT.T3AEN = 0U;
    MTU.TITCR.BIT.T4VEN = 0U;
    MTU3.TCR.BYTE = _04_MTU_PCLK_256 | _00_MTU_CKEG_RISE | _00_MTU_CKCL_DIS;
    MTU4.TCR.BYTE = _04_MTU_PCLK_256 | _00_MTU_CKEG_RISE;
    MTU.TGCR.BYTE = _80_MTU_BDC_OUT;
    MTU3.TCNT = _000A_3TCNT_VALUE;
    MTU4.TCNT = 0x0000U;
    MTU.TSYR.BIT.SYNC3 = 0U;
    MTU.TSYR.BIT.SYNC4 = 0U;
    MTU3.TGRB = _0001_3TGRB_VALUE;
    MTU3.TGRD = _0001_3TGRB_VALUE;
    MTU4.TGRA = _0064_4TGRA_VALUE;
    MTU4.TGRC = _0064_4TGRA_VALUE;
    MTU4.TGRB = _0064_4TGRB_VALUE;
    MTU4.TGRD = _0064_4TGRB_VALUE;
    MTU.TDER.BIT.TDER = 0U;
    MTU.TDDR = 0x0001U;
    MTU.TCDR = _03A9_TCDR_VALUE;
    MTU.TCBR = _03A9_TCDR_VALUE;
    MTU3.TGRA = _03AA_SUM_VALUE;
    MTU3.TGRC = _03AA_SUM_VALUE;
    MTU.TOCR1.BYTE = _00_MTU_PSYE_DISABLE | _08_MTU_TOCL_DISABLE | _04_MTU_TOCS_TOCR2;
    MTU.TOCR2.BYTE = _00_MTU_TOLBR_DIS | _00_MTU_OLS3P_HL;
    MTU.TOLBR.BYTE = MTU.TOCR2.BYTE & 0x3FU;
    MTU3.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TTGE_DISABLE;
    MTU4.TIER.BYTE = _00_MTU_TGIEA_DISABLE | _00_MTU_TGIEB_DISABLE | _00_MTU_TCIEV_DISABLE | _00_MTU_TTGE2_DISABLE;
    MTU3.TMDR.BYTE = _0F_MTU_CMT3 | _10_MTU_BFA_BUFFER | _20_MTU_BFB_BUFFER;
    MTU4.TMDR.BYTE = 0x00U;
    MTU.TOER.BYTE = _C0_MTU_OE4D_DISABLE | _C0_MTU_OE4C_DISABLE | _C0_MTU_OE3D_DISABLE | _C4_MTU_OE4B_ENABLE | 
                    _C0_MTU_OE4A_DISABLE | _C0_MTU_OE3B_DISABLE;

    /* Disable read/write to MTU3, MTU4 registers */
    MTU.TRWER.BIT.RWE = 0U;

    /* Set MTIOC4B pin */
    MPC.PC2PFS.BYTE = 0x01U;
    PORTC.PMR.BYTE |= 0x04U;

    R_Config_MTU3_MTU4_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU3_MTU4_Start
* Description  : This function starts the MTU3 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU3_MTU4_Start(void)
{
    /* Start MTU3, MTU4 channel counter */
    MTU.TSTR.BYTE |= (_40_MTU_CST3_ON | _80_MTU_CST4_ON);
}

/***********************************************************************************************************************
* Function Name: R_Config_MTU3_MTU4_Stop
* Description  : This function stops the MTU3 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU3_MTU4_Stop(void)
{
    /* Stop MTU3, MTU4 channel counter */
    MTU.TSTR.BIT.CST3 = 0U;
    MTU.TSTR.BIT.CST4 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
