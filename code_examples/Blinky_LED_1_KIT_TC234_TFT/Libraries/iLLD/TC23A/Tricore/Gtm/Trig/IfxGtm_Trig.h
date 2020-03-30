/**
 * \file IfxGtm_Trig.h
 * \brief GTM TRIG details
 * \ingroup IfxLld_Gtm
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Gtm_Trig GTM Trigger Configuration
 * \ingroup IfxLld_Gtm
 * \defgroup IfxLld_Gtm_Trig_Enumerations Enumerations
 * \ingroup IfxLld_Gtm_Trig
 * \defgroup IfxLld_Gtm_Trig_Data_Structures Data Structures
 * \ingroup IfxLld_Gtm_Trig
 * \defgroup IfxLld_Gtm_Trig_Trigger_Functions Trigger Functions
 * \ingroup IfxLld_Gtm_Trig
 */

#ifndef IFXGTM_TRIG_H
#define IFXGTM_TRIG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"
#include "_Impl/IfxGtm_cfg.h"
#include "Gtm/Std/IfxGtm_Tim.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Trig_Enumerations
 * \{ */
/** \brief Enum for ADC group
 */
typedef enum
{
    IfxGtm_Trig_AdcGroup_0,     /**< \brief For ADC group 0  */
    IfxGtm_Trig_AdcGroup_1,     /**< \brief For ADC group 1  */
    IfxGtm_Trig_AdcGroup_2,     /**< \brief For ADC group 2  */
    IfxGtm_Trig_AdcGroup_3      /**< \brief For ADC group 3  */
} IfxGtm_Trig_AdcGroup;

/** \brief Enum for ADC trigger
 */
typedef enum
{
    IfxGtm_Trig_AdcTrig_0,
    IfxGtm_Trig_AdcTrig_1,
    IfxGtm_Trig_AdcTrig_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_AdcTrig;

/** \brief Enum for ADC trigger channel
 */
typedef enum
{
    IfxGtm_Trig_AdcTrigChannel_1,
    IfxGtm_Trig_AdcTrigChannel_2,
    IfxGtm_Trig_AdcTrigChannel_3,
    IfxGtm_Trig_AdcTrigChannel_4,
    IfxGtm_Trig_AdcTrigChannel_5,
    IfxGtm_Trig_AdcTrigChannel_6,
    IfxGtm_Trig_AdcTrigChannel_7,
    IfxGtm_Trig_AdcTrigChannel_8,
    IfxGtm_Trig_AdcTrigChannel_9,
    IfxGtm_Trig_AdcTrigChannel_10,
    IfxGtm_Trig_AdcTrigChannel_11,
    IfxGtm_Trig_AdcTrigChannel_12,
    IfxGtm_Trig_AdcTrigChannel_13,
    IfxGtm_Trig_AdcTrigChannel_14,
    IfxGtm_Trig_AdcTrigChannel_15,
    IfxGtm_Trig_AdcTrigChannel_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_AdcTrigChannel;

/** \brief Enum for ADC trigger source
 */
typedef enum
{
    IfxGtm_Trig_AdcTrigSource_tom0,
    IfxGtm_Trig_AdcTrigSource_tom1,
    IfxGtm_Trig_AdcTrigSource_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_AdcTrigSource;

/** \brief Enum for SENT group
 */
typedef enum
{
    IfxGtm_Trig_SentGroup_0,     /**< \brief For SENT group 0  */
    IfxGtm_Trig_SentGroup_1,     /**< \brief For SENT group 1  */
    IfxGtm_Trig_SentGroup_2,     /**< \brief For SENT group 2  */
    IfxGtm_Trig_SentGroup_3      /**< \brief For SENT group 3  */
} IfxGtm_Trig_SentGroup;

/** \brief Enum for SENT trigger
 */
typedef enum
{
    IfxGtm_Trig_SentTrig_0  /**< \brief sent trigger 0 */
} IfxGtm_Trig_SentTrig;

/** \brief Enum for SENT trigger channel
 */
typedef enum
{
    IfxGtm_Trig_SentTrigChannel_1,
    IfxGtm_Trig_SentTrigChannel_2,
    IfxGtm_Trig_SentTrigChannel_3,
    IfxGtm_Trig_SentTrigChannel_4,
    IfxGtm_Trig_SentTrigChannel_5,
    IfxGtm_Trig_SentTrigChannel_6,
    IfxGtm_Trig_SentTrigChannel_7,
    IfxGtm_Trig_SentTrigChannel_8,
    IfxGtm_Trig_SentTrigChannel_9,
    IfxGtm_Trig_SentTrigChannel_10,
    IfxGtm_Trig_SentTrigChannel_11,
    IfxGtm_Trig_SentTrigChannel_12,
    IfxGtm_Trig_SentTrigChannel_13,
    IfxGtm_Trig_SentTrigChannel_14,
    IfxGtm_Trig_SentTrigChannel_15,
    IfxGtm_Trig_SentTrigChannel_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_SentTrigChannel;

/** \brief Enum for SENT trigger source
 */
typedef enum
{
    IfxGtm_Trig_SentTrigSource_tom0,
    IfxGtm_Trig_SentTrigSource_tom1,
    IfxGtm_Trig_SentTrigSource_count  /**< \brief count of the enum definition */
} IfxGtm_Trig_SentTrigSource;

/** \} */

/** \addtogroup IfxLld_Gtm_Trig_Trigger_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \param gtm Pointer to GTM module
 * \param adcGroup ADC group
 * \param adcTrig ADC trigger
 * \param source ADC trigger source
 * \param channel ADC trigger channel
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxGtm_Trig_toVadc(Ifx_GTM *gtm, IfxGtm_Trig_AdcGroup adcGroup, IfxGtm_Trig_AdcTrig adcTrig, IfxGtm_Trig_AdcTrigSource source, IfxGtm_Trig_AdcTrigChannel channel);

/**
 * \param gtm Pointer to GTM module
 * \param sentGroup SENT group
 * \param sentTrig SENT trigger
 * \param source SENT trigger source
 * \param channel SENT trigger channel
 * \return TRUE on success else FALSE
 */
IFX_EXTERN boolean IfxGtm_Trig_toSent(Ifx_GTM *gtm, IfxGtm_Trig_SentGroup sentGroup, IfxGtm_Trig_SentTrig sentTrig, IfxGtm_Trig_SentTrigSource source, IfxGtm_Trig_SentTrigChannel channel);

/** \} */

#endif /* IFXGTM_TRIG_H */
