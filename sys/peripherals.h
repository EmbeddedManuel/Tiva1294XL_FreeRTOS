/*
 * peripherals.h
 *
 *  Created on: Jul. 16, 2020
 *      Author: Manuel
 */

#ifndef SYS_PERIPHERALS_H_
#define SYS_PERIPHERALS_H_

#include <stdint.h>
#include "FreeRTOS/uartprint.h"

constexpr uint32_t DEF_BAUD = 115200;

extern FreeRTOS::UartPrint uart;



#endif /* SYS_PERIPHERALS_H_ */
