#include "Devices/MCP9800.h"

void MCP9800_Init(PeripheralHandle_t* peripheral, BitResolution_t resolution)
{
    UI08_t bf[3];
    bf[0] = 0b10010000;
    bf[1] = 0x01;
    bf[2] = 0b10000000;
    
    if(resolution == RESOLUTION_10BIT)
        bf[2] |= 0b00100000;
    if(resolution == RESOLUTION_11BIT)
        bf[2] |= 0b01000000;
    if(resolution == RESOLUTION_12BIT)
        bf[2] |= 0b01100000;

    // Write register 1
    Peripheral_SendStart(peripheral);
    Peripheral_Write(peripheral, bf, 3);
    Peripheral_SendStop(peripheral);

    bf[0] = 0b10010000;
    bf[1] = 0x00;
    
    // Set back to reading register 0
    Peripheral_SendStart(peripheral);
    Peripheral_Write(peripheral, bf, 2);
    Peripheral_SendStop(peripheral);
}

void MCP9800_Read(PeripheralHandle_t* peripheral, float* temp)
{
    UI08_t bf[3];
    bf[0] = 0b10010001;
    bf[1] = 0;
    Peripheral_SendStart(peripheral);
    Peripheral_Write(peripheral, bf, 1);
    Peripheral_Read (peripheral, bf, 2);
    Peripheral_SendStop(peripheral);

    *temp = ((SI08_t)bf[0])*1.0f + 0.003125f*(bf[1]);
}
