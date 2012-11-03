#include "Devices/EEPROM.h"

void EEPROM_WriteBytes(EEPROM this, UI16_t addr, UI08_t* data, UI16_t length);
void EEPROM_ReadBytes (EEPROM this, UI16_t addr, UI08_t* data, UI16_t length);

void _EEPROM_PrepareWrite_25AA(EEPROM this)
{
    UI08_t bf[2];
    bf[0] = 0b00000110; //WRSR
    SGPIO_Write0GPIO(this->Selector.CS);
    Peripheral_Write(this->peripheral, bf, 1);
    SGPIO_Write1GPIO(this->Selector.CS);

}

void EEPROM_Initialize(EEPROM this, PeripheralHandle_t* ph, EEPROMSelector_t select)
{
    this->peripheral = ph;
    this->Selector = select;

    if (this->ChipSelect)
    {
        SGPIO_DirectionGPIO(select.CS, OUTPUT);
        SGPIO_Write1GPIO(select.CS);
    }
}

void EEPROM_WriteByte(EEPROM this, UI16_t addr, UI08_t data)
{
    UI08_t bf[4], i;
    bf[0] = this->WriteCommand;

    if (this->DoubleByteAddress)
    {
        bf[1] = (addr&0xFF00)>>8;
        bf[2] = addr & 0xFF;
        bf[3] = data;
        i = 4;
    }
    else
    {
        bf[1] = addr;
        bf[2] = data;
        i = 3;
    }

    if (this->UseStartStop) Peripheral_SendStart(this->peripheral);
    if (this->ChipSelect)
    {
        SGPIO_Write0GPIO(this->Selector.CS);
    }
    else
    {
        bf[0] = bf[0] | this->Selector.AddressMask;
    }
    Peripheral_Write(this->peripheral, bf, i);
    if (this->ChipSelect) SGPIO_Write1GPIO(this->Selector.CS);
    if (this->UseStartStop) Peripheral_SendStop(this->peripheral);
}

UI08_t EEPROM_ReadByte(EEPROM this, UI16_t addr)
{
    UI08_t bf[3], i = 1;
    bf[0] = this->ReadCommand;
    if (this->DoubleByteAddress)
    {
        bf[1] = (addr&0xFF00)>>8;
        i++;
    }

    bf[i] = addr & 0xFF;    i++;
    
    if (this->UseStartStop) Peripheral_SendStart(this->peripheral);
    if (this->ChipSelect)
    {
        SGPIO_Write0GPIO(this->Selector.CS);
    }
    else
    {
        bf[0] = bf[0] | this->Selector.AddressMask;
    }
    Peripheral_Write(this->peripheral, bf, i);
    Peripheral_Read (this->peripheral, bf, 1);
    if (this->ChipSelect) SGPIO_Write1GPIO(this->Selector.CS);
    if (this->UseStartStop) Peripheral_SendStop(this->peripheral);
    return bf[0];
}

void EEPROM_Write(EEPROM this, UI16_t addr, UI08_t* d, UI16_t length)
{
    UI08_t size = 0;
    UI08_t* data = d;
    while(length>0)
    {
        if(addr % this->PageSize == 0)
            size = this->PageSize;
        else
            size = this->PageSize - (addr % this->PageSize);
        if (length < size)
            size = length;
        
        EEPROM_WriteBytes(this, addr, data, size);
        addr+=size;
        data+= size;
        length-=size;

        if (addr % this->PageSize == 0)
            // SLEEP
            Task_Sleep(this->PageWriteTime);

    }
}
void EEPROM_Read (EEPROM this, UI16_t addr, UI08_t* data, UI16_t length)
{
        EEPROM_ReadBytes(this, addr, data, length);
}



void EEPROM_WriteBytes(EEPROM this, UI16_t addr, UI08_t* d, UI16_t length)
{
    if (this->fncPrepareWrite != NULL)
        this->fncPrepareWrite((void*)this);
    
    UI08_t bf[3], i;
    UI08_t* data = d;
    bf[0] = this->WriteCommand;

    if (this->DoubleByteAddress)
    {
        bf[1] = (addr&0xFF00)>>8;
        bf[2] = addr & 0xFF;
        i = 3;
    }
    else
    {
        bf[1] = addr;
        i = 2;
    }

    if (this->UseStartStop) Peripheral_SendStart(this->peripheral);
    if (this->ChipSelect)
    {
        SGPIO_Write0GPIO(this->Selector.CS);
    }
    else
    {
        bf[0] = bf[0] | this->Selector.AddressMask;
    }
    Peripheral_Write(this->peripheral, bf, i);
    Peripheral_Write(this->peripheral, data, length);
    if (this->ChipSelect) SGPIO_Write1GPIO(this->Selector.CS);
    if (this->UseStartStop) Peripheral_SendStop(this->peripheral);
}

void EEPROM_ReadBytes (EEPROM this, UI16_t addr, UI08_t* data, UI16_t length)
{
    UI08_t bf[3], i = 1;

    // No chip select is probably I2C, so first write, then read.
    if (!this->ChipSelect && this->UseStartStop)
    {
        bf[0] = this->WriteCommand | this->Selector.AddressMask;
    }
    else
    {
        bf[0] = this->ReadCommand;
    }
    if (this->DoubleByteAddress)
    {
        bf[1] = (addr&0xFF00)>>8;
        i++;
    }

    bf[i] = addr & 0xFF;    i++;

    if (this->UseStartStop) Peripheral_SendStart(this->peripheral);
    if (this->ChipSelect)
    {
        SGPIO_Write0GPIO(this->Selector.CS);
    }
    Peripheral_Write(this->peripheral, bf, i);

    // No chip select? Probably I2C..
    if (!this->ChipSelect && this->UseStartStop)
    {
        if (this->UseStartStop) Peripheral_SendStart(this->peripheral);
        bf[0] = this->ReadCommand | this->Selector.AddressMask;
        Peripheral_Write(this->peripheral, bf, 1);
    }

    // Read the precious data.
    Peripheral_Read (this->peripheral, data, length);
    
    if (this->ChipSelect) SGPIO_Write1GPIO(this->Selector.CS);
    if (this->UseStartStop) Peripheral_SendStop(this->peripheral);
}

