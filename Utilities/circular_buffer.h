
// TODO: Test sniff


#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include "RTOS/stddefs.h"
#define NR_OF_CIRCULARBUFFERS 0

typedef struct CircularBuffer_s
{
	UI08_t* buffer;
	UI16_t size;
	UI16_t readPtr;
	UI16_t writePtr;
	UI08_t overflow:1;
} CircularBuffer_t;

extern CircularBuffer_t CircularBuffers[NR_OF_CIRCULARBUFFERS];

void CircBuffer_Setup(UI08_t id, UI08_t* Buffer, UI16_t size);
void CircBuffer_Write(UI08_t id, UI08_t byte);
void CircBuffer_WriteBytes(UI08_t id, UI08_t* buf, UI16_t length);
UI08_t CircBuffer_Read(UI08_t id);
void CircBuffer_ReadBytes(UI08_t id, UI08_t* buf, UI16_t length);
UI16_t CircBuffer_Size(UI08_t id);
UI16_t CircBuffer_GetAvailable(UI08_t id);
void CircBuffer_JumpForward(UI08_t id, UI16_t amount);
void CircBuffer_Sniff(UI08_t id, UI08_t offset, UI08_t* buf, UI16_t length);
UI08_t CircBuffer_SniffByte(UI08_t id, UI08_t offset);
UI16_t CircBuffer_SniffInt16(UI08_t id, UI08_t offset);
UI32_t CircBuffer_SniffInt32(UI08_t id, UI08_t offset);
UI08_t CircBuffer_GetOverflow(UI08_t id);
void CircBuffer_Reset(UI08_t id);
UI08_t CircBuffer_ContainsChar(UI08_t ID, UI08_t Char);
UI08_t CircBuffer_ReadLine(UI08_t ID, UI08_t* Buffer);
#endif
