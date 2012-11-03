#ifndef PORTABLE_PIC24_H
#define PORTABLE_PIC24_H

/*******************************   Devices   *********************************/
#ifdef __PIC24FJ16GA002__
#define PORTABLE_PIC24FJGA002
#endif
#ifdef __PIC24FJ32GA002__
#define PORTABLE_PIC24FJGA002
#endif
#ifdef __PIC24FJ48GA002__
#define PORTABLE_PIC24FJGA002
#endif
#ifdef __PIC24FJ64GA002__
#define PORTABLE_PIC24FJGA002
#endif
#ifdef __PIC24FJ16GA004__
#define PORTABLE_PIC24FJGA004
#endif
#ifdef __PIC24FJ32GA004__
#define PORTABLE_PIC24FJGA004
#endif
#ifdef __PIC24FJ48GA004__
#define PORTABLE_PIC24FJGA004
#endif
#ifdef __PIC24FJ64GA004__
#define PORTABLE_PIC24FJGA004
#endif
#ifdef __PIC24FJ64GA006__
#define PORTABLE_PIC24FJGA006
#endif
#ifdef __PIC24FJ92GA006__
#define PORTABLE_PIC24FJGA006
#endif
#ifdef __PIC24FJ128GA006__
#define PORTABLE_PIC24FJGA006
#endif

/******************************* Basic devices ********************************/
#ifdef PORTABLE_PIC24FJGA002
#define TARGET_PIC24
#define PORTABLE_PIC24FJGA00x
#endif

#ifdef PORTABLE_PIC24FJGA004
#define TARGET_PIC24
#define PORTABLE_PIC24FJGA00x
#endif

#ifdef PORTABLE_PIC24FJGA006
#define TARGET_PIC24
#define PORTABLE_PIC24FJGA00x
#endif


/******************************* PIC24 Generic ********************************/
#ifdef TARGET_PIC24

    #include "p24Fxxxx.h"

    #define GPIO_Direction_Output 0
    #define GPIO_Direction_Input 1

    /****************************** Header files ******************************/
    #ifdef PORTABLE_PIC24FJGA00x
    #include "Portable/PIC24/PIC24FJGA00x.h"
    #endif

    #include "Portable/PIC24/kernel.h"
    #include "Portable/PIC24/timer.h"

#if NUM_PORTS >= 1
    #define GPIO_PORT_A
    #define IO_PA 0
    #define GPIO_Write_PA LATA
    #define GPIO_Read_PA PORTA
    #define GPIO_Tris_PA TRISA
#endif

#if NUM_PORTS >= 2
    #define GPIO_PORT_B
    #define IO_PB 1
    #define GPIO_Write_PB LATB
    #define GPIO_Read_PB PORTB
    #define GPIO_Tris_PB TRISB
#endif

#if NUM_PORTS >= 3
    #define GPIO_PORT_C
    #define IO_PC 2
    #define GPIO_Write_PC LATC
    #define GPIO_Read_PC PORTC
    #define GPIO_Tris_PC TRISC
#endif

#if NUM_PORTS >= 4
    #define GPIO_PORT_D
    #define IO_PD 3
    #define GPIO_Write_PD LATD
    #define GPIO_Read_PD PORTD
    #define GPIO_Tris_PD TRISD
#endif

#if NUM_PORTS >= 5
    #define GPIO_PORT_E
    #define IO_PE 4
    #define GPIO_Write_PE LATE
    #define GPIO_Read_PE PORTE
    #define GPIO_Tris_PE TRISE
#endif

#if NUM_PORTS >= 6
    #define GPIO_PORT_F
    #define IO_PF 5
    #define GPIO_Write_PF LATF
    #define GPIO_Read_PF PORTF
    #define GPIO_Tris_PF TRISF
#endif

#if NUM_PORTS >= 7
    #define GPIO_PORT_G
    #define IO_PG 6
    #define GPIO_Write_PG LATG
    #define GPIO_Read_PG PORTG
    #define GPIO_Tris_PG TRISG
#endif

#if NUM_PORTS >= 8
    #define GPIO_PORT_H
    #define IO_PH 7
    #define GPIO_Write_PH LATH
    #define GPIO_Read_PH PORTH
    #define GPIO_Tris_PH TRISH
#endif
#endif

#endif
