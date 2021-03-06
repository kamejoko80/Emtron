#ifndef TRITON_RTOS_H
#define TRITON_RTOS_H

#include "RTOS/stddefs.h"
#include "project.h"

#ifdef RTOS_TRACE
typedef enum RTOS_Trace_Message_e
{
    RTOS_TRACE_TASK_START,
    RTOS_TRACE_TASK_REGISTER,
    RTOS_TRACE_TASK_REGISTER_NAME,
    RTOS_TRACE_TASK_SUSPEND,
    RTOS_TRACE_TASK_RESUME,
    RTOS_TRACE_TASK_CPULOAD
} RTOS_Trace_Message_t;

inline void RTOS_Trace(RTOS_Trace_Message_t message, UI08_t argl, void* arg);

#endif

#endif



