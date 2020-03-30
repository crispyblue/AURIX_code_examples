/**
 * \file IfxVadc_cfg.h
 * \brief VADC on-chip implementation data 
 * \ingroup IfxLld_Vadc 
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Vadc VADC
 * \ingroup IfxLld
 * \defgroup IfxLld_Vadc_Impl Implementation
 * \ingroup IfxLld_Vadc
 * \defgroup IfxLld_Vadc_Std Standard Driver
 * \ingroup IfxLld_Vadc
 */

#ifndef IFXVADC_CFG_H
#define IFXVADC_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of ADC Groups 
 */
#define IFXVADC_NUM_ADC_GROUPS (8)
                
/** \brief Number of calibrated ADC Groups 
 */
#define IFXVADC_NUM_ADC_CAL_GROUPS (8)
                
/** \brief Maximum allowed analog frequency 
 */
#define IFXVADC_ANALOG_FREQUENCY_MAX (20000000)
                
/** \brief Minimum allowed analog frequency 
 */
#define IFXVADC_ANALOG_FREQUENCY_MIN (500000)
                
/** \brief Default analog frequency used in initModuleConfig function 
 */
#define IFXVADC_DEFAULT_ANALOG_FREQ (20000000)
                
/** \brief Number of Conversion request Slots 
 */
#define IFXVADC_NUM_REQUESTSLOTS (3)
                
/** \brief Number of group specific Input Class 
 */
#define IFXVADC_NUM_INPUTCLASSES (2)
                
/** \brief Maximum number of configurable bitfields in ACCPROT0 register 
 */
#define IFXVADC_MAXIMUM_BITFIELDS_IN_ACCPROT0_REGISTER (32)
                
#define IFXVADC_QUEUE_REFILL (1 << IFX_VADC_G_QBUR0_RF_OFF)
                
/** \brief Number of ADC group input classes. 
 */
#define IFXVADC_NUM_GLOBAL_INPUTCLASSES (2)
                
#define IFXVADC_NUM_ADC_COMMON_GROUPS (2)
                
#define IFXVADC_SAMPLETIME_MIN (2)
                
#define IFXVADC_NUM_EMUX_INTERFACE (2)
                
#define IFXVADC_NUM_MODULES (1)
                


/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief VADC Groups  
 */
typedef enum
{
    IfxVadc_GroupId_0,           /**< \brief VADC group 0  */
    IfxVadc_GroupId_1,           /**< \brief VADC group 1  */
    IfxVadc_GroupId_2,           /**< \brief VADC group 2  */
    IfxVadc_GroupId_3,           /**< \brief VADC group 3  */
    IfxVadc_GroupId_4,           /**< \brief VADC group 4  */
    IfxVadc_GroupId_5,           /**< \brief VADC group 5  */
    IfxVadc_GroupId_6,           /**< \brief VADC group 6  */
    IfxVadc_GroupId_7,           /**< \brief VADC group 7  */
    IfxVadc_GroupId_global0,     /**< \brief VADC group global0  */
    IfxVadc_GroupId_global1      /**< \brief VADC group global1  */
} IfxVadc_GroupId;


/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST uint32 IfxVadc_cfg_srcAddresses[(IFXVADC_NUM_ADC_GROUPS *4) + (IFXVADC_NUM_ADC_COMMON_GROUPS * 4) ];


#endif /* IFXVADC_CFG_H */
