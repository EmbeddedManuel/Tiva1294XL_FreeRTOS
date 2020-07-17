/*
 * peripherals.cpp
 *
 *  Created on: Jul. 16, 2020
 *      Author: Manuel
 */

#include "peripherals.h"
#include "sysconfig.h"


void uartIntHandler();

FreeRTOS::UartPrint uart(UartHelper::UART0, uartIntHandler);

void uartIntHandler() {
    uart.handler();
}
