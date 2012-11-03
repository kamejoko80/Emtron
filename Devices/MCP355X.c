#include "Devices/MCP355X.h"
#include "RTOS/stddefs.h"

void MCP355X_Init(MCP355X this, PeripheralHandle_t* peripheral, IOPin_t cs)
{
    this->CS =cs;
    this->peripheral = peripheral;
    SGPIO_DirectionGPIO(cs, OUTPUT);
    SGPIO_Write1GPIO(cs);
}

UI08_t MCP355X_Ready(MCP355X this)
{
    UI08_t bf = 0;
    SGPIO_Write0GPIO(this->CS);
    bf = Peripheral_RxPin(this->peripheral);
    SGPIO_Write1GPIO(this->CS);

    if (bf == 0)
        return 1;
    else
        return 0;
}

void MCP355X_Start(MCP355X this)
{
    SGPIO_Write0GPIO(this->CS);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    SGPIO_Write1GPIO(this->CS);

}

UI32_t MCP355X_Read32(MCP355X this)
{
    UI08_t bf[3] = {0,0,0};
    UI32_t v;

    SGPIO_Write0GPIO(this->CS);
    Peripheral_Read(this->peripheral, bf, 3);
    SGPIO_Write1GPIO(this->CS);

    v = bf[0];
    v = v<<8;
    v += bf[1];
    v = v<<8;
    v += bf[2];
    
    return v;

}
UI16_t MCP355X_Read16(MCP355X this)
{
    return (MCP355X_Read32(this)>>8);
}
