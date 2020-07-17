/*
 * sysconfig.c
 *
 *  Created on: Jul. 16, 2020
 *      Author: Manuel
 */

#include <stdint.h>
#include <stdbool.h>
#include "sysconfig.h"

#include "driverlib/debug.h"
#include "driverlib/sysctl.h"

uint32_t sysinit() {

    uint32_t clkConfig = (SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN |SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480);
    uint32_t sysclk = SysCtlClockFreqSet(clkConfig, CPU_CLK);
    ASSERT(sysclk == CPU_CLK);

    return sysclk;
}


#ifdef DEBUG
/*  ASSERT() Error function
 *
 *  failed ASSERTS() from driverlib/debug.h are executed in this function
 */
void __error__(const char *pcFilename, uint32_t ui32Line)
{
    // Place a breakpoint here to capture errors until logging routine is finished
    while (1)
    {
    }
}
#endif
