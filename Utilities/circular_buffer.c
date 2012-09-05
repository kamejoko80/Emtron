#define _CIRCULAR_BUFFER_C_SRC

#include "../stddefs.h"
#include "circular_buffer.h"

static void CircBufferMove(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize);
static UI16_t CircBufferGet(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize);

CircularBuffer_t CircularBuffers[NR_OF_CIRCULARBUFFERS];

void CircBufferSetup(UI08_t ID, UI08_t *Buffer, UI16_t Size)
{
	// ID correct?
	if (ID >= NR_OF_CIRCULARBUFFERS)
		return;

	/** SETUP **/
	CircularBuffers[ID] . buffer = Buffer;
	CircularBuffers[ID] . size = Size;

 	CircBufferReset(ID);
}

void CircBufferWrite(UI08_t ID, UI08_t byte)
{
	if(CircularBuffers[ID].overflow == 1) return;

	CircularBuffers[ID] . buffer[ CircularBuffers[ID] . writePtr ] = byte;

	// if next move causes an overflow
	if (CircBufferGet(ID, &(CircularBuffers[ID].writePtr),1) == CircularBuffers[ID] . readPtr)
	{
		CircularBuffers[ID].overflow = 1;
	}

	CircBufferMove(ID, &( CircularBuffers[ID] . writePtr ), 1);

}

void CircBufferWriteBytes(UI08_t ID, UI08_t* buf, UI16_t Length)
{
	UI16_t i = 0;
	while (i != Length)
	{
		CircBufferWrite(ID, buf[i]);
		i++;
	}

}

UI08_t CircBufferRead(UI08_t ID)
{
	UI08_t data = CircularBuffers[ID] . buffer[ CircularBuffers[ID] . readPtr ];

	CircBufferMove(ID, &( CircularBuffers[ID] . readPtr ), 1);

	return data;
}

void CircBufferReadBytes(UI08_t ID, UI08_t* buf, UI16_t Length)
{
	UI16_t i = 0;

	while (i != Length)
	{
		buf[i] = CircBufferRead(ID);
		i++;
	}

}

UI16_t CircBufferSize(UI08_t ID)
{
	return CircularBuffers[ID] . size;
}


UI16_t CircBufferGetAvailable(UI08_t ID)
{
	if (CircularBuffers[ID] . overflow != 0)
		return 0xFF;
	// read&write equal -> size 0
	if (CircularBuffers[ID] . readPtr == CircularBuffers[ID] . writePtr)
		return 0;
	if (CircularBuffers[ID] . readPtr > CircularBuffers[ID] . writePtr)
	{
		// Write pointer is has been set back to 0,
		// so size is: writePtr+length - readPtr
		return (CircularBuffers[ID] . writePtr + CircularBuffers[ID] . size - CircularBuffers[ID] . readPtr);
	}
	else
	{
		return (CircularBuffers[ID] . writePtr - CircularBuffers[ID] . readPtr);
	}

}

void CircBufferJumpForward(UI08_t ID, UI16_t Amount)
{
	UI16_t DataAvailable = CircBufferGetAvailable(ID);
	if(Amount > DataAvailable)
		Amount = DataAvailable;

	CircBufferMove(ID, &( CircularBuffers[ID] . readPtr ), Amount);

}

UI08_t CircBufferReadLine(UI08_t ID, UI08_t* Buffer)
{
	// Check if there is a \n in the buffer
	if (CircBufferContainsChar(ID, 0x0D)) // = '\n'
	{
		do
		{
			*Buffer = CircBufferRead(ID);
		}
                while (*Buffer++ != 0x0D);
                return 1;
	}
	else
		return 0;
}

UI08_t CircBufferContainsChar(UI08_t ID, UI08_t Char)
{
	UI08_t b, i = 0;

	for (i = 0 ; i < CircBufferGetAvailable(ID); i++)
	{
		b = CircBufferSniffByte(ID, i);
		if (b == Char)
			return 1;
	}

	return 0;
}

void CircBufferSniff(UI08_t ID, UI08_t offset, UI08_t* buf, UI16_t Length)
{
	UI16_t i = 0;
	while(i != Length)
	{
		buf[i] = CircBufferSniffByte(ID, offset+i);
		i++;
	}

}

UI08_t CircBufferSniffByte(UI08_t ID, UI08_t offset)
{
	UI16_t index = CircBufferGet(ID, &( CircularBuffers[ID] . readPtr ), offset);

	return CircularBuffers[ID] . buffer[index];
}

UI16_t CircBufferSniffInt16(UI08_t ID, UI08_t offset)
{
	UI16_t data = 0;
	CircBufferSniff(ID, offset, (UI08_t*)&data, sizeof(UI16_t));
	return data;
}

UI32_t CircBufferSniffInt32(UI08_t ID, UI08_t offset)
{
	UI32_t data = 0;
	CircBufferSniff(ID, offset, (UI08_t*)&data, sizeof(UI32_t));
	return data;
}

UI08_t CircBufferGetOverflow(UI08_t ID)
{
	return CircularBuffers[ID] . overflow;
}

void CircBufferReset(UI08_t ID)
{
	CircularBuffers[ID] . overflow = 0;
	CircularBuffers[ID] . readPtr = 0;
	CircularBuffers[ID] . writePtr = 0;

	memset(CircularBuffers[ID] . buffer, 0, CircularBuffers[ID] . size);
}


void CircBufferMove(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize)
{
	UI16_t newIndex = CircBufferGet(ID, bufPtr, jumpSize);
	*bufPtr = newIndex;
}

UI16_t CircBufferGet(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize)
{
	UI16_t newIndex = *bufPtr + jumpSize;
	newIndex = newIndex % CircularBuffers[ID] . size;
	return newIndex;
}
