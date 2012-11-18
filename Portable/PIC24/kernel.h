#ifndef PORTABLE_PIC24_KERNEL_H
#define PORTABLE_PIC24_KERNEL_H

#include "RTOS/stddefs.h"

#ifdef TARGET_PIC24

#define Kernel_Sleep() asm volatile("PWRSAV #1");//enter idle mode, wakeup by interrupt.

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

#define dKernel_Suspend() asm volatile (  "CALL _Task_ChangeASM\n" );

#endif

#endif
