/*
 * kernel.h
 *
 *  Created on: Jun 10, 2012
 *      Author: Hans
 */

#ifndef KERNEL_H
#define KERNEL_H

#include "task.h"
#include "stddefs.h"
#include "portable.h"



#ifdef PORT__PIC24_H


// TODO: replace with portable code!
// This pushes all proccesor registers on the stack.
#define dKernel_ContextSave() \
asm volatile ("push SR\n" \
	"push W0\n" \
	"mov #32, W0\n" \
	"mov W0, SR\n" \
	"push W1\n" \
	"push W2\n" \
	"push W3\n" \
	"push W4\n" \
	"push W5\n" \
	"push W6\n" \
	"push W7\n" \
	"push W8\n" \
	"push W9\n" \
	"push W10\n" \
	"push W11\n" \
	"push W12\n" \
	"push W13\n" \
	"push W14\n" \
	"push RCOUNT\n" \
	"push TBLPAG\n" \
	"push CORCON\n" \
	"push PSVPAG\n" \
	"push W0\n" \
	"mov W15, _Task_CurrentStackLocation");

// The last push W0 and first pop W0 is actual nesting index.

// This pops all proccesor registers off the stack.
#define dKernel_ContextRestore() \
asm volatile ("mov _Task_CurrentStackLocation, W15\n" \
	"pop W0\n" \
	"pop PSVPAG\n" \
	"pop CORCON\n" \
	"pop TBLPAG\n" \
	"pop RCOUNT\n" \
	"pop W14\n" \
	"pop W13\n" \
	"pop W12\n" \
	"pop W11\n" \
	"pop W10\n" \
	"pop W9\n" \
	"pop W8\n" \
	"pop W7\n" \
	"pop W6\n" \
	"pop W5\n" \
	"pop W4\n" \
	"pop W3\n" \
	"pop W2\n" \
	"pop W1\n" \
	"pop W0\n" \
	"pop SR\n" \
	"return");

#define dKernel_Suspend() asm volatile ( "CALL _Task_ChangeASM			\n"		\
                                        "NOP					  " );

inline void Kernel_ContextSave(void) { dKernel_ContextSave(); }
inline void Kernel_ContextRestore(void) { dKernel_ContextRestore(); }
inline void Kernel_Suspend(void) { dKernel_Suspend(); }

void Kernel_InitializeStack(TritonTask_t* Task, int* stack, void* function);

#endif

#endif /* KERNEL_H_ */
