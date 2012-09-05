#include "kernel.h"

#ifdef PORT__PIC24_H
const int PIC24_InitialStack[] =
{
	0x1111,	/* W1 */
	0x2222, /* W2 */
	0x3333, /* W3 */
	0x4444, /* W4 */
	0x5555, /* W5 */
	0x6666, /* W6 */
	0x7777, /* W7 */
	0x8888, /* W8 */
	0x9999, /* W9 */
	0xaaaa, /* W10 */
	0xbbbb, /* W11 */
	0xcccc, /* W12 */
	0xdddd, /* W13 */
	0xeeee, /* W14 */
	0xcdce, /* RCOUNT */
	0xabac, /* TBLPAG */
};
// TODO: Replace with portable code
void Kernel_InitializeStack(TritonTask_t* Task, int* stack, void* function)
{
	int  i = 0;
	int* TOS=stack;

	*TOS = (int)function; TOS++; 	// low byte PC
        *TOS = 0; TOS++; 				// high byte PC
	*TOS = 0; TOS++; 				// initial SR
	*TOS = 0; TOS++;				 // W0.

	// Add W1-W14, RCOUNT and TBLPAG
	for (i = 0; i <  16; i++)
	{
		*TOS = PIC24_InitialStack[i];
		TOS++;
	}

	// Add CORCON and PSVPAG
	*TOS = CORCON; TOS++;			// CORCON
	*TOS = PSVPAG; TOS++;			// PSVPAG
	*TOS = 0; TOS++; 				// Nesting depth

	// Assign objects to task object.
	Task->Stack = stack;
	Task->Method = function;
	Task->StackPosition = TOS;
}
#endif
