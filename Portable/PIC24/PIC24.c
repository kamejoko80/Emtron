
#include "hardware.h"
#include "RTOS/stddefs.h"
#include "RTOS/portable.h"

#ifdef TARGET_PIC24

const IOPort_t IOPorts[NUM_PORTS] = {
    {PTR16(0x2C0), PTR16(0x2C2), PTR16(0x2C4), PTR16(0x2C6)} // Port A
    #if NUM_PORTS >= 2
        ,{PTR16(0x2C8), PTR16(0x2CA), PTR16(0x2CC), PTR16(0x2CE)} // Port B
    #endif
    #if NUM_PORTS >= 3
        ,{PTR16(0x2D0), PTR16(0x2D2), PTR16(0x2D4), PTR16(0x2D6)} // Port C
    #endif
    #if NUM_PORTS >= 4
        ,{PTR16(0x2D8), PTR16(0x2DA), PTR16(0x2DC), PTR16(0x2DE)} // Port D
    #endif
    #if NUM_PORTS >= 5
        ,{PTR16(0x2E0), PTR16(0x2E2), PTR16(0x2E4), PTR16(0x2E6)} // Port E
    #endif
    #if NUM_PORTS >= 6
        ,{PTR16(0x2E8), PTR16(0x2EA), PTR16(0x2EC), PTR16(0x2EE)} // Port F
    #endif
    #if NUM_PORTS >= 7
        ,{PTR16(0x2F0), PTR16(0x2F2), PTR16(0x2F4), PTR16(0x2F6)} // Port G
    #endif
    #if NUM_PORTS >= 8
        ,{PTR16(0x2F8), PTR16(0x2FA), PTR16(0x2FC), PTR16(0x2FE)} // Port H
    #endif
};


void FW_Init(void)
{
    // Initialize the CPU clock.
    //CLKDIV  = CFG_RCDIV << 8;
    CLKDIV = 0;

    #if NUM_PORTS >= 7 // TODO: When does AD1PCFG go to AD1PCFGL and AD1PCFGH?
    AD1PCFGL = 0xFFFF;
    AD1PCFGH = 0xFFFF;
    #else
        AD1PCFG = 0xFFFF;
    #endif

    #ifdef HARDWARE_LEDCOUNT
        #if HARDWARE_LEDCOUNT > 0
        int i=0;
        for (i = 0 ; i < HARDWARE_LEDCOUNT; i++)
        {
            SGPIO_Direction(LEDs[i].port, LEDs[i].pin, OUTPUT);
        }
        #endif
    #endif
}

#endif
