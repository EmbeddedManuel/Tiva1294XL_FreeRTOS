/*
 * UARTstdio.cpp
 *
 *  Created on: Jul. 14, 2020
 *      Author: Manuel
 */

#include <inttypes.h>

#include "FreeRTOS/uartprint.h"
#include "driverlib/uart.h"
#include "driverlib/debug.h"

#define ECHO_RX 1

namespace FreeRTOS
{

UartPrint::UartPrint(uint32_t portNum) {
    this->base = initHW(portNum);
}

UartPrint::UartPrint(uint32_t portNum, void (*intEntry)(void)) {
    this->base = initHW(portNum);
    initHW(portNum);
    UARTIntRegister(this->base, intEntry);
}

void UartPrint::init(uint32_t baud, uint32_t sysClk) {
    uint32_t config =
            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE| UART_CONFIG_PAR_NONE);

    this->taskbuf = NULL;
    this->bufCount = 0;
    this->bufLen = 0;

    this->owner = NULL;
    this->mutex = xSemaphoreCreateMutex();

    ASSERT(this->mutex != NULL);


    UARTConfigSetExpClk(this->base, sysClk, baud, config);
    UARTFIFOLevelSet(this->base, UART_FIFO_TX1_8, UART_FIFO_RX1_8);
    UARTIntDisable(this->base, 0xFFFFFFFFU);

    UARTEnable(this->base);
}

int UartPrint::readln(uint8_t* buf, int maxLen) {
    TaskHandle_t taskHandle = xTaskGetCurrentTaskHandle();

    xSemaphoreTake(this->mutex, portMAX_DELAY);

    this->taskbuf = (char*)buf;
    this->bufLen = maxLen;
    this->bufCount = 0;
    this->owner = taskHandle;

    UARTIntEnable(this->base, (UART_INT_RX | UART_INT_RT));
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    xSemaphoreGive(this->mutex);

    return this->bufCount;
}

int UartPrint::write(uint8_t byte) {
    xSemaphoreTake(this->mutex, portMAX_DELAY);
    int retval = (int)(UARTCharPutNonBlocking(this->base, byte));
    xSemaphoreGive(this->mutex);

    return retval;
}

int UartPrint::write(const uint8_t* buf, int len) {
    TaskHandle_t taskHandle = xTaskGetCurrentTaskHandle();
    xSemaphoreTake(this->mutex, portMAX_DELAY);

    this->taskbuf = (char*)buf;
    this->bufLen = len;
    this->bufCount = 0;
    this->owner = taskHandle;

    pvwrite();

    if (this->bufCount < this->bufLen) {
        UARTIntEnable(this->base, UART_INT_TX);
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }

    xSemaphoreGive(this->mutex);

    return this->bufCount;
}

void UartPrint::pvwrite() {
    taskENTER_CRITICAL();
    while (UARTSpaceAvail(base) && (bufLen > bufCount)) {
        UARTCharPutNonBlocking(base, taskbuf[bufCount]);
        bufCount++;
    }
    taskEXIT_CRITICAL();
}

void UartPrint::handler() {
    uint32_t intStatus = UARTIntStatus(this->base, true);
    UARTIntClear(this->base, intStatus);

    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    bool rxDone = false;
    char rxChar;

    if (intStatus & UART_INT_TX) {
        pvwrite();

        if (this->bufLen == this->bufCount) {
            UARTIntDisable(this->base, UART_INT_TX);
            vTaskNotifyGiveFromISR(this->owner, &xHigherPriorityTaskWoken);

            // todo: reset owner
        }
    }

    if (intStatus & (UART_INT_RX | UART_INT_RT)) {
        while (!rxDone && UARTCharsAvail(this->base)) {
            rxChar = (char)UARTCharGetNonBlocking(this->base);
            rxDone = (this->bufCount == this->bufLen-1);

            // Process character
            switch(rxChar) {
            case 0x7F:
            case '\b': {
                // char is a backspace
                if (this->bufCount > 0) {
                    this->bufCount--;
#if ECHO_RX
                    UARTCharPutNonBlocking(this->base, rxChar);
                    UARTCharPutNonBlocking(this->base, ' ');
                    UARTCharPutNonBlocking(this->base, rxChar);
#endif
                }
            } break;

            case CR:
            case LF: {
              rxDone = true;
#if ECHO_RX
              UARTCharPutNonBlocking(this->base, CR);
              UARTCharPutNonBlocking(this->base, LF);
#endif
            } break;
            default: {
                this->taskbuf[this->bufCount++] = rxChar;
#if ECHO_RX
                UARTCharPutNonBlocking(this->base, rxChar);
#endif
            } break;
            }

            if (rxDone) {
                this->taskbuf[this->bufCount++] = '\0';
                UARTIntDisable(this->base, (UART_INT_RX | UART_INT_RT));
                vTaskNotifyGiveFromISR(this->owner, &xHigherPriorityTaskWoken);

                // todo: reset owner
            }
        }
    }

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

} /* namespace RTOS */
