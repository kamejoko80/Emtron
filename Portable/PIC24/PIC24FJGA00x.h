
#ifndef PORT_PIC24FJ32GA002_H
#define PORT_PIC24FJ32GA002_H 1

#include "Portable/PIC24/PIC24.h"
#include "RTOS/stddefs.h"
#include "project.h"

#ifdef PORTABLE_PIC24FJGA00x

    #ifdef PORTABLE_PIC24FJGA002
        #define NUM_PORTS 2
        #define PINCOUNT 28
        #define PORTABLE_CONFIG2 I2C1SEL_PRI & IOL1WAY_OFF
    #endif

    #ifdef PORTABLE_PIC24FJGA004
        #define NUM_PORTS 3
        #define PINCOUNT 44
        #define PORTABLE_CONFIG2 I2C1SEL_PRI & IOL1WAY_OFF
    #endif

    #ifdef PORTABLE_PIC24FJGA006
        #define NUM_PORTS 6
        #define PINCOUNT 64
    #endif

    #ifdef PORTABLE_PIC24FJGA008
        #define NUM_PORTS 6
        #define PINCOUNT 80
    #endif

    #ifdef PORTABLE_PIC24FJGA010
        #define NUM_PORTS 6
        #define PINCOUNT 100
    #endif

    #ifndef PORTABLE_CONFIG2
    #define PORTABLE_CONFIG2 0xFFFF
    #endif

    #ifndef PROJECT_H
            #error "There is no project configuration defined!"
    #else
        #ifdef OSC_INT_32MHZ
            #define CFG_RCDIV 0
            #ifdef MAIN_C
                _CONFIG1(WDTPS_PS1 & FWPSA_PR32 & WINDIS_OFF & FWDTEN_OFF & ICS_PGx1 & GWRP_OFF & GCP_OFF & JTAGEN_OFF)
                _CONFIG2(POSCMOD_NONE & OSCIOFNC_ON & FCKSM_CSDCMD & FNOSC_FRCPLL & IESO_ON & PORTABLE_CONFIG2)
            #endif
            #define CLOCK_CPU 4000000
            #define CLOCK_PERIPHERAL CLOCK_CPU/2
        #endif
    #endif

    typedef enum PeripheralType_e
    {
        PERIPHERAL_UART_1,
        PERIPHERAL_UART_2,
        PERIPHERAL_SOFTSPI,
        PERIPHERAL_SOFTI2C
    } PeripheralType_t;

    extern const IOPort_t IOPorts[NUM_PORTS];

#endif

#endif