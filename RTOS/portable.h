#ifndef TRITON_PORTABLE_H
#define TRITON_PORTABLE_H 1

#include "project.h"
// All PIC24 devices:
#include "Portable/PIC24/PIC24.h"


#ifndef CLOCK_CPU
	#error "CPU configuration didn't specify CPU clock in Hz"
#endif

#ifndef CLOCK_PERIPHERAL
	#error "CPU configuration didn't specify peripheral clock in Hz"
#endif

#define GPIO_Direction_INPUT GPIO_Direction_Input
#define GPIO_Direction_OUTPUT GPIO_Direction_Output
#define GPIO_Direction_IN GPIO_Direction_Input
#define GPIO_Direction_OUT GPIO_Direction_Output
#define INPUT GPIO_Direction_Input
#define OUTPUT GPIO_Direction_Output


void FW_Init(void);

inline void Kernel_ContextSave(void);
inline void Kernel_ContextRestore(void);
inline void Kernel_Suspend(void);

#endif
