/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
 /*\title Comparison of signals via IOM
 * \abstract Two PWM signals are compared by the IOM module.
 * \description Two PWM signals are routed through the port pins to the Input Output Module (IOM) as monitor and
 *              reference respectively. The signals are continuously compared using exclusive OR. If the newly formed
 *              signal (XOR) is in high state outside the acceptable propagation window, an LED is switched on.
 *
 * \name IOM_Signals_Comparison_1_KIT_TC297_TFT
 * \version V1.0.0
 * \board APPLICATION KIT TC2X7 V1.1, KIT_AURIX_TC297_TFT_BC-Step, TC29xTA/TX_BC-step
 * \keywords AURIX, IOM, IOM_Signals_Comparison_1, PWM, comparison, duty cycle, signal
 * \documents https://www.infineon.com/aurix-expert-training/Infineon-AURIX_IOM_Signals_Comparison_1_KIT_TC297_TFT-TR-v01_00_00-EN.pdf
 * \documents https://www.infineon.com/aurix-expert-training/TC29B_iLLD_UM_1_0_1_11_0.chm
 * \lastUpdated 2020-02-11
 *********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Bsp.h"
#include "IOM_Signals_Comparison.h"

IfxCpu_syncEvent g_cpuSyncEvent = 0;

int core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    
    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    /* Initial duty cycle (in %) */
    float32 duty = 50.0;

    initTime();         /* Calculate iLLDs time constants                                       */

    /* Initialization of all the needed modules */
    initSmu();          /* Initialization of SMU module                                         */
    initIR();           /* Initialization of the Interrupt Routine module                       */
    initIOM();          /* Initialization of the IOM module                                     */
    initGtmTomPwm();    /* Initialization of the GTM module and generation of the PWM signal    */

    IfxCpu_restoreInterrupts(interruptState);

    while(1)
    {
        IfxPort_setPinHigh(LED_D107);           /* Switch off the LED D110 (active low)         */
        changeDutyCycle(duty);                  /* Update the duty cycle with specified value   */
        waitTime(TimeConst_1s);                 /* Wait 1 second to facilitate the observation  */
        duty -= 1.0;                            /* Decrease the duty cycle - 1% less            */

        /* Start another observation round beginning with a duty cycle of 50% */
        if(duty < 25)
        {
            duty = 50.0;
        }
    }
    return (1);
}
