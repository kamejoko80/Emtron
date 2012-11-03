#define _CIRCULAR_BUFFER_C_SRC

#include "RTOS/stddefs.h"
#include "Utilities/circular_buffer.h"
#include <string.h>

static void CircBuffer_Move(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize);
static UI16_t CircBuffer_Get(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize);

CircularBuffer_t CircularBuffers[NR_OF_CIRCULARBUFFERS];

void CircBuffer_Setup(UI08_t ID, UI08_t *Buffer, UI16_t Size)
{
	// ID correct?
	if (ID >= NR_OF_CIRCULARBUFFERS)
		return;

	/** SETUP **/
	CircularBuffers[ID] . buffer = Buffer;
	CircularBuffers[ID] . size = Size;

 	CircBuffer_Reset(ID);
}

void CircBuffer_Write(UI08_t ID, UI08_t byte)
{
	if(CircularBuffers[ID].overflow == 1) return;

	CircularBuffers[ID] . buffer[ CircularBuffers[ID] . writePtr ] = byte;

	// if next move causes an overflow
	if (CircBuffer_Get(ID, &(CircularBuffers[ID].writePtr),1) == CircularBuffers[ID] . readPtr)
	{
		CircularBuffers[ID].overflow = 1;
	}

	CircBuffer_Move(ID, &( CircularBuffers[ID] . writePtr ), 1);

}

void CircBuffer_WriteBytes(UI08_t ID, UI08_t* buf, UI16_t Length)
{
	UI16_t i = 0;
	while (i != Length)
	{
		CircBuffer_Write(ID, buf[i]);
		i++;
	}

}

UI08_t CircBuffer_Read(UI08_t ID)
{
	UI08_t data = CircularBuffers[ID] . buffer[ CircularBuffers[ID] . readPtr ];

	CircBuffer_Move(ID, &( CircularBuffers[ID] . readPtr ), 1);

	return data;
}

void CircBuffer_ReadBytes(UI08_t ID, UI08_t* buf, UI16_t Length)
{
	UI16_t i = 0;

	while (i != Length)
	{
		buf[i] = CircBuffer_Read(ID);
		i++;
	}

}

UI16_t CircBuffer_Size(UI08_t ID)
{
	return CircularBuffers[ID] . size;
}


UI16_t CircBuffer_GetAvailable(UI08_t ID)
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

void CircBuffer_JumpForward(UI08_t ID, UI16_t Amount)
{
	UI16_t DataAvailable = CircBuffer_GetAvailable(ID);
	if(Amount > DataAvailable)
		Amount = DataAvailable;

	CircBuffer_Move(ID, &( CircularBuffers[ID] . readPtr ), Amount);

}

UI08_t CircBuffer_ReadLine(UI08_t ID, UI08_t* Buffer)
{
	// Check if there is a \n in the buffer
	if (CircBuffer_ContainsChar(ID, 0x0D)) // = '\n'
	{
		do
		{
			*Buffer = CircBuffer_Read(ID);
		}
                while (*Buffer++ != 0x0D);
                return 1;
	}
	else
		return 0;
}

UI08_t CircBuffer_ContainsChar(UI08_t ID, UI08_t Char)
{
	UI08_t b, i = 0;

	for (i = 0 ; i < CircBuffer_GetAvailable(ID); i++)
	{
		b = CircBuffer_SniffByte(ID, i);
		if (b == Char)
			return 1;
	}

	return 0;
}

void CircBuffer_Sniff(UI08_t ID, UI08_t offset, UI08_t* buf, UI16_t Length)
{
	UI16_t i = 0;
	while(i != Length)
	{
		buf[i] = CircBuffer_SniffByte(ID, offset+i);
		i++;
	}

}

UI08_t CircBuffer_SniffByte(UI08_t ID, UI08_t offset)
{
	UI16_t index = CircBuffer_Get(ID, &( CircularBuffers[ID] . readPtr ), offset);

	return CircularBuffers[ID] . buffer[index];
}

UI16_t CircBuffer_SniffInt16(UI08_t ID, UI08_t offset)
{
	UI16_t data = 0;
	CircBuffer_Sniff(ID, offset, (UI08_t*)&data, sizeof(UI16_t));
	return data;
}

UI32_t CircBuffer_SniffInt32(UI08_t ID, UI08_t offset)
{
	UI32_t data = 0;
	CircBuffer_Sniff(ID, offset, (UI08_t*)&data, sizeof(UI32_t));
	return data;
}

UI08_t CircBuffer_GetOverflow(UI08_t ID)
{
	return CircularBuffers[ID] . overflow;
}

void CircBuffer_Reset(UI08_t ID)
{
	CircularBuffers[ID] . overflow = 0;
	CircularBuffers[ID] . readPtr = 0;
	CircularBuffers[ID] . writePtr = 0;

	memset(CircularBuffers[ID] . buffer, 0, CircularBuffers[ID] . size);
}


void CircBuffer_Move(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize)
{
	UI16_t newIndex = CircBuffer_Get(ID, bufPtr, jumpSize);
	*bufPtr = newIndex;
}

UI16_t CircBuffer_Get(UI08_t ID, UI16_t* bufPtr, UI16_t jumpSize)
{
	UI16_t newIndex = *bufPtr + jumpSize;
	newIndex = newIndex % CircularBuffers[ID] . size;
	return newIndex;
}
