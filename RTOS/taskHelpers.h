#ifndef EMTRON_RTOS_TASKHELPERS_H
#define EMTRON_RTOS_TASKHELPERS_H

#include "RTOS/stddefs.h"
#include "project.h"

#ifdef RTOS_USE_QUEUES
#if RTOS_USE_QUEUES == 1
#define RTOS_QUEUES_AVAILABLE
#undef RTOS_TASK_WAIT_STATE_ENABLED
#define RTOS_TASK_WAIT_STATE_ENABLED
#endif
#endif

#ifdef RTOS_USE_EVENTS
#if RTOS_USE_EVENTS == 1
#define RTOS_EVENTS_AVAILABLE
#undef RTOS_TASK_WAIT_STATE_ENABLED
#define RTOS_TASK_WAIT_STATE_ENABLED
#endif
#endif

#ifdef RTOS_USE_MESSAGES
#if RTOS_USE_MESSAGES == 1
#define RTOS_MESSAGES_AVAILABLE
#undef RTOS_TASK_WAIT_STATE_ENABLED
#define RTOS_TASK_WAIT_STATE_ENABLED
#endif
#endif


#ifdef RTOS_TASK_WAIT_STATE_ENABLED
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

#endif