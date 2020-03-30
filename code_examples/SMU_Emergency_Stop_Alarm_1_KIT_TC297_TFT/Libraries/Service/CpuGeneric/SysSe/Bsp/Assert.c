/**
 * \file Assert.c
 * \brief Assert functions.
 *
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
 *
 * $Date: 2014-02-27 20:08:29 GMT$
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
 */

#include "Assert.h"

#if IFX_CFG_ASSERT_STDIO == 1
/** Current standard IO used for the IFX_ASSERT and IFX_VALIDATE */
IfxStdIf_DPipe *Assert_io = NULL_PTR;
#endif

#if IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT > IFX_VERBOSE_LEVEL_OFF
uint32          Assert_verboseLevel = IFX_CFG_ASSERT_VERBOSE_LEVEL_DEFAULT;
#endif

#if IFX_CFG_ASSERT_STDIO == 1
void Ifx_Assert_setStandardIo(IfxStdIf_DPipe *standardIo)
{
    Assert_io = standardIo;
}


#endif

/** \internal
 * Text used to display the king of assertion
 */
const pchar Assert_level[6] = {
    "OFF",
    "FAILURE",
    "ERROR",
    "WARNING",
    "INFO",
    "DEBUG"
};

void Ifx_Assert_doLevel(uint8 level, pchar __assertion, pchar __file, unsigned int __line, pchar __function)
{
#if IFX_CFG_ASSERT_USE_BREAKPOINT == 1

    if (level <= IFX_VERBOSE_LEVEL_ERROR)
    {
        __debug();
    }

#endif

#if IFX_CFG_ASSERT_STDIO == 1

    if (Assert_io != NULL_PTR)
    {
        IfxStdIf_DPipe_print(Assert_io, "ASSERTION %s '%s' in %s:%u (function '%s()')" ENDL, Assert_level[level],
            __assertion, __file, __line, __function);
    }

#endif
}


boolean Ifx_Assert_doValidate(boolean expr, uint8 level, pchar __assertion, pchar __file, unsigned int __line, pchar __function)
{
    if (!((expr) || (level > Assert_verboseLevel)))
    {
#if IFX_CFG_ASSERT_USE_BREAKPOINT == 1

        if (level <= IFX_VERBOSE_LEVEL_ERROR)
        {
            __debug();
        }

#endif

#if IFX_CFG_ASSERT_STDIO == 1

        if (Assert_io != NULL_PTR)
        {
            IfxStdIf_DPipe_print(Assert_io, "VALIDATION %s '%s' in %s:%u (function '%s()')" ENDL, Assert_level[level],
                __assertion, __file, __line, __function);
        }

#endif
    }
    else
    {}

    return expr;
}
