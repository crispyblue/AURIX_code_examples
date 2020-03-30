/**
 * \file Ifx_InternalMux.h
 * \brief Mux configuration functions
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2015 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_lib_internalmux_internalmux FIFO
 * This module implements the Internal Mux functionality.
 * \ingroup IfxLld_lib_internalmux
 */

#ifndef IFX_INTERNALMUX_H
#define IFX_INTERNALMUX_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/Ifx_Types.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
/** \addtogroup IfxLld_lib_internalmux_internalmux
 * \{ */
/** Individual Mux configuration structure
 *
 */
typedef struct
{
    volatile void *regAddr;     /**< \brief pointer to the register for Mux/Demux configuration */
    uint32         mask;        /**< \brief Bit field position for the Mux/Demux selection */
    uint32         value;       /**< \brief Mux/Demux configuration value */
} Ifx_InternalMux_MuxConfig;

/** Global/Combined Mux configuration object
 *
 */
typedef struct
{
    uint32                     size;            /**< size of the internal mux configuration array*/
    Ifx_InternalMux_MuxConfig *muxConfig;       /**< pointer to the internal mux config array*/
}Ifx_InternalMux_Config;

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/
/** \brief Initialises the internal mux configuration
 *
 * \param cfg Pointer on the Global Mux Configuration object
 *
 * \return None
 */
IFX_EXTERN void Ifx_InternalMux_init(const Ifx_InternalMux_Config *cfg);

/**\}*/

#endif /* IFX_INTERNALMUX_H */
