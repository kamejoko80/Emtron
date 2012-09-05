#include "task.h"
#include <stdio.h>
#include <string.h>
#include "portable.h"

TritonTask_t* Task_Top;
TritonTask_t* Task_Active;
TritonTask_t* Task_Tmp;
TritonTask_t* Task_Next;

UI16_t Task_CurrentStackLocation;
UI08_t Task_ActiveID;
Time_t Task_CurrentTime;

// TODO: Replace with portable code
UI16_t uxCriticalNesting = 0;

// local functions

TritonTask_t* Task_GetTask(int depth);

/**** IDlE TASK ****/
int Task_Idle_Stack[128];
TritonTask_t Task_Idle;

/**
 * Idle task of the RTOS.
 * Idle task of the RTOS could be used to bring the microcontroller into sleep. Please make sure that the portable supports timer interrupts whilst sleep.
 */
void Task_Idle_Loop(void)
{
    while(1)
    {
       asm volatile("PWRSAV #1");//enter idle mode, wakeup by interrupt.
    }
}

// global methods

/**
 * \brief Initialize Task Manager
 */
void Task_Init(void)
{

    #ifdef RTOS_TRACE
        RTOS_Trace(RTOS_TRACE_TASK_START, 0, null);
    #endif

    // TODO: Replace with portable code.
    Task_Tmp = (TritonTask_t*) 0;
    Task_Top = (TritonTask_t*) 0;
    Task_Next = (TritonTask_t*) 0;
    Task_Active = (TritonTask_t*) 0;

    // Start the system timer.
    Timer_OpenSysTimer();

    // Register idle task
    Task_Register(&Task_Idle, "Idle", Task_Idle_Stack, 36, Task_Idle_Loop, 0);

}
void Task_Start(void)
{
    // Set active task the top one.
    Task_Active = Task_Top;

    Task_CurrentStackLocation = (int)Task_Active->StackPosition;
    Timer_StartSysTimer();
    Kernel_ContextRestore();
}

TritonTask_t* Task_GetTask(int depth)
{
    // get the active task
    TritonTask_t* ref = Task_Top;

    while(--depth >= 0)
        ref = ref->NextTask;

    return ref;
}

void Task_Register(TritonTask_t* task, char* name, int* Stack, int StackSize, void* Method, int Priority)
{
	memset(task, 0, sizeof(TritonTask_t));
	Kernel_InitializeStack(task, Stack, Method);
	task->StackSize = StackSize;
	task->Priority = Priority;
	task->NextTask = 0;
	
	// Make top task or add to linkedlist?
	if(Task_Top == 0x0000)
		Task_Top = task;
	else
	{
		Task_Tmp = Task_Top;
		while(Task_Tmp->NextTask != 0)
			Task_Tmp = Task_Tmp->NextTask;
		Task_Tmp->NextTask = task;
                task->ID = Task_Tmp->ID+1;
	}

#ifdef RTOS_TRACE
    RTOS_Trace(RTOS_TRACE_TASK_REGISTER, sizeof(TritonTask_t), task);
    RTOS_Trace(RTOS_TRACE_TASK_REGISTER_NAME, strlen(name)+1, name);
#endif
}

// Finds next task on Suspend()
void Task_FindBestTask(void)
{
	Task_Tmp  = Task_Top;
	Task_Next = Task_Top;
	do
	{
		if(Task_Tmp->RunNext <= Task_CurrentTime)
		{
			// Is this task of higher priority? Then set as next.
			if (Task_Tmp->Priority > Task_Next->Priority)
				Task_Next = Task_Tmp;
		}
		Task_Tmp = Task_Tmp->NextTask;
	}
	while(Task_Tmp != 0);
}

// Finds next task on Tick()
void Task_FindNextTask(void)
{
	// 
	Task_Tmp  = Task_Top;
	Task_Next = Task_Active;
	do
	{
		if(Task_Tmp->RunNext <= Task_CurrentTime)
		{
			// Is this task of higher priority? Then set as next.
			if (Task_Tmp->Priority > Task_Next->Priority)
				Task_Next = Task_Tmp;
		}
		Task_Tmp = Task_Tmp->NextTask;
	}
	while(Task_Tmp != 0);
}

void Task_Sleep(Time_t time)
{
	Task_Active->RunNext = Task_CurrentTime + time;
	Task_Active->State = TASK_SUSPENDING;
	
	Kernel_Suspend();
}

void Task_Change(void)
{
	// Save old task
	Task_Active->StackPosition = (int*)Task_CurrentStackLocation;
	Task_Active->RunLast = Task_CurrentTime;
	if(Task_Active->RunNext < Task_Active->RunLast)
		Task_Active->RunNext = Task_CurrentTime+1;

	if(Task_Active->State == TASK_SUSPENDING)
	{
		Task_Active->State = TASK_SUSPENDED;
		Task_FindBestTask();
	}
	else
	{
		Task_Active->State = TASK_SUSPENDED;
		Task_FindNextTask();
	}

        #ifdef RTOS_TRACE
        if(Task_Next->ID != Task_Active->ID)
        {
            RTOS_Trace(RTOS_TRACE_TASK_SUSPEND, sizeof(UI08_t), Task_Active->ID);
            RTOS_Trace(RTOS_TRACE_TASK_RESUME, sizeof(UI08_t), (void*)Task_Active->ID);
        }
        #endif
	Task_Active = Task_Next;
	Task_Active->State = TASK_RUNNING;
	// Start other task
	Task_CurrentStackLocation = (int)Task_Active->StackPosition;

}


// Interrupt of OS
// TODO: Replace with portable code

#ifdef RTOS_TRACE
volatile UI16_t CPULoad=0;
volatile Time_t CPULoadIdle=0;
#endif
void __attribute__((__interrupt__, __shadow__, auto_psv)) _T1Interrupt(void)
{
	Task_CurrentTime++;
	Timer_ClrSysTimerInt();

        #ifdef RTOS_TRACE
        Task_Active->RunActive ++;
        CPULoad++;
        if(CPULoad>=1000) // 1 second, report CPU time
        {
            CPULoad = Task_Idle.RunActive - CPULoadIdle;
            RTOS_Trace(RTOS_TRACE_TASK_CPULOAD, sizeof(UI16_t), (void*)&CPULoad);
            CPULoadIdle = Task_Idle.RunActive;
            CPULoad=0;
        }
        #endif

	// This calls ASM to change context.
	Kernel_Suspend();

}
