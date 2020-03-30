/**
 * \file IfxCpu_Cstart1.c
 * \brief This file contains the Core startup sequence for Cpu1.
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2012 Infineon Technologies AG. All rights reserved.
 *
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
 *
 */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Ifx_Cfg.h"
#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu.h"
#include "Cpu/CStart/IfxCpu_CStart.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"

/******************************************************************************/
/*                           Macros                                            */
/******************************************************************************/
/** \brief Configuration for cache enable.
 *
 */
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_PCACHE
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_PCACHE (1)  /**< Program Cache enabled by default*/
#endif
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_DCACHE
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_DCACHE (1)  /**< Data Cache enabled by default*/
#endif
/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
IFXCOMPILER_COMMON_LINKER_SYMBOLS()
IFXCOMPILER_CORE_LINKER_SYMBOLS(1)

IFX_EXTERN void core1_main(void);
#if defined(__TASKING__)
__asm("\t .extern core1_main");
#endif

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define IFXCSTART1_PSW_DEFAULT     (0x00000980u)
#define IFXCSTART1_PCX_O_S_DEFAULT (0xfff00000u)

/*********************************************************************************
* - startup code
*********************************************************************************/
#if defined(__HIGHTEC__)
#pragma GCC optimize ("-O2")
#endif

void _Core1_start(void)
{
    uint32 pcxi;
    uint16 wdtPassword = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[1]);

    IFX_CFG_CPU_CSTART_PRE_C_INIT_HOOK(1);  /*Test Stack, CSA and Cache */

    /* Load user stack pointer */
    __setareg(sp, __USTACK(1));
    __dsync();

    /* Set the PSW to its reset value in case of a warm start,clear PSW.IS */
    __mtcr(CPU_PSW, IFXCSTART1_PSW_DEFAULT);    /* 0x00000980 */

    /* Set the PCXS and PCXO to its reset value in case of a warm start */
    pcxi  = __mfcr(CPU_PCXI);
    pcxi &= IFXCSTART1_PCX_O_S_DEFAULT; /*0xfff00000; */
    __mtcr(CPU_PCXI, pcxi);

    /*enable program cache */
    IfxCpu_setProgramCache(IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_PCACHE);

    /*enable data cache */
    IfxCpu_setDataCache(IFX_CFG_CPU_CSTART_ENABLE_TRICORE1_DCACHE);

    /* Clear the ENDINIT bit in the WDT_CON0 register, inline funtion */
    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[1], wdtPassword);

    /* Load Base Address of Trap Vector Table. */
    __mtcr(CPU_BTV, (uint32)__TRAPTAB(1));

    /* Load Base Address of Interrupt Vector Table. we will do this later in the program */
    __mtcr(CPU_BIV, (uint32)__INTTAB(1));

    /* Load interupt stack pointer. */
    __mtcr(CPU_ISP, (uint32)__ISTACK(1));

    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[1], wdtPassword);

    /* initialize SDA base pointers */
    __setareg(a0, __SDATA1(1));
    __setareg(a1, __SDATA2(1));

    /* These to be un commented if A8 and A9 are required to be initialised */
    __setareg(a8, __SDATA3(1));
    __setareg(a9, __SDATA4(1));

    IfxCpu_initCSA((uint32 *)__CSA(1), (uint32 *)__CSA_END(1));

    /*Call main function of Cpu0 */
    __non_return_call(core1_main);
}

#if defined(__HIGHTEC__)
#pragma GCC reset_options
#endif
#endif /*#ifndef IFX_CFG_USE_COMPILER_DEFAULT_LINKER */
