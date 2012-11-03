#ifndef TRITON_PERIPHERAL
#define TRITON_PERIPHERAL

#include "RTOS/stddefs.h"
#include "RTOS/task.h"
#include "RTOS/portable.h"
#include "RTOS/peripheral_inf.h"

typedef struct PeripheralDriver_s
{
    PeripheralType_t type:4;
    UI08_t peripheral:4;
    
    UI08_t TaskHandleTx:4;
    UI08_t TaskHandleRx:4;

    // Underlying methods used.
    HandlerInit     fncInit;
    HandlerMode     fncMode;
    HandlerTRx      fncTx;
    HandlerTRx      fncRx;
    HandlerTxRx     fncTxRx;
    HandlerPin      fncRxPin;

} PeripheralDriver_t;

extern UI08_t __PeripheralDataHeap[CFG_PERIPHERAL_HEAPSIZE];
extern PeripheralDriver_t __PeripheralDrivers[CFG_PERIPHEAL_MAX_DRIVERS];
extern PeripheralHandle_t __PeripheralHandles[CFG_PERIPHEAL_MAX_HANDLES];

void Peripheral_Register(PeripheralType_t type, UI08_t id, HandlerInit fncInit, HandlerMode fncMode, HandlerTRx fncTx, HandlerTRx fncRx, HandlerTxRx fncTxRx, HandlerPin fncRxPin);

PeripheralHandle_t* Peripheral_Open( PeripheralType_t type, void* args);
PeripheralResult_t Peripheral_Mode( PeripheralHandle_t* peripheral, PeripheralModeReg_t reg, void* data);
PeripheralResult_t Peripheral_Read( PeripheralHandle_t* peripheral, UI08_t* buffer, UI08_t bytes);
UI08_t Peripheral_RxPin(PeripheralHandle_t* peripheral);
PeripheralResult_t Peripheral_Write( PeripheralHandle_t* peripheral, UI08_t* buffer, UI08_t bytes);
PeripheralResult_t Peripheral_ReadWrite( PeripheralHandle_t* peripheral, UI08_t* tx_buffer, UI08_t* rx_buffer, UI08_t bytes);
void Peripheral_Close( PeripheralHandle_t* peripheral);

void Peripheral_SendStart(PeripheralHandle_t* peripheral);
void Peripheral_SendStop(PeripheralHandle_t* peripheral);

#endif
