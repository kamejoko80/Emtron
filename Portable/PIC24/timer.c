#include "Portable/PIC24/timer.h"

#ifdef TARGET_PIC24
void Timer_OpenSysTimer(void)
{
    T1CON = 0;//off
    TMR1=0;//reset
    PR1=CLOCK_PERIPHERAL/1000; // 1kHz
    IPC0bits.T1IP = 0x01; //Setup Timer1 interrupt for desired priority level
    IFS0bits.T1IF = 0; //Clear the Timer1 interrupt status flag
    IEC0bits.T1IE = 1; //Enable Timer1 interrupts
    T1CONbits.TCKPS = 0b00; // No prescale
}

void Timer_StartSysTimer(void)
{
    T1CONbits.TON=1;
}

void Timer_ClrSysTimerInt(void)
{
    IFS0bits.T1IF = 0;
}
#endif
