
#ifndef PORT_DSPIC33FJ128GP802_H
#define PORT_DSPIC33FJ128GP802_H 1

#include "_PIC33.h"
#include "project.h"
#include "pps.h"
#include "../stddefs.h"

//#ifdef __PIC24FJ32GA002__
#define PINCOUNT 28

#ifndef PROJECT_H
        #error "There is no project configuration defined!"
#else
    #ifdef OSC_INT_40MHZ
        #define CFG_RCDIV 0
        #ifdef MAIN_C
        _FBS(BWRP_WRPROTECT_OFF);      // No Boot Protect
        _FGS(GSS_OFF);              // No Code Protect
        _FOSCSEL(FNOSC_FRCPLL);            // Fast RC to start
        _FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_NONE);
        // Primary disabled, clock switch, no monitor, allow multiple IOLOCKs
        _FWDT(FWDTEN_OFF);            // Turn off Watchdog Timer
        _FPOR(FPWRT_PWR1);            // Power-up Timer to 16msecs
        _FICD(ICS_PGD2 & JTAGEN_OFF);   // Use PGC/D 2, no JTAG
        #endif
        #define CLOCK_CPU 40000000
        #define CLOCK_PERIPHERAL CLOCK_CPU/2
    #endif
#endif

typedef enum PeripheralType_e
{
    PERIPHERAL_UART_1,
    PERIPHERAL_UART_2
} PeripheralType_t;
#define CFG_PERIPHEAL_MAX_DRIVERS sizeof(PeripheralType_t)

#define GPIO_PORT_A
#define GPIO_PORT_B
#define GPIO_PORT_C

#define IO_PA 0
#define IO_PB 1
#define IO_PC 1

#if PINCOUNT==44
    #define NUM_PORTS 3
    #define IO_PC 2
#else
    #define NUM_PORTS 2
#endif

extern IOPort_t IOPorts[NUM_PORTS];

//#endif
#endif
