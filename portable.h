#ifndef TRITON_PORTABLE_H
#define TRITON_PORTABLE_H 1

#include "project.h"

// Microchip PIC24

#ifdef __PIC24FJ32GA002__
#include "Portable/PIC24FJ32GA002.h"
#endif

#ifdef __PIC24FJ64GB004__
#include "Portable/PIC24FJ32GA002.h"
#endif

#ifdef __dsPIC33FJ128GP802__
#include "Portable/dsPIC33FJ128GP802.h"
#endif

#ifdef __18F4620
#include "Portable/PIC18F4620.h"
#endif

// ARM
#ifdef __arm__
// TODO: FIX THIS
#include "Portable/LPC17xx.h"
#endif

#ifndef CLOCK_CPU
	#error "CPU configuration didn't specify CPU clock in Hz"
#endif

#ifndef CLOCK_PERIPHERAL
	#error "CPU configuration didn't specify peripheral clock in Hz"
#endif


#define GPIO_Direction_INPUT GPIO_Direction_Input
#define GPIO_Direction_OUTPUT GPIO_Direction_Output
#define GPIO_Direction_IN GPIO_Direction_Input
#define GPIO_Direction_OUT GPIO_Direction_Output
#define INPUT GPIO_Direction_Input
#define OUTPUT GPIO_Direction_Output

void FW_Init(void);

#endif
