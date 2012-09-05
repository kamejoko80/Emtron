#ifndef MCP23S17_H
#define MCP23S17_h

#include "stddefs.h"
#include "peripheral.h"
typedef struct MCP23S17_t* MCP23S17;

typedef enum MCP23S17_Registers_s
{
	MCP23S17_IODIRA = 0x0,
	MCP23S17_IODIRB,
	MCP23S17_IPOLA,
	MCP23S17_IPOLB,
	MCP23S17_GPINENTA,
	MCP23S17_GPINENTB,
	MCP23S17_DEFVALA,
	MCP23S17_DEFVALB,
	MCP23S17_INTCONA,
	MCP23S17_INTCONB,
	MCP23S17_IOCON,
	MCP23S17_GPPUA = 0x0C,
	MCP23S17_GPPUB,
	MCP23S17_INTFA,
	MCP23S17_INTFB,
	MCP23S17_INTCAPA,
	MCP23S17_INTCAPB,
	MCP23S17_GPIOA,
	MCP23S17_GPIOB,
	MCP23S17_OLATA,
	MCP23S17_OLATB
} MCP23S17_Registers_t;

typedef enum MCP23S17Mode
{
    MCP23S17_SoftSPI,
    MCP23S17_SPI1,
    MCP23S17_SPI2,
    MCP23S17_SPI3,
    MCP23S17_SPI4
} MCP23S17Mode;

typedef struct MCP23S17_t
{
    MCP23S17Mode mode:3;
    UI08_t address:3;
    UI08_t init:1;
    PeripheralHandle_t* peripheral; // soft SPI or SPI peripheral instance
    IOPin_t CS; // chip select IO pin
    
} MCP23S17_t;

void MCP23S17_Mode(MCP23S17 this, MCP23S17Mode mode);
void MCP23S17_Init(MCP23S17 this, PeripheralHandle_t* peripheral, UI08_t address, IOPin_t cs);

void MCP23S17_Write(MCP23S17 this, MCP23S17_Registers_t reg, UI08_t value);
UI08_t MCP23S17_Read(MCP23S17 this, MCP23S17_Registers_t reg);


#endif
