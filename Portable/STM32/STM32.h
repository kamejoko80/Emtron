#ifndef PORTABLE_STM32_STM32_H
#define PORTABLE_STM32_STM32_H

#ifdef STM32F40X
#define TARGET_STM32
#define PORTABLE_STM32F40x
#endif
#include "RTOS/stddefs.h"

#ifdef TARGET_STM32
  #define CORE_SIZE 32
    #include "stm32f40x.h"
    #define GPIO_Direction_Output 1
    #define GPIO_Direction_Input 0
    #define GPIO_Direction_Size 2

    /****************************** Header files ******************************/
    #ifdef PORTABLE_STM32F40x
    #include "Portable/STM32/STM32F407.h"
    #endif
    extern const IOPort_t IOPorts[NUM_PORTS];

    #include "Portable/STM32/kernel.h"
    #include "Portable/STM32/timer.h"

#if NUM_PORTS >= 1
    #define GPIO_PORT_A
    #define IO_PA 0
    #define GPIO_Write_PA GPIOA->ODR
    #define GPIO_Read_PA GPIOA->IDR
    #define GPIO_Tris_PA GPIOA->MODER
#endif

#if NUM_PORTS >= 2
    #define GPIO_PORT_B
    #define IO_PB 1
    #define GPIO_Write_PB GPIOB->ODR
    #define GPIO_Read_PB GPIOB->IDR
    #define GPIO_Tris_PB GPIOB->MODER
#endif

#if NUM_PORTS >= 3
    #define GPIO_PORT_C
    #define IO_PC 2
    #define GPIO_Write_PC GPIOC->ODR
    #define GPIO_Read_PC GPIOC->IDR
    #define GPIO_Tris_PC GPIOC->MODER
#endif


#if NUM_PORTS >= 4
    #define GPIO_PORT_D
    #define IO_PD 3
    #define GPIO_Write_PD GPIOD->ODR
    #define GPIO_Read_PD GPIOD->IDR
    #define GPIO_Tris_PD GPIOD->MODER
#endif


#endif


#endif
