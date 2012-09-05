#ifndef MCP355X_H
#define MCP355X_H

#include "stddefs.h"
#include "../peripheral.h"
#include "../peripheral_inf.h"

typedef struct MCP355X_t* MCP355X;

typedef struct MCP355X_t
{
    IOPin_t CS;
    PeripheralHandle_t* peripheral;
} MCP355X_t;


void MCP355X_Init(MCP355X this, PeripheralHandle_t* peripheral, IOPin_t cs);
void MCP355X_Start(MCP355X this);
UI32_t MCP355X_Read32(MCP355X this);
UI16_t MCP355X_Read16(MCP355X this);

#endif

