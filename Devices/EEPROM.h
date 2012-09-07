#ifndef EEPROM_H
#define EEPROM_H

#include "stddefs.h"
#include "task.h"
#include "peripheral.h"

typedef struct EEPROM_t* EEPROM;

// Messy I know.
typedef union EEPROMSelector_t
{
        IOPin_t CS;
        UI08_t AddressMask;
} EEPROMSelector_t;

#define EEPROMSelectAddressMask(b) ((EEPROMSelector_t) {(UI08_t)b})
#define EEPROMSelectPin(port, pin) ((EEPROMSelector_t){GPIO(port, pin)})

typedef struct EEPROM_t
{
    // Commands
    UI08_t ReadCommand;
    UI08_t WriteCommand;

    // Addressing
    UI08_t DoubleByteAddress:1;
    UI08_t UseStartStop:1;
    UI08_t ChipSelect:1;
    UI08_t Banks:1;
    UI08_t BankBit0:3;
    UI08_t BankBit1:3;
    UI08_t BankBit2:3;
    
    UI08_t PageSize;
    UI08_t PageWriteTime;

    HandlerPtr_ptr_t fncPrepareWrite;

    EEPROMSelector_t Selector;
    PeripheralHandle_t* peripheral;
} EEPROM_t;

//TODO:
// Place EEPROM struct into ROM and only variables Selector & Peripheral into RAM.

void EEPROM_Initialize(EEPROM this, PeripheralHandle_t* ph, EEPROMSelector_t select);

void   EEPROM_WriteByte(EEPROM this, UI16_t addr, UI08_t data);
UI08_t EEPROM_ReadByte (EEPROM this, UI16_t addr);

void EEPROM_Write(EEPROM this, UI16_t addr, UI08_t* data, UI16_t length);
void EEPROM_Read (EEPROM this, UI16_t addr, UI08_t* data, UI16_t length);

void _EEPROM_PrepareWrite_25AA(EEPROM this);

//I2C
#define EEPROM_24AA01   {0b10100001, 0b10100000, 0, 1, 0, 0, 0, 0, 0, 16, 25, NULL, 0, NULL}
#define EEPROM_24AA02   {0b10100001, 0b10100000, 0, 1, 0, 0, 0, 0, 0, 16, 25, NULL, 0, NULL}
#define EEPROM_24AA04   {0b10100001, 0b10100000, 0, 1, 0, 1, 7, 0, 0, 16, 25, NULL, 0, NULL}
#define EEPROM_24AA08   {0b10100001, 0b10100000, 0, 1, 0, 1, 7, 6, 0, 16, 25, NULL, 0, NULL}
#define EEPROM_24AA16   {0b10100001, 0b10100000, 0, 1, 0, 1, 7, 6, 5, 16, 25, NULL, 0, NULL}
#define EEPROM_24AA512  {0b10100001, 0b10100000, 1, 1, 0, 0, 0, 0, 0, 16, 25, NULL, 0, NULL}
#define EEPROM_24AA1025 {0b10100001, 0b10100000, 1, 1, 0, 1, 5, 0, 0, 16, 25, NULL, 0, NULL}

//SPI
#define EEPROM_25AA040A {0b00000011, 0b00000010, 0, 0, 1, 1, 4, 0, 0, 16, 25, _EEPROM_PrepareWrite_25AA, 0, NULL}

#endif

