/*
 * UARThw.cpp
 *
 *  Created on: Jul. 14, 2020
 *      Author: Manuel
 */

#include "UartHelper.h"
#include "driverlib/debug.h"

constexpr UartHelper::portconfig_t UartHelper::configTable[];

uint32_t UartHelper::initHW(uint32_t portNum) {
    ASSERT(portNum < UART_COUNT);

    portconfig_t config = configTable[portNum];

    SysCtlPeripheralEnable(config.gpioSysCtl);  // Enable UART peripheral clock gating
    SysCtlPeripheralEnable(config.portSysCtl);  // Enable GPIO peripheral clock gating for the port used by UART port
    SysCtlDelay(10);    // Small delay to ensure peripherals are on.

    GPIOPinConfigure(config.txPinMux);    // Configure pin mux for the UART's TX pin
    GPIOPinConfigure(config.rxPinMux);    // Configure pin mux for the UART's RX pin

    GPIOPinTypeUART(config.gpioBase, config.pinMode);   // Configure UART's pin mode

    return config.portBase;
}
