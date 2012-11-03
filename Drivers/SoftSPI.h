#ifndef EMTRON_DRIVERS_SOFTSPI_H
#define EMTRON_DRIVERS_SOFTSPI_H

#include "RTOS/portable.h"
#include "RTOS/peripheral.h"
#include "RTOS/stddefs.h"

typedef struct SoftSPI_t* SoftSPI;

typedef struct SoftSPI_t
{
    IOPin_t sck;
    IOPin_t mosi;
    IOPin_t miso;
    UI08_t id:2;
    // other options (polarity etc.)
} SoftSPI_t;


void SoftSPI_IO(SoftSPI spi, PeripheralModeReg_t mode, IOPin_t pin);
void SoftSPI_Register(SoftSPI spi);

void  SoftSPI_Init(PeripheralHandle_t* handle, void* args);

UI08_t SoftSPI_ReadSDO(PeripheralHandle_t* handle);
PeripheralResult_t SoftSPI_Mode(PeripheralHandle_t* handle, PeripheralModeReg_t mode, void* data);
PeripheralResult_t SoftSPI_Tx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length);
PeripheralResult_t SoftSPI_Rx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length);
PeripheralResult_t SoftSPI_TxRx(PeripheralHandle_t* handle, UI08_t* tx_buf, UI08_t* rx_buf, UI16_t length);

UI08_t SoftSPI_TxRxByte(SoftSPI spi, UI08_t b);

#endif
