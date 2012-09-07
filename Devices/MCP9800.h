#ifndef MCP9800_H
#define MCP9800_H
#include "stddefs.h"
#include "../peripheral.h"


void MCP9800_Init(PeripheralHandle_t* peripheral, BitResolution_t resolution);
void MCP9800_Read(PeripheralHandle_t* peripheral, float* temp);

#endif
