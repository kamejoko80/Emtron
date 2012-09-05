/*
 * timer.h
 *
 *  Created on: Jun 10, 2012
 *      Author: Hans
 */

#ifndef TIMER_H
#define TIMER_H

#include "portable.h"

#ifdef PORT__PIC24_H
void Timer_OpenSysTimer(void);
void Timer_StartSysTimer(void);
void Timer_ClrSysTimerInt(void);
#endif

#endif /* TIMER_H_ */
