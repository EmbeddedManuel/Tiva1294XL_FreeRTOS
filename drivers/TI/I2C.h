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

#define FIFO_EN

namespace TI
{

class I2C
{
public:
    enum I2C_PORTS {I2C0, I2C1, I2C2, I2C3, I2C4, I2C5, I2C6, I2C7, I2C8, I2C9, I2C_COUNT};
    enum SPEED_MODES {I2C_100K, I2C_400K};

//    enum MASTER_COMMANDS {
//        SINGLE_SEND, SINGLE_RECEIVE,
//
//        START_REPEAT_SEND, CONT_REPEAT_SEND, FINISH_REPEAT_SEND,
//
//        START_REPEAT_RECEIVE, CONT_REPEAT_RECEIVE,FINISH_REPEAT_RECEIVE,
//
//#ifdef FIFO_EN
//        FIFO_SINGLE_SEND, FIFO_SINGLE_RECEIVE,
//
//        FIFO_START_REPEAT_SEND, FIFO_CONT_REPEAT_SEND, FIFO_FINISH_REPEAT_SEND,
//
//        FIFO_START_REPEAT_RECEIVE, FIFO_CONT_REPEAT_RECEIVE, FIFO_FINISH_REPEAT_RECEIVE,
//#endif
//
//        ERROR_STOP,
//
//        COMMAND_COUNT
//    };

protected:
    I2C(uint32_t portNum);
    I2C(uint32_t portNum, void (*intEntry)(void));

    void initHW();

//    int masterInit(uint32_t speedMode);
//
//    int slaveInit(uint8_t addr);
//    int slaveInit(uint8_t addr, uint8_t altAddr);
//
//    void masterSetAddr(uint8_t addr);
//    void masterSetAddr(uint8_t addr, uint8_t rw);
//
//    int masterDataPut(uint8_t byte);
//
//    int masterDataGet(uint8_t byte);
//    int masterDataGetFIFO(uint8_t* buf, uint32_t len);
//
//#ifdef FIFO_EN
//    int masterSetupTxFIFO(uint8_t* buf, uint32_t len);
//    int masterSetupRxFIFO(uint32_t len);
//#endif
//
//    int masterCommad(uint32_t cmd);
//
//    int masterIntStatus();
//    int masterIntStatusClear();
//
//    int masterIntEnable(uint32_t flags);
//    int masterIntDisable(uint32_t flags);

    uint32_t port;
private:
    constexpr uint32_t getBase();

    typedef struct I2C_HW_CONFIG {
        uint32_t portBase;
        uint32_t portClkCtl;

        uint32_t gpioBase;
        uint32_t gpioClkCtl;

        uint32_t sclMux;
        uint32_t sclPin;

        uint32_t sdaMux;
        uint32_t sdaPin;
    } hw_config_t;

    static constexpr hw_config_t CONFIG_TABLE[I2C_COUNT] =
    {
     /* portBase      portClkCtl          gpioBase          gpioClkCtl          sclMux          sclPin        sdaMux          sdaPin  */
     {I2C0_BASE, SYSCTL_PERIPH_I2C0, GPIO_PORTB_BASE, SYSCTL_PERIPH_GPIOB, GPIO_PB2_I2C0SCL, GPIO_PIN_2, GPIO_PB3_I2C0SDA, GPIO_PIN_3}, // I2C0
     {I2C1_BASE, SYSCTL_PERIPH_I2C1, GPIO_PORTG_BASE, SYSCTL_PERIPH_GPIOG, GPIO_PG0_I2C1SCL, GPIO_PIN_0, GPIO_PG1_I2C1SDA, GPIO_PIN_1}, // I2C1
     {I2C2_BASE, SYSCTL_PERIPH_I2C2, GPIO_PORTL_BASE, SYSCTL_PERIPH_GPIOL, GPIO_PL1_I2C2SCL, GPIO_PIN_1, GPIO_PL0_I2C2SDA, GPIO_PIN_0}, // I2C2
     {I2C3_BASE, SYSCTL_PERIPH_I2C3, GPIO_PORTK_BASE, SYSCTL_PERIPH_GPIOK, GPIO_PK4_I2C3SCL, GPIO_PIN_4, GPIO_PK5_I2C3SDA, GPIO_PIN_5}, // I2C3
     {I2C4_BASE, SYSCTL_PERIPH_I2C4, GPIO_PORTK_BASE, SYSCTL_PERIPH_GPIOK, GPIO_PK6_I2C4SCL, GPIO_PIN_6, GPIO_PK7_I2C4SDA, GPIO_PIN_7}, // I2C4
     {I2C5_BASE, SYSCTL_PERIPH_I2C5, GPIO_PORTB_BASE, SYSCTL_PERIPH_GPIOB, GPIO_PB0_I2C5SCL, GPIO_PIN_0, GPIO_PB1_I2C5SDA, GPIO_PIN_1}, // I2C5
     {I2C6_BASE, SYSCTL_PERIPH_I2C6, GPIO_PORTA_BASE, SYSCTL_PERIPH_GPIOA, GPIO_PA6_I2C6SCL, GPIO_PIN_6, GPIO_PA7_I2C6SDA, GPIO_PIN_7}, // I2C6
     {I2C7_BASE, SYSCTL_PERIPH_I2C7, GPIO_PORTD_BASE, SYSCTL_PERIPH_GPIOD, GPIO_PD0_I2C7SCL, GPIO_PIN_0, GPIO_PD1_I2C7SDA, GPIO_PIN_1}, // I2C7
     {I2C8_BASE, SYSCTL_PERIPH_I2C8, GPIO_PORTD_BASE, SYSCTL_PERIPH_GPIOD, GPIO_PD2_I2C8SCL, GPIO_PIN_2, GPIO_PD3_I2C8SDA, GPIO_PIN_3}, // I2C8
     {I2C9_BASE, SYSCTL_PERIPH_I2C9, GPIO_PORTA_BASE, SYSCTL_PERIPH_GPIOA, GPIO_PA0_I2C9SCL, GPIO_PIN_0, GPIO_PA1_I2C9SDA, GPIO_PIN_1}, // I2C9
    };

//    static constexpr uint32_t COMMAND_TABLE[COMMAND_COUNT] =
//    {
//     I2C_MASTER_CMD_SINGLE_SEND, I2C_MASTER_CMD_SINGLE_RECEIVE,
//
//     I2C_MASTER_CMD_BURST_SEND_START, I2C_MASTER_CMD_BURST_SEND_CONT, I2C_MASTER_CMD_BURST_SEND_FINISH,
//
//     I2C_MASTER_CMD_BURST_RECEIVE_START, I2C_MASTER_CMD_BURST_RECEIVE_CONT, I2C_MASTER_CMD_BURST_RECEIVE_FINISH,
//
//#ifdef FIFO_EN
//     I2C_MASTER_CMD_FIFO_SINGLE_SEND, I2C_MASTER_CMD_FIFO_SINGLE_RECEIVE,
//
//     I2C_MASTER_CMD_FIFO_BURST_SEND_START, I2C_MASTER_CMD_FIFO_BURST_SEND_CONT, I2C_MASTER_CMD_FIFO_BURST_SEND_FINISH,
//
//     I2C_MASTER_CMD_FIFO_BURST_RECEIVE_START, I2C_MASTER_CMD_FIFO_BURST_RECEIVE_CONT, I2C_MASTER_CMD_FIFO_BURST_RECEIVE_FINISH,
//#endif
//
//     I2C_MASTER_CMD_BURST_SEND_STOP // error is the same for any type of operation
//    };
};

} /* namespace TI */

#endif /* DRIVERS_TI_I2C_H_ */
