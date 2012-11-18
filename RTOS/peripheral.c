#include "RTOS/peripheral.h"
#include "RTOS/task.h"

UI08_t __PeripheralDataHeap[CFG_PERIPHERAL_HEAPSIZE];
PeripheralDriver_t __PeripheralDrivers[CFG_PERIPHEAL_MAX_DRIVERS];
PeripheralHandle_t __PeripheralHandles[CFG_PERIPHEAL_MAX_HANDLES];


void Peripheral_Register(PeripheralType_t type, UI08_t id, HandlerInit fncInit, HandlerMode fncMode, HandlerTRx fncTx, HandlerTRx fncRx, HandlerTxRx fncTxRx, HandlerPin fncRxPin)
{
    // TODO: look up free spot
    // register it.
    PeripheralDriver_t* drv = &(__PeripheralDrivers[(UI08_t)type]); //convert type to int
    
    drv->type           = type;
    drv->fncInit        = fncInit;
    drv->fncMode        = fncMode;
    drv->fncRx          = fncRx;
    drv->fncTx          = fncTx;
    drv->fncTxRx        = fncTxRx;
    drv->fncRxPin       = fncRxPin;
    drv->peripheral     = id;

    drv->TaskHandleRx   = 0xF;
    drv->TaskHandleTx   = 0xF;
}

PeripheralHandle_t* Peripheral_Open( PeripheralType_t type, void* args)
{
    UI08_t i = 0;
    PeripheralHandle_t* hndl = NULL;

    // Check for existing.
    for(i = 0; i < CFG_PERIPHEAL_MAX_HANDLES; i++)
    {
        if(__PeripheralHandles[i].Driver == type)
        {
            hndl = &(__PeripheralHandles[i]);
            break;
        }
    }
    
    // No handle? Create new
    if (hndl == NULL)
    {
        for(i = 0; i < CFG_PERIPHEAL_MAX_HANDLES; i++)
        {
            if(__PeripheralHandles[i].Use == 0)
            {
                hndl = &(__PeripheralHandles[i]);
                hndl->Use = 1;
                hndl->Driver = type;
                hndl->StateRx = PS_OPEN;
                hndl->StateTx = PS_OPEN;

                // In this case, call init function.
                __PeripheralDrivers[type].fncInit(hndl, args);

                break;
            }
        }
    }
    if (hndl == NULL)
        return NULL;

    return hndl;
    
}

PeripheralResult_t Peripheral_Mode( PeripheralHandle_t* peripheral, PeripheralModeReg_t reg, void* data)
{
    int timeout = (int) data;
    switch(reg)
    {

        case MODE_RX_POLL:
        case MODE_RX_BUFFER:
        case MODE_RX_RTOS:
            do
            {
                if (peripheral->StateRx == PS_OPEN)
                {
                    // Reserve this.
                    if(reg == MODE_RX_POLL)
                        peripheral->StateRx = PS_POLL_RX_IDLE;
                    else
                        peripheral->StateRx = PS_BUF_RX_IDLE;
                    peripheral->TaskRx = Task_Active->ID;
                    return PR_OK;
                }
                //Timeout 0 -> instant access
                if(timeout == 0)
                    return PR_BLOCKED;

                // Timeout < 0 -> Timeout
                if(timeout <= 0)
                    return PR_TIMEOUT;

                timeout-=25;
                Task_Sleep(25);
            }
            while(peripheral->TaskRx != Task_Active->ID);
            peripheral->TaskRx = Task_Active->ID;
            return PR_OK;

            break;
            
        case MODE_TX_POLL:
        case MODE_TX_BUFFER:
        case MODE_TX_RTOS:
            do
            {
                if (peripheral->StateTx == PS_OPEN)
                {
                    // Reserve this.
                    if(reg == MODE_TX_POLL)
                        peripheral->StateTx = PS_POLL_TX_IDLE;
                    else
                        peripheral->StateTx = PS_BUF_TX_IDLE;
                    peripheral->TaskTx = Task_Active->ID;
                    return PR_OK;

                }
                //Timeout 0 -> instant access
                if(timeout == 0)
                    return PR_BLOCKED;

                // Timeout < 0 -> Timeout
                if(timeout <= 0)
                    return PR_TIMEOUT;
                
                timeout-=25;
                Task_Sleep(25);
            }
            while(peripheral->TaskTx != Task_Active->ID);
            peripheral->TaskTx = Task_Active->ID;
            return PR_OK;
            
            break;


        // Any remaining register are for the driver.
        default:
            return __PeripheralDrivers[peripheral->Driver].fncMode(peripheral, reg, data);
            break;
    }
    
}
PeripheralResult_t Peripheral_Read( PeripheralHandle_t* peripheral, UI08_t* buffer, UI08_t bytes)
{
    // Is it locked by another task?
    if(peripheral->TaskRx != Task_Active->ID)
        return PR_BLOCKED;
    return __PeripheralDrivers[peripheral->Driver].fncRx(peripheral, buffer, bytes);

}

UI08_t Peripheral_RxPin(PeripheralHandle_t* peripheral)
{
    if(peripheral->TaskRx != Task_Active->ID)
        return 0xFF;
    return __PeripheralDrivers[peripheral->Driver].fncRxPin(peripheral);
}

PeripheralResult_t Peripheral_Write( PeripheralHandle_t* peripheral, UI08_t* buffer, UI08_t bytes)
{
    // Is it locked by another task?
    if(peripheral->TaskTx != Task_Active->ID)
        return PR_BLOCKED;
    
    return __PeripheralDrivers[peripheral->Driver].fncTx(peripheral, buffer, bytes);

}

void Peripheral_Close( PeripheralHandle_t* peripheral)
{
    if(peripheral->TaskRx == Task_Active->ID)
    {
        peripheral->StateRx = PS_OPEN;
        peripheral->TaskRx = 0xFF;
    }
    if(peripheral->TaskTx == Task_Active->ID)
    {
        peripheral->StateTx = PS_OPEN;
        peripheral->TaskTx = 0xFF;
    }
}


void Peripheral_SendStart(PeripheralHandle_t* peripheral)
{
    Peripheral_Mode(peripheral, MODE_START, null);
}
void Peripheral_SendStop(PeripheralHandle_t* peripheral)
{
    Peripheral_Mode(peripheral, MODE_STOP, null);
}
