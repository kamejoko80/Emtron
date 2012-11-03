#include "Drivers/SoftI2C.h"
#include "RTOS/peripheral.h"

UI08_t I2C_id = 0;
SoftI2C SoftI2CList[2]; // up to 2 soft I2C busses.
UI08_t SoftI2C_TxRxBit(SoftI2C i2c, UI08_t b);
void SoftI2C_Delay1_2(void);


void SoftI2C_Delay1_2(void)
{
}

void SoftI2C_Register(SoftI2C this)
{
    Peripheral_Register(PERIPHERAL_SOFTI2C,
            I2C_id,
            SoftI2C_Init,
            SoftI2C_Mode,
            SoftI2C_Tx,
            SoftI2C_Rx,
            null,
            SoftI2C_ReadSDA);

    SoftI2CList[I2C_id] = this;
    SoftI2CList[I2C_id]->id = I2C_id;

    I2C_id ++;
}
void SoftI2C_IO(SoftI2C this, PeripheralModeReg_t mode, IOPin_t pin)
{
    switch(mode)
    {
        case MODE_DATA_PIN:
            this->sda = pin;
            SGPIO_Write1GPIO(pin);
            SGPIO_DirectionGPIO(pin, OUTPUT);
            SGPIO_OpenDrainEnable(pin);
            break;

        case MODE_CLK_PIN:
            this->scl = pin;
            SGPIO_Write1GPIO(pin);
            SGPIO_DirectionGPIO(pin, OUTPUT);
            SGPIO_OpenDrainEnable(pin);
            break;
        default:
            break;
    }
}

void  SoftI2C_Init(PeripheralHandle_t* handle, void* args)
{
    
}

UI08_t SoftI2C_ReadSDA(PeripheralHandle_t* handle)
{
    return SGPIO_ReadGPIO(SoftI2CList[handle->Peripheral]->sda);
}
PeripheralResult_t SoftI2C_Mode(PeripheralHandle_t* handle, PeripheralModeReg_t mode, void* data)
{
    SoftI2C this = SoftI2CList[handle->Peripheral];
    //
    switch(mode)
    {
        case MODE_START:
            if(SGPIO_ReadGPIO(this->sda) == 0)  SGPIO_Write1GPIO(this->sda);
            if(SGPIO_ReadGPIO(this->scl) == 0)  SGPIO_Write1GPIO(this->scl);
            // pull SDA down when SCL is high
            SGPIO_Write0GPIO(this->sda);
            SoftI2C_Delay1_2();
            SGPIO_Write0GPIO(this->scl);
            break;

        case MODE_STOP:
            // pull SDA down when SCL is high
            SGPIO_Write1GPIO(this->scl);
            SoftI2C_Delay1_2();
            SGPIO_Write1GPIO(this->sda);
            break;
        default:
            return PR_NOT_EXIST;
            break;
    }
    SoftI2C_Delay1_2();
    return PR_OK;
}
PeripheralResult_t SoftI2C_Tx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length)
{
    while(length > 0)
    {
        if (SoftI2C_TxByte(SoftI2CList[handle->Peripheral], buf) == PR_NOT_ACK)
            return PR_NOT_ACK;
        buf++;
        length--;
    }
    return PR_OK;
}
PeripheralResult_t SoftI2C_Rx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length)
{
    while(length > 0)
    {
        SoftI2C_RxByte(SoftI2CList[handle->Peripheral], buf);
        buf++;
        length--;

        // Do acknowledge
        SoftI2C_TxRxBit(SoftI2CList[handle->Peripheral], ((length == 0)?1:0));
    }
    return PR_OK;
}
PeripheralResult_t SoftI2C_TxByte(SoftI2C this, UI08_t* b)
{
    SI08_t i = 7,v =0;
    for(; i>= 0; i--)
    {
        v = (*b)>>i;
        v = v&0x1;
        SoftI2C_TxRxBit(this, v);
    }
    if (SoftI2C_TxRxBit(this, 1) == 0)
        return PR_ACK;
    else
        return PR_NOT_ACK;
}
PeripheralResult_t SoftI2C_RxByte(SoftI2C this, UI08_t* b)
{
    SI08_t i = 7;
    *b = 0;
    for(; i>= 0; i--)
    {
        *b |= (SoftI2C_TxRxBit(this, 1)) << i;
    }
    return PR_OK;
}
UI08_t SoftI2C_TxRxBit(SoftI2C i2c, UI08_t b)
{
    SGPIO_WriteGPIO(i2c->sda, (b&0x1));
    SGPIO_Write1GPIO(i2c->scl);
    SoftI2C_Delay1_2();
    b = SGPIO_ReadGPIO(i2c->sda);
    SoftI2C_Delay1_2();
    SGPIO_Write0GPIO(i2c->scl);
    SoftI2C_Delay1_2();
    SGPIO_Write0GPIO(i2c->sda);
    SoftI2C_Delay1_2();
    return b;
}
