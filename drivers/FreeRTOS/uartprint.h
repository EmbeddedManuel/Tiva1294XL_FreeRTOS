/*
 * UARTstdio.h
 *
 *  Created on: Jul. 14, 2020
 *      Author: Manuel
 */

#ifndef FREERTOS_DRIVERS_UART_UARTSTDIO_H_
#define FREERTOS_DRIVERS_UART_UARTSTDIO_H_

#include <stdint.h>
#include "UartHelper.h"
#include "DeviceTypes/PrintDevice.h"

#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

namespace FreeRTOS
{

class UartPrint : public PrintDevice, private UartHelper
{
public:

    UartPrint(uint32_t portNum);
    UartPrint(uint32_t portNum, void (*handler)(void));

    void init(uint32_t baud, uint32_t sysClk);

    int readln(uint8_t* buf, int maxLen);

    inline int readln(char* buf, int maxLen) {
        return readln((uint8_t*)buf, maxLen);
    }

    void handler();

private:
    SemaphoreHandle_t   mutex;
    TaskHandle_t        owner;

    uint32_t            base;

    char*               taskbuf;
    uint32_t            bufLen;
    uint32_t            bufCount;

    int write(uint8_t byte) final;
    int write(const uint8_t* buf, int len) final;

    void pvwrite();

    int read(uint8_t byte) final {return 0;}
    int read(uint8_t* buf, int len) final {return 0;}


};

} /* namespace FreeRTOS */

#endif /* FREERTOS_DRIVERS_UART_UARTSTDIO_H_ */
