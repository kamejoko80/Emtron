	.extern _Task_Change
	.extern uxCriticalNesting

.section *,code
.global _Task_ChangeASM
_Task_ChangeASM:

		PUSH	SR						/* Save the SR used by the task.... */
		PUSH	W0						/* ....then disable interrupts. */
		MOV		#32, W0
		MOV		W0, SR
		PUSH	W1						/* Save registers to the stack. */
		PUSH.D	W2
		PUSH.D	W4
		PUSH.D	W6
		PUSH.D 	W8
		PUSH.D 	W10
		PUSH.D	W12
		PUSH	W14
		PUSH	RCOUNT
		PUSH	TBLPAG
																						
		PUSH	CORCON
		PUSH	PSVPAG
		MOV		_uxCriticalNesting, W0		/* Save the critical nesting counter for the task. */
		PUSH	W0
		MOV		W15, _Task_CurrentStackLocation		/* Save the new top of stack into the TCB. */

		call 	_Task_Change

		MOV		_Task_CurrentStackLocation, W15			/* Restore the stack pointer for the task. */
		POP		W0							/* Restore the critical nesting counter for the task. */
		MOV		W0, _uxCriticalNesting
		POP		PSVPAG
		POP		CORCON
		POP		TBLPAG
		POP		RCOUNT						/* Restore the registers from the stack. */
		POP		W14
		POP.D	W12
		POP.D	W10
		POP.D	W8
		POP.D	W6
		POP.D	W4
		POP.D	W2
		POP.D	W0
		POP		SR

        return

        .end

