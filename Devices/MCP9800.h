#ifndef EMTRON_DEVICES_MCP9800_H
#define EMTRON_DEVICES_MCP9800_H
#include "RTOS/stddefs.h"
#include "RTOS/peripheral.h"


void MCP9800_Init(PeripheralHandle_t* peripheral, BitResolution_t resolution);
void MCP9800_Read(PeripheralHandle_t* peripheral, float* temp);

#endif
