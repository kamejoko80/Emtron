#ifndef PORTABLE_STM32_STM32F40x_h
#define PORTABLE_STM32_STM32F40x_h

    #ifndef PROJECT_H
            #error "There is no project configuration defined!"
    #else
            #define CLOCK_CPU 168000000
            #define CLOCK_PERIPHERAL CLOCK_CPU/2
    #endif

    #define NUM_PORTS 4

    typedef enum PeripheralType_e
    {
        PERIPHERAL_SOFTSPI,
        PERIPHERAL_SOFTI2C
    } PeripheralType_t;
#endif
