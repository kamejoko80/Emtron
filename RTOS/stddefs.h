#ifndef TRITON_STDDEFS_H
#define TRITON_STDDEFS_H

#include <stdio.h>

/**** DATA TYPES ****/
#define UI64_t unsigned long long
#define UI32_t unsigned long
#define UI16_t unsigned int
#define UI08_t unsigned char

#define SI32_t signed long
#define SI16_t signed int
#define SI08_t signed char

#define F32_t float
#define PTR16(addr) ((UI16_t*)addr)
#define PTR32(addr) ((UI32_t*)addr)
#ifndef NULL
    #define NULL 0
#endif
#ifndef null
    #define null 0
#endif

typedef void *          Pointer_t;
typedef char *          String_t;
typedef void            (*HandlerPtr_t) (void);
typedef void            (*HandlerPtr_argb_t) (UI08_t arg);
typedef void            (*HandlerPtr_ptr_t) (UI08_t* arg);
typedef void            (*HandlerPtr_argb_ptr_t) (UI08_t arg1, UI08_t* arg2);
typedef void            (*HandlerPtr_argb_argb_t) (UI08_t arg1, UI08_t arg2);
typedef void            (*CaptureHandlerPtr_t) (UI08_t id, UI32_t elTime);

/**** General definition of IO pin reference */
typedef struct IOPin_s
{
    unsigned port:3;         // A to D
    unsigned pin:7;          // Pin 0 to 31
    unsigned invert:1;       // 1 invert
} IOPin_t;

typedef struct IOPort_s
{
	UI32_t* TRIS;
	UI32_t* PORT;
	UI32_t* LAT;
	UI32_t* ODC;
} IOPort_t;

#include "RTOS/portable.h"

// These struct initialisations are not compatible in C++
#ifdef __cplusplus

#define PIN(port, pin, invert) (IOPin_t){IO_##port, pin, invert}
#define GPIO(port, pin) {IO_##port, pin, 0}
#else
#define PIN(port, pin, invert) (IOPin_t){IO_##port, pin, invert}
#define GPIO(port, pin) (IOPin_t){IO_##port, pin, 0}
#endif

/***** General purpose Fast-GPIO writes (not flexible)*****/
//TODO: add set/clr function
#ifdef GPIO_SetClr
	// This microcontroller uses set/clr registers
	#define FGPIO_Write(port, pin, value) if(value) { \
		GPIO_Write1_##port |=  (1U << pin); \
	} else { \
		GPIO_Write0_##port |=  (1U << pin); \
	}
	#define FGPIO_Write1(port, pin) GPIO_Write1_##port |=  (1U << pin)
	#define FGPIO_Write0(port, pin) GPIO_Write0_##port |=  (1U << pin)
#else
	#define FGPIO_Write(port, pin, value) if(value) { \
		GPIO_Write_##port |=  (1U << pin); \
	} else { \
		GPIO_Write_##port &=  ~(1U << pin); \
	}
	#define FGPIO_Write1(port, pin) GPIO_Write_##port |=  (1U << pin)
	#define FGPIO_Write0(port, pin) GPIO_Write_##port &= ~(1U << pin)
#endif

#define FGPIO_Read(port, pin) ((GPIO_Write_##port>>pin) & 0x1)
#define FGPIO_Direction(port, pin, dir) if(GPIO_Direction_##dir) \
{ \
    GPIO_Tris_##port  |= 1<<(GPIO_Direction_Size*pin); \
}else{ \
    GPIO_Tris_##port &= ~(1<<(GPIO_Direction_Size*pin)); \
}

/**** Look-up general purpose writes ****/
// For use with structs (i.e. stored port number in memory)
#define SGPIO_Direction(port, pin, dir) \
    if(dir) {   \
        *(IOPorts[port].TRIS) |= 1<<(GPIO_Direction_Size*pin);    \
    } else {    \
        *(IOPorts[port].TRIS) &= ~(1<<(GPIO_Direction_Size*pin)); \
    }
#define SGPIO_OpenDrainEnable(gpio) \
    *(IOPorts[(gpio).port].ODC) |= (1<<(gpio).pin);
#define SGPIO_OpenDrainDisable(gpio) \
    *(IOPorts[(gpio).port].ODC) &= ~(1<<(gpio).pin);
#define SGPIO_DirectionGPIO(gpio, dir) \
    if(dir) {   \
        *(IOPorts[(gpio).port].TRIS) |= (1<<(GPIO_Direction_Size*(gpio).pin));    \
    } else {    \
        *(IOPorts[(gpio).port].TRIS) &= ~(1<<(GPIO_Direction_Size*(gpio).pin)); \
    }
#define SGPIO_Write(port, pin, value) \
    if(value) {\
    SGPIO_Write1(port, pin);\
    }else{\
    SGPIO_Write0(port,pin));\
    }
#define SGPIO_WriteGPIO(gpio, value) \
    if(value) {\
    SGPIO_Write1(gpio.port, gpio.pin);\
    }else{\
    SGPIO_Write0(gpio.port, gpio.pin);\
    }
#define SGPIO_Read(port, pin) ((*(IOPorts[port].PORT)>>pin)&0x1)
#define SGPIO_ReadGPIO(gpio) ((*(IOPorts[gpio.port].PORT)>>gpio.pin)&0x1)
#define SGPIO_Write1(port, pin) *(IOPorts[(port)].LAT) |=  (1U << (pin));
#define SGPIO_Write0(port, pin) *(IOPorts[(port)].LAT)  &= ~(1U << (pin));
#define SGPIO_Write1GPIO(gpio) *(IOPorts[gpio.port].LAT) |=  (1U << gpio.pin);
#define SGPIO_Write0GPIO(gpio) *(IOPorts[gpio.port].LAT)  &= ~(1U << gpio.pin);


// For normal code (usage of macros)
#define GPIO_Direction(port, pin, dir) \
    if(dir) {   \
        *(IOPorts[IO_##port].TRIS) |= 1<<(GPIO_Direction_Size*pin);    \
    } else {    \
        *(IOPorts[IO_##port].TRIS) &= ~(1<<(GPIO_Direction_Size*pin)); \
    }

#define GPIO_Write(port, pin, value) \
    if(value) {\
    GPIO_Write1(port, pin);\
    }else{\
    GPIO_Write0(port,pin);\
    }
#define GPIO_Read(port, pin) ((*(IOPorts[IO_##port].PORT)>>pin)&0x1)
#define GPIO_Write1(port, pin) *(IOPorts[IO_##port].LAT) |=  (1U << pin);
#define GPIO_Write0(port, pin) *(IOPorts[IO_##port].LAT)  &= ~(1U << pin);

typedef enum BitResolution_t
{
    RESOLUTION_8BIT,
    RESOLUTION_9BIT,
    RESOLUTION_10BIT,
    RESOLUTION_11BIT,
    RESOLUTION_12BIT,
    RESOLUTION_13BIT,
    RESOLUTION_14BIT,
    RESOLUTION_15BIT,
    RESOLUTION_16BIT
} BitResolution_t;

// Glue for several macro's:
// http://stackoverflow.com/questions/806543/c-macros-manipulating-a-parameter-specific-example
#define STRINGIFY2( x) #x
#define STRINGIFY(x) STRINGIFY2(x)
#define PASTE_( a, b) a##b
#define PASTE( a, b) PASTE_( a, b)


#endif
