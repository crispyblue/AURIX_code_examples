/**
 * \file IfxIom_cfg.h
 * \brief IOM on-chip implementation data
 * \ingroup IfxLld_Iom
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Use of this file is subject to the terms of use agreed between (i) you or 
 * the company in which ordinary course of business you are acting and (ii) 
 * Infineon Technologies AG or its licensees. If and as long as no such 
 * terms of use are agreed, use of this file is subject to following:


 * Boost Software License - Version 1.0 - August 17th, 2003

 * Permission is hereby granted, free of charge, to any person or 
 * organization obtaining a copy of the software and accompanying 
 * documentation covered by this license (the "Software") to use, reproduce,
 * display, distribute, execute, and transmit the Software, and to prepare
 * derivative works of the Software, and to permit third-parties to whom the 
 * Software is furnished to do so, all subject to the following:

 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.

 *
 * \defgroup IfxLld_Iom IOM
 * \ingroup IfxLld
 * \defgroup IfxLld_Iom_Impl Implementation
 * \ingroup IfxLld_Iom
 * \defgroup IfxLld_Iom_Std Standard Driver
 * \ingroup IfxLld_Iom
 * \defgroup IfxLld_Iom_Impl_Enum Enum input signals
 * \ingroup IfxLld_Iom_Impl
 * \defgroup IfxLld_Iom_Impl_Enumeration Enumeration inputs
 * \ingroup IfxLld_Iom_Impl
 */

#ifndef IFXIOM_CFG_H
#define IFXIOM_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Specifies maximum number of channels
 */
#define IFXIOM_NUM_CHANNELS 16

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Iom_Impl_Enum
 * \{ */
/** \brief IOM_FPCCTRk.ISM
 */
typedef enum
{
    IfxIom_MonInputSignal_p = 0,  /**< \brief Signal input Pn_IN (from portlogic) selected */
    IfxIom_MonInputSignal_0 = 1,  /**< \brief Monitor Signal Input 0 selected */
    IfxIom_MonInputSignal_1 = 2,  /**< \brief Monitor Signal Input 1 selected */
    IfxIom_MonInputSignal_2 = 3   /**< \brief Monitor Signal Input 2 selected */
} IfxIom_MonInputSignal;

/** \brief IOM_FPCCTRk.ISR
 */
typedef enum
{
    IfxIom_RefInputSignal_p           = 0, /**< \brief Signal input Pn_IN (from portlogic) selected */
    IfxIom_RefInputSignal_0           = 1, /**< \brief Monitor Signal Input 0 selected */
    IfxIom_RefInputSignal_1           = 2, /**< \brief Monitor Signal Input 1 selected */
    IfxIom_RefInputSignal_2           = 3, /**< \brief Monitor Signal Input 2 selected */
    IfxIom_RefInputSignal_xorCombiner = 4  /**< \brief GTM XOR Combiner selected */
} IfxIom_RefInputSignal;

/** \} */

/** \addtogroup IfxLld_Iom_Impl_Enumeration
 * \{ */
/** \brief LAM mon inputs
 */
typedef enum
{
    IfxIom_MonInput_p33_0       = (IfxIom_MonInputSignal_p << 8) | 0x0,  /**< \brief Value=0xXXYY where XX=ISM, YY=k */
    IfxIom_MonInput_p33_1       = (IfxIom_MonInputSignal_p << 8) | 0x1,
    IfxIom_MonInput_p33_2       = (IfxIom_MonInputSignal_p << 8) | 0x2,
    IfxIom_MonInput_p33_3       = (IfxIom_MonInputSignal_p << 8) | 0x3,
    IfxIom_MonInput_p33_4       = (IfxIom_MonInputSignal_p << 8) | 0x4,
    IfxIom_MonInput_p33_5       = (IfxIom_MonInputSignal_p << 8) | 0x5,
    IfxIom_MonInput_p33_6       = (IfxIom_MonInputSignal_p << 8) | 0x6,
    IfxIom_MonInput_p33_7       = (IfxIom_MonInputSignal_p << 8) | 0x7,
    IfxIom_MonInput_p33_8       = (IfxIom_MonInputSignal_p << 8) | 0x8,
    IfxIom_MonInput_p33_9       = (IfxIom_MonInputSignal_p << 8) | 0x9,
    IfxIom_MonInput_p33_10      = (IfxIom_MonInputSignal_p << 8) | 0xa,
    IfxIom_MonInput_p33_11      = (IfxIom_MonInputSignal_p << 8) | 0xb,
    IfxIom_MonInput_p33_12      = (IfxIom_MonInputSignal_p << 8) | 0xc,
    IfxIom_MonInput_p20_12      = (IfxIom_MonInputSignal_p << 8) | 0xd,
    IfxIom_MonInput_p20_13      = (IfxIom_MonInputSignal_p << 8) | 0xe,
    IfxIom_MonInput_p20_14      = (IfxIom_MonInputSignal_p << 8) | 0xf,
    IfxIom_MonInput_gtmTout22   = (IfxIom_MonInputSignal_0 << 8) | 0x0,
    IfxIom_MonInput_gtmTout23   = (IfxIom_MonInputSignal_0 << 8) | 0x1,
    IfxIom_MonInput_gtmTout24   = (IfxIom_MonInputSignal_0 << 8) | 0x2,
    IfxIom_MonInput_gtmTout25   = (IfxIom_MonInputSignal_0 << 8) | 0x3,
    IfxIom_MonInput_gtmTout26   = (IfxIom_MonInputSignal_0 << 8) | 0x4,
    IfxIom_MonInput_gtmTout27   = (IfxIom_MonInputSignal_0 << 8) | 0x5,
    IfxIom_MonInput_gtmTout28   = (IfxIom_MonInputSignal_0 << 8) | 0x6,
    IfxIom_MonInput_gtmTout29   = (IfxIom_MonInputSignal_0 << 8) | 0x7,
    IfxIom_MonInput_gtmTout30   = (IfxIom_MonInputSignal_0 << 8) | 0x8,
    IfxIom_MonInput_gtmTout31   = (IfxIom_MonInputSignal_0 << 8) | 0x9,
    IfxIom_MonInput_gtmTout32   = (IfxIom_MonInputSignal_0 << 8) | 0xa,
    IfxIom_MonInput_gtmTout33   = (IfxIom_MonInputSignal_0 << 8) | 0xb,
    IfxIom_MonInput_gtmTout34   = (IfxIom_MonInputSignal_0 << 8) | 0xc,
    IfxIom_MonInput_gtmTout68   = (IfxIom_MonInputSignal_0 << 8) | 0xd,
    IfxIom_MonInput_gtmTout69   = (IfxIom_MonInputSignal_0 << 8) | 0xe,
    IfxIom_MonInput_gtmTout70   = (IfxIom_MonInputSignal_0 << 8) | 0xf,
    IfxIom_MonInput_ccu60Cc62   = (IfxIom_MonInputSignal_1 << 8) | 0x0,
    IfxIom_MonInput_ccu60Cc61   = (IfxIom_MonInputSignal_1 << 8) | 0x1,
    IfxIom_MonInput_ccu60Cc60   = (IfxIom_MonInputSignal_1 << 8) | 0x2,
    IfxIom_MonInput_ccu60Cout60 = (IfxIom_MonInputSignal_1 << 8) | 0x3,
    IfxIom_MonInput_ccu60Cout61 = (IfxIom_MonInputSignal_1 << 8) | 0x4,
    IfxIom_MonInput_ccu60Cout62 = (IfxIom_MonInputSignal_1 << 8) | 0x5,
    IfxIom_MonInput_ccu60Cout63 = (IfxIom_MonInputSignal_1 << 8) | 0x6,
    IfxIom_MonInput_ccu61Cout63 = (IfxIom_MonInputSignal_1 << 8) | 0x7,
    IfxIom_MonInput_ccu61Cc60   = (IfxIom_MonInputSignal_1 << 8) | 0x8,
    IfxIom_MonInput_ccu61Cc61   = (IfxIom_MonInputSignal_1 << 8) | 0x9,
    IfxIom_MonInput_ccu61Cc62   = (IfxIom_MonInputSignal_1 << 8) | 0xa,
    IfxIom_MonInput_ccu61Cout60 = (IfxIom_MonInputSignal_1 << 8) | 0xb,
    IfxIom_MonInput_ccu61Cout61 = (IfxIom_MonInputSignal_1 << 8) | 0xc,
    IfxIom_MonInput_ccu61Cout62 = (IfxIom_MonInputSignal_1 << 8) | 0xd,
    IfxIom_MonInput_psi5Psitx0  = (IfxIom_MonInputSignal_1 << 8) | 0xe,
    IfxIom_MonInput_psi5Psitx1  = (IfxIom_MonInputSignal_1 << 8) | 0xf,
    IfxIom_MonInput_qspi0Mrst   = (IfxIom_MonInputSignal_2 << 8) | 0x0,
    IfxIom_MonInput_qspi1Mrst   = (IfxIom_MonInputSignal_2 << 8) | 0x1,
    IfxIom_MonInput_qspi2Mrst   = (IfxIom_MonInputSignal_2 << 8) | 0x2,
    IfxIom_MonInput_qspi3Mrst   = (IfxIom_MonInputSignal_2 << 8) | 0x3,
    IfxIom_MonInput_gnd         = (IfxIom_MonInputSignal_2 << 8) | 0x4,
    IfxIom_MonInput_canNode0Txd = (IfxIom_MonInputSignal_2 << 8) | 0x5,
    IfxIom_MonInput_canNode1Txd = (IfxIom_MonInputSignal_2 << 8) | 0x6,
    IfxIom_MonInput_canNode2Txd = (IfxIom_MonInputSignal_2 << 8) | 0x7,
    IfxIom_MonInput_canNode3Txd = (IfxIom_MonInputSignal_2 << 8) | 0x8,
    IfxIom_MonInput_gtmTout104  = (IfxIom_MonInputSignal_2 << 8) | 0x9,
    IfxIom_MonInput_gtmTout105  = (IfxIom_MonInputSignal_2 << 8) | 0xa,
    IfxIom_MonInput_gtmTout106  = (IfxIom_MonInputSignal_2 << 8) | 0xb,
    IfxIom_MonInput_asclin0Atx  = (IfxIom_MonInputSignal_2 << 8) | 0xc,
    IfxIom_MonInput_asclin1Atx  = (IfxIom_MonInputSignal_2 << 8) | 0xd,
    IfxIom_MonInput_asclin2Atx  = (IfxIom_MonInputSignal_2 << 8) | 0xe,
    IfxIom_MonInput_asclin3Atx  = (IfxIom_MonInputSignal_2 << 8) | 0xf
} IfxIom_MonInput;

/** \brief LAM ref inputs
 */
typedef enum
{
    IfxIom_RefInput_p33_0        = (IfxIom_RefInputSignal_p << 8) | 0x0,
    IfxIom_RefInput_p33_1        = (IfxIom_RefInputSignal_p << 8) | 0x1,
    IfxIom_RefInput_p33_2        = (IfxIom_RefInputSignal_p << 8) | 0x2,
    IfxIom_RefInput_p33_3        = (IfxIom_RefInputSignal_p << 8) | 0x3,
    IfxIom_RefInput_p33_4        = (IfxIom_RefInputSignal_p << 8) | 0x4,
    IfxIom_RefInput_p33_5        = (IfxIom_RefInputSignal_p << 8) | 0x5,
    IfxIom_RefInput_p33_6        = (IfxIom_RefInputSignal_p << 8) | 0x6,
    IfxIom_RefInput_p33_7        = (IfxIom_RefInputSignal_p << 8) | 0x7,
    IfxIom_RefInput_p33_8        = (IfxIom_RefInputSignal_p << 8) | 0x8,
    IfxIom_RefInput_p33_9        = (IfxIom_RefInputSignal_p << 8) | 0x9,
    IfxIom_RefInput_p33_10       = (IfxIom_RefInputSignal_p << 8) | 0xa,
    IfxIom_RefInput_p33_11       = (IfxIom_RefInputSignal_p << 8) | 0xb,
    IfxIom_RefInput_p33_12       = (IfxIom_RefInputSignal_p << 8) | 0xc,
    IfxIom_RefInput_p20_12       = (IfxIom_RefInputSignal_p << 8) | 0xd,
    IfxIom_RefInput_p20_13       = (IfxIom_RefInputSignal_p << 8) | 0xe,
    IfxIom_RefInput_p20_14       = (IfxIom_RefInputSignal_p << 8) | 0xf,
    IfxIom_RefInput_gtmTout0     = (IfxIom_RefInputSignal_0 << 8) | 0x0,
    IfxIom_RefInput_gtmTout1     = (IfxIom_RefInputSignal_0 << 8) | 0x1,
    IfxIom_RefInput_gtmTout2     = (IfxIom_RefInputSignal_0 << 8) | 0x2,
    IfxIom_RefInput_gtmTout3     = (IfxIom_RefInputSignal_0 << 8) | 0x3,
    IfxIom_RefInput_gtmTout4     = (IfxIom_RefInputSignal_0 << 8) | 0x4,
    IfxIom_RefInput_gtmTout5     = (IfxIom_RefInputSignal_0 << 8) | 0x5,
    IfxIom_RefInput_gtmTout6     = (IfxIom_RefInputSignal_0 << 8) | 0x6,
    IfxIom_RefInput_gtmTout7     = (IfxIom_RefInputSignal_0 << 8) | 0x7,
    IfxIom_RefInput_gtmTout8     = (IfxIom_RefInputSignal_0 << 8) | 0x8,
    IfxIom_RefInput_gtmTout9     = (IfxIom_RefInputSignal_0 << 8) | 0x9,
    IfxIom_RefInput_gtmTout10    = (IfxIom_RefInputSignal_0 << 8) | 0xa,
    IfxIom_RefInput_gtmTout11    = (IfxIom_RefInputSignal_0 << 8) | 0xb,
    IfxIom_RefInput_gtmTout12    = (IfxIom_RefInputSignal_0 << 8) | 0xc,
    IfxIom_RefInput_gtmTout13    = (IfxIom_RefInputSignal_0 << 8) | 0xd,
    IfxIom_RefInput_gtmTout14    = (IfxIom_RefInputSignal_0 << 8) | 0xe,
    IfxIom_RefInput_gtmTout15    = (IfxIom_RefInputSignal_0 << 8) | 0xf,
    IfxIom_RefInput_ccu60Cout63  = (IfxIom_RefInputSignal_1 << 8) | 0x0,
    IfxIom_RefInput_ccu60Cout62  = (IfxIom_RefInputSignal_1 << 8) | 0x1,
    IfxIom_RefInput_ccu60Cout61  = (IfxIom_RefInputSignal_1 << 8) | 0x2,
    IfxIom_RefInput_ccu60Cout60  = (IfxIom_RefInputSignal_1 << 8) | 0x3,
    IfxIom_RefInput_ccu60Cc62    = (IfxIom_RefInputSignal_1 << 8) | 0x4,
    IfxIom_RefInput_ccu60Cc61    = (IfxIom_RefInputSignal_1 << 8) | 0x5,
    IfxIom_RefInput_ccu60Cc60    = (IfxIom_RefInputSignal_1 << 8) | 0x6,
    IfxIom_RefInput_ccu61Cout63  = (IfxIom_RefInputSignal_1 << 8) | 0x7,
    IfxIom_RefInput_ccu61Cout62  = (IfxIom_RefInputSignal_1 << 8) | 0x8,
    IfxIom_RefInput_ccu61Cout61  = (IfxIom_RefInputSignal_1 << 8) | 0x9,
    IfxIom_RefInput_ccu61Cout60  = (IfxIom_RefInputSignal_1 << 8) | 0xa,
    IfxIom_RefInput_ccu61Cc62    = (IfxIom_RefInputSignal_1 << 8) | 0xb,
    IfxIom_RefInput_ccu61Cc61    = (IfxIom_RefInputSignal_1 << 8) | 0xc,
    IfxIom_RefInput_ccu61Cc60    = (IfxIom_RefInputSignal_1 << 8) | 0xd,
    IfxIom_RefInput_psi5Psitx0   = (IfxIom_RefInputSignal_1 << 8) | 0xe,
    IfxIom_RefInput_psi5Psitx2   = (IfxIom_RefInputSignal_1 << 8) | 0xf,
    IfxIom_RefInput_qspi0Mrst    = (IfxIom_RefInputSignal_2 << 8) | 0x0,
    IfxIom_RefInput_qspi1Mrst    = (IfxIom_RefInputSignal_2 << 8) | 0x1,
    IfxIom_RefInput_qspi2Mrst    = (IfxIom_RefInputSignal_2 << 8) | 0x2,
    IfxIom_RefInput_qspi3Mrst    = (IfxIom_RefInputSignal_2 << 8) | 0x3,
    IfxIom_RefInput_gnd          = (IfxIom_RefInputSignal_2 << 8) | 0x4,
    IfxIom_RefInput_canNode0Txd  = (IfxIom_RefInputSignal_2 << 8) | 0x5,
    IfxIom_RefInput_canNode1Txd  = (IfxIom_RefInputSignal_2 << 8) | 0x6,
    IfxIom_RefInput_canNode2Txd  = (IfxIom_RefInputSignal_2 << 8) | 0x7,
    IfxIom_RefInput_canNode3Txd  = (IfxIom_RefInputSignal_2 << 8) | 0x8,
    IfxIom_RefInput_gtmTout107   = (IfxIom_RefInputSignal_2 << 8) | 0x9,
    IfxIom_RefInput_gtmTout108   = (IfxIom_RefInputSignal_2 << 8) | 0xa,
    IfxIom_RefInput_gtmTout109   = (IfxIom_RefInputSignal_2 << 8) | 0xb,
    IfxIom_RefInput_asclin0Atx   = (IfxIom_RefInputSignal_2 << 8) | 0xc,
    IfxIom_RefInput_asclin1Atx   = (IfxIom_RefInputSignal_2 << 8) | 0xd,
    IfxIom_RefInput_asclin2Atx   = (IfxIom_RefInputSignal_2 << 8) | 0xe,
    IfxIom_RefInput_asclin3Atx   = (IfxIom_RefInputSignal_2 << 8) | 0xf,
    IfxIom_RefInput_exorCombiner = (IfxIom_RefInputSignal_xorCombiner << 8) | 0x0
} IfxIom_RefInput;

/** \} */

#endif /* IFXIOM_CFG_H */
