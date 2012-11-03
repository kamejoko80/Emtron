#include "Drivers/SoftSPI.h"
#include <string.h>

UI08_t spi_id = 0;

SoftSPI SoftSPIList[4]; // up to 4 soft SPI busses.

void SoftSPI_Register(SoftSPI spi)
{
    Peripheral_Register(PERIPHERAL_SOFTSPI, 
            spi_id,
            SoftSPI_Init,
            SoftSPI_Mode,
            SoftSPI_Tx,
            SoftSPI_Rx,
            SoftSPI_TxRx,
            SoftSPI_ReadSDO);

    SoftSPIList[spi_id] = spi;
    SoftSPIList[spi_id]->id = spi_id;
    
    spi_id ++;

}

void  SoftSPI_Init(PeripheralHandle_t* handle, void* args)
{
    // ??
    handle->Peripheral = ((SoftSPI)args)->id;
}

void SoftSPI_IO(SoftSPI this, PeripheralModeReg_t mode, IOPin_t pin)
{
    switch(mode)
    {
        case MODE_RX_PIN:
            this->miso = pin;
            SGPIO_DirectionGPIO(pin, INPUT);
            // TODO: Enable internal pull-up
            break;

        case MODE_TX_PIN:
            this->mosi = pin;
            SGPIO_DirectionGPIO(pin, OUTPUT);
            SGPIO_Write1GPIO(pin);
            break;
            
        case MODE_CLK_PIN:
            this->sck = pin;
            SGPIO_DirectionGPIO(pin, OUTPUT);
            SGPIO_Write1GPIO(pin);
            break;

        default:
            break;
    }
}

PeripheralResult_t SoftSPI_Mode(PeripheralHandle_t* handle, PeripheralModeReg_t mode, void* data)
{
    //
    return PR_OK;
}

PeripheralResult_t  SoftSPI_Tx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length)
{
    while(length > 0)
    {
        SoftSPI_TxRxByte(SoftSPIList[handle->Peripheral], *buf);
        buf++;
        length--;
    }
    return PR_OK;
}
PeripheralResult_t  SoftSPI_Rx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length)
{
    while(length > 0)
    {
        *buf = SoftSPI_TxRxByte(SoftSPIList[handle->Peripheral], 0xFF);
        buf++;
        length--;
    }
    return PR_OK;
}
PeripheralResult_t  SoftSPI_TxRx(PeripheralHandle_t* handle, UI08_t* tx_buf, UI08_t* rx_buf, UI16_t length)
{
    while(length > 0)
    {
        *rx_buf = SoftSPI_TxRxByte(SoftSPIList[handle->Peripheral], *tx_buf);
        tx_buf++;
        rx_buf++;
        
        length--;
    }
    return PR_OK;
}

UI08_t SoftSPI_ReadSDO(PeripheralHandle_t* handle)
{
    if (SGPIO_ReadGPIO(SoftSPIList[handle->Peripheral]->miso)==0)
        return 0;
    else
        return 1;
}
UI08_t SoftSPI_TxRxByte(SoftSPI spi, UI08_t b)
{
    UI08_t a = 0;
    SI08_t i;

    SGPIO_Write1GPIO(spi->sck);
    for(i = 7; i >= 0; i--)
    {
        SGPIO_WriteGPIO(spi->mosi, ((b>>i)&0x1));
        SGPIO_Write0GPIO(spi->sck);

        if(SGPIO_ReadGPIO(spi->miso) != 0)
            a |= 1<<i;
        SGPIO_Write1GPIO(spi->sck);
    }


    SGPIO_Write1GPIO(spi->sck);
    return a;
}
