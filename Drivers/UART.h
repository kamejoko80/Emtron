#ifndef TRITON_UART_H
#define TRITON_UART_H

#include "../portable.h"
#include "../peripheral_inf.h"

/*
typedef struct UartHandle_s
{

} UartHandle_t;*/


void  Uart_Init(PeripheralHandle_t* handle);
void* Uart_Mode(PeripheralHandle_t* handle, PeripheralModeReg_t mode, void* data);
void  Uart_Tx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length);
void  Uart_Rx(PeripheralHandle_t* handle, UI08_t* buf, UI16_t length);

UI08_t Uart_RxByte(PeripheralHandle_t* handle);
void Uart_TxByte(PeripheralHandle_t* handle, UI08_t b);

#endif
