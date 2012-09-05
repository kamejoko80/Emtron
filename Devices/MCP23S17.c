
#include "Devices/MCP23S17.h"
#include "stddefs.h"
#include "portable.h"
#include "peripheral.h"

void MCP23S17_Init(MCP23S17 this, PeripheralHandle_t* peripheral, UI08_t address, IOPin_t cs)
{
    this->peripheral = peripheral;
    this->address = address;
    this->CS = cs;
    this->init = 0;

    SGPIO_DirectionGPIO(cs, OUTPUT);
    SGPIO_Write1GPIO(cs);

    // Set up IOCON
    // Enable addressing (BIT 3: HAEN) MCP23S17_IOCON
    MCP23S17_Write(this, MCP23S17_IOCON, 0b00001000);

    this->init = 1;
}

void MCP23S17_Write(MCP23S17 this, MCP23S17_Registers_t reg, UI08_t value)
{
    UI08_t bf[3];

    if(this->init == 0)
        bf[0] = 0x1<<6;
    else
        bf[0] = (this->address << 1) + (0x1 << 6);
    bf[1] = reg;
    bf[2] = value;
    SGPIO_Write0GPIO(this->CS);

    Peripheral_Write(this->peripheral, bf, 3);

    SGPIO_Write1GPIO(this->CS);
}

UI08_t MCP23S17_Read(MCP23S17 this, MCP23S17_Registers_t reg)
{
    UI08_t bf[2];

    bf[0] = 0x1 + (this->address << 1) + (0x1 << 6);
    bf[1] = reg;
    SGPIO_Write0GPIO(this->CS);

    Peripheral_Write(this->peripheral, bf, 2);
    Peripheral_Read(this->peripheral, bf, 1);

    SGPIO_Write1GPIO(this->CS);

    return bf[0];
}
