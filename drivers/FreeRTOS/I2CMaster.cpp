/*
 * I2C.cpp
 *
 *  Created on: Jul. 17, 2020
 *      Author: Manuel
 */

#include "FreeRTOS/I2CMaster.h"

#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"s

namespace FreeRTOS
{

I2CMaster::I2CMaster(uint32_t portNum) {

}

I2CMaster::I2CMaster(uint32_t portNum, void (*intEntry)(void)) {

    I2CIntRegister(this->base, intEntry);
}

void I2CMaster::init(uint32_t speedMode) {
    ASSERT(speedMode == I2C_100K || speedMode == I2C_400K);

    this->taskbuf = NULL;
    this->bufCount = 0;
    this->bufLen = 0;

    this->owner = NULL;
    this->mutex = xSemaphoreCreateMutex();

    ASSERT(this->mutex != NULL);

    uint32_t sysclk = SysCtlClockGet();
    I2CMasterInitExpClk(this->base, sysclk, (bool)speedMode);
}

int I2CMaster::read(uint8_t addr) {

}

int I2CMaster::read(uint8_t addr, uint8_t* buf, int len) {

}

int I2CMaster::write(uint8_t addr, uint8_t byte) {

}

int I2CMaster::write(uint8_t addr, uint8_t* buf, int len) {

}

void I2CMaster::handler() {

}

inline void I2CMaster::setAddr(uint8_t addr, bool rw) {
    this->slvAddr = (addr << 1 | (uint8_t)rw);
}

inline bool I2CMaster::getMode() {
    return (bool)(this->slvAddr & 1);
}


} /* namespace FreeRTOS */
