/*
 * I2C.h
 *
 *  Created on: Jul. 18, 2020
 *      Author: Manuel
 */

#ifndef DRIVERS_TI_I2C_H_
#define DRIVERS_TI_I2C_H_

#include <stdint.h>

#include "driverlib/i2c.h"

namespace TI
{

class I2C
{
public:
    enum I2C_PORTS {I2C0, I2C1, I2C3, I2C4, I2C5, I2C6, I2C8, I2C9, I2C_COUNT};
    enum SPEED_MODES {I2C_100K, I2C_400K};

protected:
    I2C(uint32_t portNum);
    I2C(uint32_t portNum, void (*intEntry)(void));

    int initMaster(uint32_t speedMode);

    int initSlave(uint8_t addr);
    int initSlave(uint8_t addr, uint8_t altAddr);

private:
    uint32_t base;

    typedef struct portConfig {
        uint32_t portBase;
        uint32_t portSysCtl;

        uint32_t gpioBase;
        uint32_t gpioSysCtl;

        uint32_t sdaMux;
        uint32_t sdaPin;

        uin
    };
};

} /* namespace TI */

#endif /* DRIVERS_TI_I2C_H_ */
