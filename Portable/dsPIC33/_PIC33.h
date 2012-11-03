#ifndef PORT__PIC24_H
#define PORT__PIC24_H

#include "p33Fxxxx.h"
#include "project.h"

#define GPIO_Write_PA LATA
#define GPIO_Write_PB LATB
#define GPIO_Read_PA PORTA
#define GPIO_Read_PB PORTB
#define GPIO_Tris_PA TRISA
#define GPIO_Tris_PB TRISB
#define GPIO_Direction_Input 1
#define GPIO_Direction_Output 0
#define GPIO_Direction_INPUT 1
#define GPIO_Direction_OUTPUT 0
#define GPIO_Direction_IN 1
#define GPIO_Direction_OUT 0
#define INPUT 1
#define OUTPUT 0

/*
void GPIO_Write(UI08_t port, UI08_t pin, UI08_t value)
{
    switch(port)
    {
#ifdef GPIO_PORT_A
        case GPIO_PORT_A:
            if (value==0)
                LATA &= ~(1<<pin);
            else
                LATA |= 1<<pin;
            break;
#endif
#ifdef GPIO_PORT_B
        case GPIO_PORT_B:
            if (value==0)
                LATB &= ~(1<<pin);
            else
                LATB |= 1<<pin;
            break;
#endif
#ifdef GPIO_PORT_C
        case GPIO_PORT_C:
            if (value==0)
                LATB &= ~(1<<pin);
            else
                LATB |= 1<<pin;
            break;
#endif
#ifdef GPIO_PORT_D
        case GPIO_PORT_D:
            if (value==0)
                LATD &= ~(1<<pin);
            else
                LATD |= 1<<pin;
            break;
#endif

    }
}*/

#endif
