/**
 * \file IfxCif_PinMap.h
 * \brief CIF I/O map
 * \ingroup IfxLld_Cif
 *
 * \version iLLD_1_0_1_11_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Cif_pinmap CIF Pin Mapping
 * \ingroup IfxLld_Cif
 */

#ifndef IFXCIF_PINMAP_H
#define IFXCIF_PINMAP_H

#include <IfxCif_reg.h>
#include <_Impl/IfxCif_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Cif_pinmap
 * \{ */

/** \brief CLK pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_Clk_In;

/** \brief D pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_D_In;

/** \brief HSNC pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_Hsnc_In;

/** \brief VSNC pin mapping structure */
typedef const struct
{
    Ifx_CIF*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
} IfxCif_Vsnc_In;

IFX_EXTERN IfxCif_Clk_In IfxCif_CLK_P00_7_IN;  /**< \brief CIF_CLK: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D0_P02_0_IN;  /**< \brief CIF_D0: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D10_P00_1_IN;  /**< \brief CIF_D10: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D11_P00_2_IN;  /**< \brief CIF_D11: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D12_P00_3_IN;  /**< \brief CIF_D12: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D13_P00_4_IN;  /**< \brief CIF_D13: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D14_P00_5_IN;  /**< \brief CIF_D14: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D15_P00_6_IN;  /**< \brief CIF_D15: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D1_P02_1_IN;  /**< \brief CIF_D1: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D2_P02_2_IN;  /**< \brief CIF_D2: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D3_P02_3_IN;  /**< \brief CIF_D3: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D4_P02_4_IN;  /**< \brief CIF_D4: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D5_P02_5_IN;  /**< \brief CIF_D5: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D6_P02_6_IN;  /**< \brief CIF_D6: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D7_P02_7_IN;  /**< \brief CIF_D7: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D8_P02_8_IN;  /**< \brief CIF_D8: CIF input */
IFX_EXTERN IfxCif_D_In IfxCif_D9_P00_0_IN;  /**< \brief CIF_D9: CIF input */
IFX_EXTERN IfxCif_Hsnc_In IfxCif_HSNC_P00_9_IN;  /**< \brief CIF_HSNC: CIF input */
IFX_EXTERN IfxCif_Vsnc_In IfxCif_VSNC_P00_8_IN;  /**< \brief CIF_VSNC: CIF input */

/** \} */

#endif /* IFXCIF_PINMAP_H */
