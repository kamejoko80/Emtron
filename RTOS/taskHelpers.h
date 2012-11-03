#ifndef EMTRON_RTOS_TASKHELPERS_H
#define EMTRON_RTOS_TASKHELPERS_H

#include "RTOS/stddefs.h"

typedef struct TaskQueue_s
{
    UI08_t* circ_buffer; // pointer to buffer array
    UI16_t circ_size;
    UI16_t circ_readPtr;
    UI16_t circ_writePtr;
    UI16_t circ_count;

    UI08_t ItemSize;
    UI08_t Items;
} TaskQueue_t;

#endif