#ifndef EMTRON_DRIVERS_SOFTI2C_H
#define EMTRON_DRIVERS_SOFTI2C_H

#include "RTOS/portable.h"
#include "RTOS/peripheral.h"
#include "RTOS/stddefs.h"

typedef struct SoftI2C_t* SoftI2C;

typedef struct SoftI2C_t
{
    IOPin_t scl;
    IOPin_t sda;
    UI08_t id:2;
    // other options (polarity etc.)
} SoftI2C_t;

void SoftI2C_Register(SoftI2C this);
void SoftI2C_Init(PeripheralHandle_t* handle, void* args);
void SoftI2C_IO(SoftI2C this, PeripheralModeReg_t mode, IOPin_t pin);

UI08_t SoftI2C_ReadSDA(PeripheralHandle_t* handle);
PeripheralResult_t SoftI2C_Mode(PeripheralHandle_t* handle, PeripheralModeReg_t mode, void* data);
PeripheralResult_t SoftI2C_Tx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length);
PeripheralResult_t SoftI2C_Rx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length);

PeripheralResult_t SoftI2C_TxByte(SoftI2C this, UI08_t* b);
PeripheralResult_t SoftI2C_RxByte(SoftI2C this, UI08_t* b);

#endif
