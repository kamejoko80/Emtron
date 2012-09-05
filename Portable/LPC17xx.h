/*
 * LPC17xx.h
 *
 *  Created on: Jun 10, 2012
 *      Author: Hans
 */

#ifndef PORT_LPC17XX_H_
#define PORT_LPC17XX_H_

#include "project.h"
#include "../stddefs.h"

/** LPC17XX series **/


// GPIO basics.
#define GPIO_Direction_Input 0
#define GPIO_Direction_Output 1
#define GPIO_SetClr 1

// Definitions for port 0 to 3
#define GPIO_Write0_P0 FIO0CLR
#define GPIO_Write0_P1 FIO1CLR
#define GPIO_Write0_P2 FIO2CLR
#define GPIO_Write0_P3 FIO3CLR

#define GPIO_Write1_P0 FIO0SET
#define GPIO_Write1_P1 FIO1SET
#define GPIO_Write1_P2 FIO2SET
#define GPIO_Write1_P3 FIO3SET

#define GPIO_Read_P0 FIO0PIN
#define GPIO_Read_P1 FIO1PIN
#define GPIO_Read_P2 FIO2PIN
#define GPIO_Read_P3 FIO3PIN

#define GPIO_Tris_P0 FIO0DIR
#define GPIO_Tris_P1 FIO1DIR
#define GPIO_Tris_P2 FIO2DIR
#define GPIO_Tris_P3 FIO3DIR

// Definitions for port A to D
#define GPIO_Write0_PA FIO0CLR
#define GPIO_Write0_PB FIO1CLR
#define GPIO_Write0_PC FIO2CLR
#define GPIO_Write0_PD FIO3CLR

#define GPIO_Write1_PA FIO0SET
#define GPIO_Write1_PB FIO1SET
#define GPIO_Write1_PC FIO2SET
#define GPIO_Write1_PD FIO3SET

#define GPIO_Read_PA FIO0PIN
#define GPIO_Read_PB FIO1PIN
#define GPIO_Read_PC FIO2PIN
#define GPIO_Read_PD FIO3PIN

#define GPIO_Tris_PA FIO0DIR
#define GPIO_Tris_PB FIO1DIR
#define GPIO_Tris_PC FIO2DIR
#define GPIO_Tris_PD FIO3DIR

/** LPC1769 **/

#define PINCOUNT 100

#ifndef PROJECT_H
        #error "There is no project configuration defined!"
#else
    #ifdef OSC_INT_120MHZ
        #define CLOCK_CPU 120000000
        #define CLOCK_PERIPHERAL CLOCK_CPU/2
    #endif
#endif

typedef enum PeripheralType_e
{
    PERIPHERAL_UART_1,
    PERIPHERAL_UART_2,
    PERIPHERAL_UART_3,
    PERIPHERAL_UART_4
} PeripheralType_t;

#define CFG_PERIPHEAL_MAX_DRIVERS sizeof(PeripheralType_t)

#define GPIO_PORT_0
#define GPIO_PORT_1
#define GPIO_PORT_2
#define GPIO_PORT_3

#define IO_P0 0
#define IO_P1 1
#define IO_P2 2
#define IO_P3 3

#define NUM_PORTS 4

extern IOPort_t IOPorts[NUM_PORTS];

#endif /* LPC17XX_H_ */
