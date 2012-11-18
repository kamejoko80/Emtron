#ifndef PORTABLE_STM32_KERNEL_H
#define PORTABLE_STM32_KERNEL_H

#include "RTOS/stddefs.h"

#ifdef TARGET_STM32

extern UI32_t scramble;

extern void asmKernel_ContextRestore(void);
extern void asmKernel_ContextSave(void);
extern void asmKernel_StackPtrRead(void);
extern void asmKernel_StackPtrWrite(void);
extern void asmKernel_ContextSwitch(void);

//This defines the stack frame that must be saved by the software
typedef struct {
  uint32_t r4;
  uint32_t r5;
  uint32_t r6;
  uint32_t r7;
  uint32_t r8;
  uint32_t r9;
  uint32_t r10;
  uint32_t r11;
  uint32_t lr;
} sw_stack_frame_t;
//This defines the stack frame that is saved  by the hardware
typedef struct {
  uint32_t r0;
  uint32_t r1;
  uint32_t r2;
  uint32_t r3;
  uint32_t r12;
  uint32_t lr;
  uint32_t pc;
  uint32_t psr;
} hw_stack_frame_t;
 
#define Kernel_Sleep() asm("nop");
#define Kernel_ContextSave asmKernel_ContextSave
#define Kernel_ContextRestore asmKernel_ContextRestore

#define dKernel_ContextRestore() \
  volatile  uint32_t scratch; \
  asm volatile ("MRS %0, psp\n\t" \
      "LDMFD %0!, {r4-r11}\n\t" \
      "MSR psp, %0\n\t"  : "=r" (scratch) );

#define dKernel_ContextSave() \
  volatile uint32_t scratch; \
  asm volatile ("MRS %0, psp\n\t" \
      "STMDB %0!, {r4-r11}\n\t" \
      "MSR psp, %0\n\t"  : "=r" (scratch) );

#endif

#endif
