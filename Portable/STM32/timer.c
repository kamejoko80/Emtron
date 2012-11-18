#include "Portable/STM32/timer.h"
#include "stm32f40x.h"

#ifdef TARGET_STM32
void Timer_OpenSysTimer(void)
{
  SysTick_Config(SystemCoreClock / 1); // temporarely very slow..
}
void Timer_StartSysTimer(void) {

  SysTick_Config(SystemCoreClock / 2000); // 1000 interrupts per second.
}

// SysTick doesn't require this.
void Timer_ClrSysTimerInt(void) 
{
} 

#endif
