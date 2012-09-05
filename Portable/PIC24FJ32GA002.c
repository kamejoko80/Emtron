#include "../portable.h"
#include "../peripheral.h"
#include "../stddefs.h"
#include "hardware.h"

#ifdef __PIC24FJ32GA002__
IOPort_t IOPorts[NUM_PORTS] = {
        {PTR16(0x2C0), PTR16(0x2C2), PTR16(0x2C4), PTR16(0x2C6)},
        {PTR16(0x2C8), PTR16(0x2CA), PTR16(0x2CC), PTR16(0x2CE)}
#if PINCOUNT==44
        ,{PTR16(0x2D0), PTR16(0x2D2), PTR16(0x2D4), PTR16(0x2D6)}
#endif
};

void FW_Init(void)
{
    // Initialize the CPU clock.
    CLKDIV  = CFG_RCDIV << 8;   // bit 10-8 RCDIV. 000 to 111 - 8MHz to 31.25kHz
    AD1PCFG = 0xFFFF;           // Initially configurate everything as analog ports.

    int i=0;
    for (i = 0 ; i < HARDWARE_LEDCOUNT; i++)
    {
        SGPIO_Direction(LEDs[i].port, LEDs[i].pin, OUTPUT);
    }

    // Register all peripherals in the peripheral driver.
    //Peripheral_Register(PERIPHERAL_UART_1, 1, Uart_Init, Uart_Mode, Uart_Tx, Uart_Rx);
    //Peripheral_Register(PERIPHERAL_UART_2, 2, Uart_Init, Uart_Mode, Uart_Tx, Uart_Rx);
}
#endif
