
#ifndef TASK_H
#define TASK_H

#include "RTOS/stddefs.h"
#include "RTOS/rtos.h"
#include "RTOS/taskHelpers.h"
#include "RTOS/portable.h"
#include <stdio.h>
#include <string.h>

#define Time_t UI32_t


/**
 * Types of state a task can obtain.
 */
typedef enum TritonTaskState_e
{
	TASK_RUNNING,
	TASK_SUSPENDED,
	TASK_SUSPENDING,
#ifdef RTOS_TASK_WAIT_STATE_ENABLED
        TASK_WAITING,
#endif
	TASK_STOP
} TritonTaskState_t;

#ifdef RTOS_TASK_WAIT_STATE_ENABLED
/**
 */
typedef enum TritonTaskHelper_e
{
#ifdef RTOS_EVENTS_AVAILABLE
    TASKHELPER_EVENT = 0x1,
#endif
#ifdef RTOS_MESSAGES_AVAILABLE
    TASKHELPER_MESSAGE = 0x2,
#endif
#ifdef RTOS_QUEUES_AVAILABLE
    TASKHELPER_QUEUE = 0x3
#endif
} TritonTaskHelper_t;

/**
 * Type of stuff a task can wait for
 */
typedef union
{
#ifdef RTOS_QUEUES_AVAILABLE
    TaskQueue_t* Queue;
#endif
#ifdef RTOS_EVENTS_AVAILABLE
    UI32_t Events;
#endif
#ifdef RTOS_MESSAGES_AVAILABLE
    UI32_t Message;
#endif

    UI32_t __cmp;
} TritonTaskState_WaitData_u;
typedef struct TritonTaskState_WaitData_s
{
    TritonTaskHelper_t type:3;
    UI08_t timedout:1;
    UI16_t timeout;
    TritonTaskState_WaitData_u data;
} TritonTaskState_WaitData_t;
#endif

/**
 * Basic type for a task instance. Usage of linked list reduces initial memory usage and configuration.
 */
typedef struct TritonTask_s
{
    //! Task ID
    UI08_t ID;
    
    //! Location of task stack
    int* Stack;
    //! Location of task method required to execute. Only used at start
    void* Method;
    //! Position last used in the stack. Saved at each context switch.
    int* StackPosition;
    //! Size of the actual stack.
    int StackSize;

    //! Timestamp of last run.
    Time_t RunLast;
    //! Timestamp of next scheduled run.
    Time_t RunNext;
    //! Timespan the task has been active.
    Time_t RunActive;    
    //! Priority of the task, determines how urgent is changed to this task if multiple tasks are need to be done at once.
    int Priority;    

    //! State the task currently is in.
    TritonTaskState_t State;

#ifdef RTOS_TASK_WAIT_STATE_ENABLED
    //! Task waiting arguments.
    TritonTaskState_WaitData_t State_WaitArgument;
#endif

    //! Linked list reference to next task.
    struct TritonTask_s* NextTask;
} TritonTask_t;

/**
 * Initialize task manager.
 * Initializes the task manager. This allocates the first task (idle task) in the task manager,
 * registers the required tick interrupt. Trace should show RTOS_TRACE_TASK_START event.
 * @return void
 */
void Task_Init(void);

/**
 * Registers one task in the task manager
 * Register one task in the task manager. The simpelst task requires a main function and an allocated stack. Stacks can't be shared.
 * The stack should be sufficient in size to support the functionality of the program. Initially a 64 byte stack is decent, but enlarge if stack overflow occurs (see trace port).
 * This function will trigger RTOS_TRACE_TASK_REGISTER and  RTOS_TRACE_TASK_REGISTER_NAME events. The name is only used for trace functionalities.
 * @param task Pointer to the instance of the task.
 * @param name Name of the task (debug only)
 * @param Stack Pointer to the first integer of the stack. Enlarge the size on tasks with many local variables or function calls.
 * @param StackSize Report the size of the stack to check for stack overflows.
 * @param Method Pointer to the initial method.
 * @param Priority Integer value containing the priority of this task.
 * @return void
 */
void _Task_Register(TritonTask_t* task, char* name, int* Stack, int StackSize, void* Method, int Priority);

/**
 * Suspend a task for a x time.
 * Suspend the current task for a specific amount of time (ticks). Only works within a task, do not execute from interrupts.
 * The task manager will try to resume the task as soon as the ticks have been passed.
 * Any multitasking system requires a TaskSleep to ensure other tasks get a chance to execute.
 * @param time The time (in ticks) to sleep.
 */
void Task_Sleep(Time_t time);

/**
 * Suspends a task until x time.
 * Suspends the current task until the tick counter reaches a certain value. Only works within a task, do not execute from interrupts.
 * The task manager will try to resume the task as soon as the ticks have been passed.
 * Any multitasking system requires a TaskSleep to ensure other tasks get a chance to execute.
 * @param time The time to wait until
 */
void Task_SleepUntil(Time_t time);

#ifdef RTOS_TASK_WAIT_STATE_ENABLED
/**
 * Suspends a task due to a task-helper calling for a wait procedure.
 * @return
 */
UI08_t Task_Wait(TritonTaskState_WaitData_t argument);

/**
 * Suspends a task due to a task-helper calling for a wait procedure.
 * @return
 */
void Task_Signal(TritonTaskState_WaitData_t argument);
#endif

/**
 * Gets the current time.
 * Gets the current time from the task manager (ticks). This can be used as a rough time keeper, but is more useful to determine SleepUntil values.
 * @return  time_t time (ticks)
 */
Time_t Task_GetTime(void);

/**
 * Start the task manager.
 * This method starts the task maanger. This method will never complete executing, as the task manager will be running from this moment.
 * If no task is registrered, this will only run the idle task.
 */
void Task_Start(void);

extern void Task_ChangeASM(void);

void Kernel_InitializeStack(TritonTask_t* Task, int* stack, void* function);


extern int* CurrentTaskStack ;
extern UI16_t uxCriticalNesting;
extern TritonTask_t* Task_Active;

#define Task(name, stack_size, priority) TritonTask_t PASTE(Task_Inst_, name); \
const UI08_t PASTE(Task_StackSize_, name) = stack_size; \
const UI08_t PASTE(Task_Priority_, name) = priority; \
UI08_t PASTE(Task_Stack_, name) [stack_size]; \
void PASTE(Task_, name) (void)

#define TaskProto(name, stack_size) void PASTE(Task_, name) (void); \
extern TritonTask_t PASTE(Task_Inst_, name); \
extern const UI08_t PASTE(Task_StackSize_, name); \
extern const UI08_t PASTE(Task_Priority_, name); \
extern UI08_t PASTE(Task_Stack_, name) [stack_size];

#define Task_Register(name) _Task_Register( \
    &PASTE(Task_Inst_, name),  \
    STRINGIFY(name), \
    (int*)PASTE(Task_Stack_, name), \
    PASTE(Task_StackSize_, name), \
    (void*)PASTE(Task_, name),  \
    PASTE(Task_Priority_, name) \
);
#endif
