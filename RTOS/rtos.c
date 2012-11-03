#include "RTOS/rtos.h"
#include "Drivers/uart.h"

#ifdef RTOS_TRACE
inline  void RTOS_Trace(RTOS_Trace_Message_t message, UI08_t argl, void* arg)
{
    // Do trace on the specified port
    Uart_TxByte(RTOS_TRACE_PORT, 0x7F);
    Uart_TxByte(RTOS_TRACE_PORT, message);
    if(argl == 1)
        Uart_TxByte(RTOS_TRACE_PORT, (UI08_t) arg);
    else
        Uart_Tx(RTOS_TRACE_PORT, arg, argl);
}

#endif

