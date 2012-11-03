#define MAIN_C

#include "RTOS/stddefs.h"
#include "RTOS/task.h"
#include "RTOS/taskQueue.h"
#include "Utilities/circular_buffer.h"

#define ButtonA GPIO(PB, 14)
#define ButtonB GPIO(PB, 15)

TritonTask_t T1;
UI08_t T1_Stack[128];
TritonTask_t T2;
UI08_t T2_Stack[128];

TaskQueue_t ButtonQueue;
UI08_t ButtonQueueBf[128];
typedef struct
{
    UI32_t Lolwut;
    UI08_t ButtonID;
} ButtonMessage_t;

void Task1(void)
{
    ButtonMessage_t message;
    
    while(1)
    {
        if (TaskQueue_WaitPeriod(&ButtonQueue, &message, 100))
        {
            GPIO_Write(PB, 2, 0);
            GPIO_Write(PB, message.ButtonID, 1-GPIO_Read(PB, message.ButtonID));
        }
        else
        {
            GPIO_Write(PB, 2, 1);
        }
        Task_Sleep(100);
    }
}

void Task2(void)
{
    ButtonMessage_t MyMessage;
    while(1)
    {
        MyMessage.ButtonID = 1;
        TaskQueue_Add(&ButtonQueue, &MyMessage);
        Task_Sleep(300);
        TaskQueue_Add(&ButtonQueue, &MyMessage);
        Task_Sleep(200);
        TaskQueue_Add(&ButtonQueue, &MyMessage);
        Task_Sleep(200);
        TaskQueue_Add(&ButtonQueue, &MyMessage);
        Task_Sleep(200);
        while(1){Task_Sleep(5000); }
    }
}

int main(void)
{
    FW_Init();
    TaskQueue_Create(&ButtonQueue, ButtonQueueBf, 8, sizeof(ButtonMessage_t));

    SGPIO_DirectionGPIO(GPIO(PB, 7), OUTPUT);
    SGPIO_DirectionGPIO(ButtonA, INPUT);
    SGPIO_DirectionGPIO(ButtonB, INPUT);

    Task_Init();
    Task_Register(&T1, "T1", (int*)T1_Stack, 128, Task1, 100);
    Task_Register(&T2, "T2", (int*)T2_Stack, 128, Task2, 10);
    Task_Start();

    return 0;
}

