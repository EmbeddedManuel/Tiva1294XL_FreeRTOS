

/**
 * main.c
 */

#include "FreeRTOS/uartprint.h"
#include "FreeRTOS.h"
#include "task.h"

#include "sysconfig.h"
#include "peripherals.h"

#include "driverlib/debug.h"

void testTask1(void* param) {
    uart.println("Hello from task 1!");

    char buf[64];
    while (true) {
        uart.print("[Task 1] type: ");
        uart.readln(buf, 64);
        uart.print("[Task 1] Received: ");
        uart.println(buf);
    }
}

void testTask2(void* param) {
    uart.println("Hello from task 2!");

    char buf[64];
    while (true) {
        uart.print("[Task 2] type: ");
        uart.readln(buf, 64);
        uart.print("[Task 2] Received: ");
        uart.println(buf);
    }
}

int main(void)
{
    sysinit();
    uart.init(115200, CPU_CLK);

    xTaskCreate(testTask1, "test1", 256, NULL, tskIDLE_PRIORITY+1, NULL);
    xTaskCreate(testTask2, "test2", 256, NULL, tskIDLE_PRIORITY+1, NULL);


    vTaskStartScheduler();

	return 0;
}

