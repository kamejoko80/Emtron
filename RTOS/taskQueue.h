#ifndef EMTRON_RTOS_TASKQUEUE_H
#define EMTRON_RTOS_TASKQUEUE_H

#include "RTOS/stddefs.h"
#include "RTOS/task.h"
#include "RTOS/taskHelpers.h"
#include "Utilities/circular_buffer_macro.h"

#ifdef RTOS_QUEUES_AVAILABLE
void TaskQueue_Create(TaskQueue_t* queue, void* buffer, UI16_t items, UI16_t size);
void TaskQueue_Add(TaskQueue_t* queue, void* data);
UI08_t TaskQueue_Wait(TaskQueue_t* queue, void* data);
UI08_t TaskQueue_WaitPeriod(TaskQueue_t* queue, void* data, UI16_t time);
#endif

#endif