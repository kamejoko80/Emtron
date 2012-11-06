#include "RTOS/taskQueue.h"

#ifdef RTOS_QUEUES_AVAILABLE
void TaskQueue_Create(TaskQueue_t* queue, void* buffer, UI16_t items, UI16_t size)
{
    m_CircularBuffer_Reset(queue, items*size);

    queue->ItemSize = size;
    queue->Items = items;
    queue->circ_buffer = buffer;
}

void TaskQueue_Add(TaskQueue_t* queue, void* data)
{
    TritonTaskState_WaitData_t wait_data;
    wait_data.data.Queue = queue;

    m_CircularBuffer_WriteBytes(queue, (UI08_t*)data, queue->ItemSize);
    Task_Signal(wait_data);
}

UI08_t TaskQueue_Wait(TaskQueue_t* queue, void* data)
{
    TaskQueue_WaitPeriod(queue, data, 0);
    return 1;
}

UI08_t TaskQueue_WaitPeriod(TaskQueue_t* queue, void* data, UI16_t time)
{
    UI08_t circ_bf_size = 0;
    m_CircularBuffer_Available(queue, circ_bf_size);
    if (circ_bf_size > 0)
    {
        // waiting is done..
        m_CircularBuffer_ReadBytes(queue, (UI08_t*)data, queue->ItemSize);
        return 1;
    }
    
    TritonTaskState_WaitData_t wait_data;
    wait_data.data.Queue = queue;
    wait_data.timeout = time;

    // suspend this task until another task calls Add(which calls signal)
    if (Task_Wait(wait_data))
    {
        // waiting is done..
        m_CircularBuffer_ReadBytes(queue, (UI08_t*)data, queue->ItemSize);
        return 1;
        
    }
    else
    {
        return 0;
        
    }

}
#endif