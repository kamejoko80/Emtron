#include "../portable.h"
#include "../peripheral.h"
#include "hardware.h"

#ifdef __dsPIC33FJ128GP802__
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
    AD1PCFGL = 0xFFFF;           // Initially configurate everything as analog ports.

    int i=0;
    for (i = 0 ; i < HARDWARE_LEDCOUNT; i++)
    {
        SGPIO_Direction(LEDs[i].port, LEDs[i].pin, OUTPUT);
    }

    // Register all peripherals in the peripheral driver.
    Peripheral_Register(PERIPHERAL_UART_1, 1, Uart_Init, Uart_Mode, Uart_Tx, Uart_Rx);
    Peripheral_Register(PERIPHERAL_UART_2, 2, Uart_Init, Uart_Mode, Uart_Tx, Uart_Rx);
}


/** TAKEN FROM EXAMPLES*/
void clrClkFail(void);

void __attribute__((__interrupt__)) _OscillatorFail(void);
void __attribute__((__interrupt__)) _AddressError(void);
void __attribute__((__interrupt__)) _StackError(void);
void __attribute__((__interrupt__)) _MathError(void);
void __attribute__((__interrupt__)) _DMACError(void);

void __attribute__((__interrupt__)) _AltOscillatorFail(void);
void __attribute__((__interrupt__)) _AltAddressError(void);
void __attribute__((__interrupt__)) _AltStackError(void);
void __attribute__((__interrupt__)) _AltMathError(void);
void __attribute__((__interrupt__)) _AltDMACError(void);

/*
Primary Exception Vector handlers:
These routines are used if INTCON2bits.ALTIVT = 0.
All trap service routines in this file simply ensure that device
continuously executes code within the trap service routine. Users
may modify the basic framework provided here to suit to the needs
of their application.
*/

/*On encountering a clock failure, if the fail-safe clock monitor (FSCM)
is enabled, device executes code using the FRC oscillator and code execution
reaches the Oscillatore Fail trap
*/

void __attribute__((interrupt, no_auto_psv)) _OscillatorFail(void)
{
        INTCON1bits.OSCFAIL = 0;        //Clear the trap flag
        while (1);

}

void __attribute__((interrupt, no_auto_psv)) _AddressError(void)
{
        INTCON1bits.ADDRERR = 0;        //Clear the trap flag
        while (1);
}
void __attribute__((interrupt, no_auto_psv)) _StackError(void)
{
        INTCON1bits.STKERR = 0;         //Clear the trap flag
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _MathError(void)
{
        INTCON1bits.MATHERR = 0;        //Clear the trap flag
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _DMACError(void)
{
        INTCON1bits.DMACERR = 0;        //Clear the trap flag
        while (1);
}





/*
Alternate Exception Vector handlers:
These routines are used if INTCON2bits.ALTIVT = 1.
All trap service routines in this file simply ensure that device
continuously executes code within the trap service routine. Users
may modify the basic framework provided here to suit to the needs
of their application.
*/

void __attribute__((interrupt, no_auto_psv)) _AltOscillatorFail(void)
{
        INTCON1bits.OSCFAIL = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltAddressError(void)
{
        INTCON1bits.ADDRERR = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltStackError(void)
{
        INTCON1bits.STKERR = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltMathError(void)
{
        INTCON1bits.MATHERR = 0;
        while (1);
}

void __attribute__((interrupt, no_auto_psv)) _AltDMACError(void)
{
        INTCON1bits.DMACERR = 0;        //Clear the trap flag
        while (1);
}


#endif