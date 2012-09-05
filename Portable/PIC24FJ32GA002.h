
#ifndef PORT_PIC24FJ32GA002_H
#define PORT_PIC24FJ32GA002_H 1

#include "_PIC24.h"
#include "project.h"
#include "../stddefs.h"

//#ifdef __PIC24FJ32GA002__
#define PINCOUNT 28

#ifndef PROJECT_H
        #error "There is no project configuration defined!"
#else
    #ifdef OSC_INT_32MHZ
        #define CFG_RCDIV 0
        #ifdef MAIN_C
            _CONFIG1(WDTPS_PS1 & FWPSA_PR32 & WINDIS_OFF & FWDTEN_OFF & ICS_PGx1 & GWRP_OFF & GCP_OFF & JTAGEN_OFF)
            _CONFIG2(POSCMOD_NONE & I2C1SEL_PRI & IOL1WAY_OFF & OSCIOFNC_ON & FCKSM_CSDCMD & FNOSC_FRCPLL & IESO_ON)
        #endif
        #define CLOCK_CPU 32000000
        #define CLOCK_PERIPHERAL 16000000
    #endif
#endif

typedef enum PeripheralType_e
{
    PERIPHERAL_UART_1,
    PERIPHERAL_UART_2,
    PERIPHERAL_SOFTSPI,
    PERIPHERAL_SOFTI2C
} PeripheralType_t;

#define GPIO_PORT_A
#define GPIO_PORT_B
#define GPIO_PORT_C

#define IO_PA 0
#define IO_PB 1
#define IO_PC 2

//#define GPIO(port, pin) (IOPin_t){IO_##port, ##pin}

#if PINCOUNT==44
    #define NUM_PORTS 3
    #define IO_PC 2
#else
    #define NUM_PORTS 2
#endif

extern IOPort_t IOPorts[NUM_PORTS];

//#endif
#endif
