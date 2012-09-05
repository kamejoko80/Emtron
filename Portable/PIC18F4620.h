
#ifndef PORT_PIC24FJ32GA002_H
#define PORT_PIC24FJ32GA002_H 1

#include <p18f4620.h>
#include "_PIC18.h"
#include "project.h"
#include "stddefs.h"

#ifdef __18F4620
#define PINCOUNT 40

#ifndef PROJECT_H
        #error "There is no project configuration defined!"
#else
    #define CLOCK_CPU 40000000
    #define CLOCK_PERIPHERAL 10000000
#endif

typedef enum PeripheralType_e
{
    PERIPHERAL_UART_1
} PeripheralType_t;
#define CFG_PERIPHEAL_MAX_DRIVERS sizeof(PeripheralType_t)

#define GPIO_PORT_A
#define GPIO_PORT_B
#define GPIO_PORT_C

#define IO_PA 0
#define IO_PB 1
#define IO_PC 2

#if PINCOUNT==40
    #define NUM_PORTS 3
#endif

extern IOPort_t IOPorts[NUM_PORTS];

#endif
#endif
