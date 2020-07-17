/*
 * UARThw.h
 *
 *  Created on: Jul. 14, 2020
 *      Author: Manuel
 */

#ifndef FREERTOS_DRIVERS_UART_UARTHELPER_H_
#define FREERTOS_DRIVERS_UART_UARTHELPER_H_

#include <stdint.h>
#include "inc/hw_memmap.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"

class UartHelper {
public:
    enum UART_PORTS {UART0, UART1, UART2, UART3, UART4, UART5, UART6, UART7, UART_COUNT};

    uint32_t initHW(uint32_t portNum);

    typedef struct port_config {
        uint32_t portBase;
        uint32_t portSysCtl;

        uint32_t gpioBase;
        uint32_t gpioSysCtl;

        uint32_t rxPinMux;
        uint32_t txPinMux;

        uint32_t pinMode;
    } portconfig_t;

    static constexpr portconfig_t configTable[UART_COUNT] =
    {
     {UART0_BASE, SYSCTL_PERIPH_UART0, GPIO_PORTA_BASE, SYSCTL_PERIPH_GPIOA, GPIO_PA0_U0RX, GPIO_PA1_U0TX, (GPIO_PIN_0 | GPIO_PIN_1)},
     {UART1_BASE, SYSCTL_PERIPH_UART1, GPIO_PORTB_BASE, SYSCTL_PERIPH_GPIOB, GPIO_PB0_U1RX, GPIO_PB1_U1TX, (GPIO_PIN_0 | GPIO_PIN_1)},
     {UART2_BASE, SYSCTL_PERIPH_UART2, GPIO_PORTD_BASE, SYSCTL_PERIPH_GPIOD, GPIO_PD4_U2RX, GPIO_PD5_U2TX, (GPIO_PIN_4 | GPIO_PIN_5)},
     {UART3_BASE, SYSCTL_PERIPH_UART3, GPIO_PORTJ_BASE, SYSCTL_PERIPH_GPIOJ, GPIO_PJ0_U3RX, GPIO_PJ1_U3TX, (GPIO_PIN_0 | GPIO_PIN_1)},
     {UART4_BASE, SYSCTL_PERIPH_UART4, GPIO_PORTK_BASE, SYSCTL_PERIPH_GPIOK, GPIO_PK0_U4RX, GPIO_PK1_U4TX, (GPIO_PIN_0 | GPIO_PIN_1)},
     {UART5_BASE, SYSCTL_PERIPH_UART5, GPIO_PORTC_BASE, SYSCTL_PERIPH_GPIOC, GPIO_PC6_U5RX, GPIO_PC7_U5TX, (GPIO_PIN_6 | GPIO_PIN_7)},
     {UART6_BASE, SYSCTL_PERIPH_UART6, GPIO_PORTH_BASE, SYSCTL_PERIPH_GPIOP, GPIO_PP0_U6RX, GPIO_PP1_U6TX, (GPIO_PIN_0 | GPIO_PIN_1)},
     {UART7_BASE, SYSCTL_PERIPH_UART7, GPIO_PORTC_BASE, SYSCTL_PERIPH_GPIOC, GPIO_PC4_U7RX, GPIO_PC5_U7TX, (GPIO_PIN_4 | GPIO_PIN_5)}
    };
};


#endif /* FREERTOS_DRIVERS_UART_UARTHELPER_H_ */
