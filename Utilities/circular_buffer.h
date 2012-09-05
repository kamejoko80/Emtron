
// TODO: Test sniff


#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H

#include "../stddefs.h"
#define NR_OF_CIRCULARBUFFERS 1

typedef struct CircularBuffer_s
{
	UI08_t* buffer;
	UI16_t size;
	UI16_t readPtr;
	UI16_t writePtr;
	UI08_t overflow;
} CircularBuffer_t;

extern CircularBuffer_t CircularBuffers[NR_OF_CIRCULARBUFFERS];

void CircBufferSetup(UI08_t id, UI08_t* Buffer, UI16_t size);
void CircBufferWrite(UI08_t id, UI08_t byte);
void CircBufferWriteBytes(UI08_t id, UI08_t* buf, UI16_t length);
UI08_t CircBufferRead(UI08_t id);
void CircBufferReadBytes(UI08_t id, UI08_t* buf, UI16_t length);
UI16_t CircBufferSize(UI08_t id);
UI16_t CircBufferGetAvailable(UI08_t id);
void CircBufferJumpForward(UI08_t id, UI16_t amount);
void CircBufferSniff(UI08_t id, UI08_t offset, UI08_t* buf, UI16_t length);
UI08_t CircBufferSniffByte(UI08_t id, UI08_t offset);
UI16_t CircBufferSniffInt16(UI08_t id, UI08_t offset);
UI32_t CircBufferSniffInt32(UI08_t id, UI08_t offset);
UI08_t CircBufferGetOverflow(UI08_t id);
void CircBufferReset(UI08_t id);
UI08_t CircBufferContainsChar(UI08_t ID, UI08_t Char);
UI08_t CircBufferReadLine(UI08_t ID, UI08_t* Buffer);
#endif
