/*
 * I2C.h
 *
 *  Created on: Jul. 17, 2020
 *      Author: Manuel
 */

#ifndef DRIVERS_FREERTOS_I2CMASTER_H_
#define DRIVERS_FREERTOS_I2CMASTER_H_

#include <stdint.h>

#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"


namespace FreeRTOS
{

class I2CMaster
{
public:
    enum SPEED_MODES {I2C_100K, I2C_400K};

    I2CMaster(uint32_t portNum);
    I2CMaster(uint32_t portNum, void (*intEntry)(void));

    void init(uint32_t speedMode = I2C_100K);

    int read(uint8_t addr);
    int read(uint8_t addr, uint8_t* buf, int len);

    int write(uint8_t addr, uint8_t byte);
    int write(uint8_t addr, uint8_t* buf, int len);

    inline int read(char addr) {
        return read((uint8_t)addr);
    }

    inline int read(uint8_t addr, char* buf, int len) {
        return read(addr, (uint8_t*)buf, len);
    }

    inline int read(char addr, char* buf, int len) {
        return read((uint8_t)addr, (uint8_t*)buf, len);
    }

    inline int write(uint8_t addr, char* buf, int len) {
        return write(addr, (uint8_t*)buf, len);
    }

    inline int write(char addr, char* buf, int len) {
        return write((uint8_t)addr, (uint8_t*)buf, len);
    }

    void handler();

private:
    inline void setAddr(uint8_t addr, bool rw);
    inline bool getMode();

    SemaphoreHandle_t   mutex;
    TaskHandle_t        owner;

    uint32_t            base;

    char*               taskbuf;
    uint32_t            bufLen;
    uint32_t            bufCount;

    uint8_t             slvAddr;
};

} /* namespace FreeRTOS */

#endif /* DRIVERS_FREERTOS_I2CMASTER_H_ */
