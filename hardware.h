#ifndef HARDWARE_H
#define HARDWARE_H

#include "RTOS/stddefs.h"
#include "RTOS/portable.h"

#define HARDWARE_LEDCOUNT 3
const IOPin_t LEDs[HARDWARE_LEDCOUNT] = {
    GPIO(PB,0),
    GPIO(PB,1),
    GPIO(PB,2)
};

#endif