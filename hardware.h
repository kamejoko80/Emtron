#ifndef HARDWARE_H
#define HARDWARE_H

#include "RTOS/stddefs.h"
#include "RTOS/portable.h"
#include "Devices/GraphicDisplay.h"

#define HARDWARE_LEDCOUNT 1
const IOPin_t LEDs[HARDWARE_LEDCOUNT] = {
    GPIO(PB, 14)
};

#endif