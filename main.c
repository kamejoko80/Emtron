#define MAIN_C

#include "RTOS/stddefs.h"
#include "RTOS/task.h"
#include "RTOS/taskQueue.h"
#include "RTOS/taskEvent.h"
#include "main.h"
  
#define ButtonA GPIO(PB, 14)
#define ButtonB GPIO(PB, 15)

#ifdef RTOS_QUEUES_AVAILABLE
TaskQueue_t ButtonQueue;
UI08_t ButtonQueueBf[8*4];
#endif
typedef struct ButtonMessage_s
{
    IOPin_t io;
} ButtonMessage_t;

Task(Task1, 4000, 1)
{
    ButtonMessage_t message;
    message.io = GPIO(PD,14);
    while(1)
    {
#ifdef RTOS_QUEUES_AVAILABLE
        if (TaskQueue_WaitPeriod (&ButtonQueue, &message, 250))
        {
            SGPIO_WriteGPIO(message.io, 1- SGPIO_ReadGPIO(message.io));
        }
        else
        {
            IOPin_t l = GPIO(PD, 14);
            UI08_t a = 1-SGPIO_ReadGPIO(l);
            SGPIO_WriteGPIO(l, a);
        }
#else
            SGPIO_WriteGPIO(message.io, 1-SGPIO_ReadGPIO(message.io));
#endif
    }
}

Task(Task2, 4000, 10)
{
    ButtonMessage_t MyMessage;
    MyMessage.io = GPIO(PD, 15);
    while(1)
    {
#ifdef RTOS_QUEUES_AVAILABLE
        TaskQueue_Add(&ButtonQueue, &MyMessage);
#endif
        Task_Sleep(1000);
    }
}

int main(void)
{
    FW_Init();
#ifdef RTOS_QUEUES_AVAILABLE
    TaskQueue_Create(&ButtonQueue, ButtonQueueBf, 8, sizeof(ButtonMessage_t));
#endif
    SGPIO_DirectionGPIO(GPIO(PD, 15), OUTPUT);
    SGPIO_DirectionGPIO(GPIO(PD, 14), OUTPUT);
    SGPIO_DirectionGPIO(GPIO(PD, 13), OUTPUT);
    Task_Init();
    Task_Register(Task1);
    Task_Register(Task2);
    Task_Start();

    while(1);
    return 0;
}