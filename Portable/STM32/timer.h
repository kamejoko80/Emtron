#ifndef TIMER_H
#define TIMER_H

#include "RTOS/portable.h"

#ifdef TARGET_STM32
void Timer_OpenSysTimer(void);
void Timer_StartSysTimer(void);
void Timer_ClrSysTimerInt(void);
#endif

#endif
