
#include "RTOS/portable.h"
#include "RTOS/task.h"
#include "Portable/STM32/kernel.h"

#ifdef TARGET_STM32
UI32_t scramble;

void Kernel_Close(void);
/*
void Kernel_ContextSave(void)
{
 asmKernel_ContextSave();
}

void Kernel_ContextRestore(void)
{
  asmKernel_ContextRestore();
}*/

void Kernel_Suspend(void)
{ 
  asmKernel_ContextSwitch();
  /*
  asmKernel_ContextSave();
  //Kernel_ContextSave();

  asmKernel_StackPtrRead();
  Task_Change();
  asmKernel_StackPtrWrite();
  asmKernel_ContextRestore();*/
  //Kernel_ContextRestore();
}

void Kernel_Close(void) 
{
}
// TODO: Replace with portable code
void Kernel_InitializeStack(TritonTask_t* Task, void* stack, void* function)
{
    hw_stack_frame_t * process_frame;
    process_frame = (hw_stack_frame_t *)((UI08_t*)stack + Task->StackSize -  sizeof(hw_stack_frame_t));
    process_frame->r0 = 0x11;
    process_frame->r1 = 0x22;
    process_frame->r2 = 0x33;
    process_frame->r3 = 0x44;
    process_frame->r12 = 0x55;
    process_frame->pc = ((uint32_t)function);
    process_frame->lr = (uint32_t)Kernel_Close;
    process_frame->psr = 0x21000000; //default PSR value
    sw_stack_frame_t* software_stack;
    software_stack = (sw_stack_frame_t*) ((UI08_t*)stack + Task->StackSize -  sizeof(sw_stack_frame_t) -  sizeof(hw_stack_frame_t));
    software_stack->r4 = 0x11;
    software_stack->r5 = 0x22;
    software_stack->r6 = 0x33;
    software_stack->r7 = 0x44;
    software_stack->r8 = 0x55;
    software_stack->r9 = 0x66;
    software_stack->lr = ((uint32_t)function);
    // Assign objects to task object.
    Task->Stack = stack;
    Task->Method = function;
    Task->StackPosition =(int*) ((UI08_t*)stack + Task->StackSize - sizeof(hw_stack_frame_t) - sizeof(sw_stack_frame_t));
}

#endif