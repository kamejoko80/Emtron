#define MAIN_C

#include "RTOS/stddefs.h"
#include "RTOS/task.h"
#include "RTOS/taskQueue.h"
#include "RTOS/taskEvent.h"
#include "main.h"
#include "Devices/GraphicDisplay.h"

#define ButtonA GPIO(PB, 14)
#define ButtonB GPIO(PB, 15)

GraphicDisplay_t Dsp;

#ifdef RTOS_QUEUES_AVAILABLE
TaskQueue_t ButtonQueue;
UI08_t ButtonQueueBf[8];
#endif
typedef struct
{
    UI08_t ButtonID;
} ButtonMessage_t;

Task(Task1, 128, 1)
{
    ButtonMessage_t message;
    while(1)
    {
#ifdef RTOS_QUEUES_AVAILABLE
        if (TaskQueue_Wait (&ButtonQueue, &message))
        {
            GPIO_Write(PB, message.ButtonID, 1-GPIO_Read(PB, message.ButtonID));
        }
#else
            GPIO_Write(PB, message.ButtonID, 1-GPIO_Read(PB, message.ButtonID));
#endif
        Task_Sleep(100);
        
    }
}

Task(Task2, 128, 10)
{
    ButtonMessage_t MyMessage;
    MyMessage.ButtonID = 14;
    Task_Sleep(2);
    SGPIO_Write1GPIO(GPIO(PB, 0));
    GraphicDisplay_Power(&Dsp, 1);
    while(1)
    {
#ifdef RTOS_QUEUES_AVAILABLE
        TaskQueue_Add(&ButtonQueue, &MyMessage);
#endif
        Task_Sleep(100);
        GraphicDisplay_Test(&Dsp);
    }
}

int main(void)
{
    FW_Init();
#ifdef RTOS_QUEUES_AVAILABLE
    TaskQueue_Create(&ButtonQueue, ButtonQueueBf, 8, sizeof(ButtonMessage_t));
#endif

    GraphicDisplay_Init(&Dsp, &DISPLAY_SED1565, 128, 64);
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_RS, GPIO(PB, 1));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_RW, GPIO(PB, 2));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_E,  GPIO(PB, 3));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D0, GPIO(PB, 4));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D1, GPIO(PB, 5));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D2, GPIO(PB, 6));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D3, GPIO(PB, 7));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D4, GPIO(PB, 8));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D5, GPIO(PB, 9));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D6, GPIO(PB, 10));
    GraphicDisplay_GPIO(&Dsp, GraphicDisplay_IO_D7, GPIO(PB, 11));
    SGPIO_DirectionGPIO(GPIO(PB,0), OUTPUT);
    SGPIO_Write0GPIO(GPIO(PB, 0));

    Task_Init();
    Task_Register(Task1);
    Task_Register(Task2);
    Task_Start();

    return 0;
}