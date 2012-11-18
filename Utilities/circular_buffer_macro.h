#ifndef UTILITIES_CIRCULAR_BUFFER_MACRO_H
#define UTILITIES_CIRCULAR_BUFFER_MACRO_H

#include "RTOS/stddefs.h"

#define m_CircularBuffer_WriteBytes(inst, buffer, size) \
UI08_t m_CircBuffer_i = 0; \
while(m_CircBuffer_i < size) \
{ \
    m_CircularBuffer_WriteByte(inst, ((UI08_t*)buffer)[m_CircBuffer_i++]); \
}
#define m_CircularBuffer_WriteByte(inst, byte) \
inst->circ_buffer[inst->circ_writePtr] = (UI08_t)byte; \
inst->circ_count++; \
if(++inst->circ_writePtr > inst->circ_size) inst->circ_writePtr = 0; \

#define m_CircularBuffer_ReadByte(inst, byte) \
byte = inst->circ_buffer[inst->circ_readPtr]; \
if (inst->circ_count > 0) inst->circ_count--; \
if(++inst->circ_readPtr > inst->circ_size) inst->circ_readPtr = 0;

#define m_CircularBuffer_ReadBytes(inst, buffer, size) \
UI08_t m_CircBuffer_i = 0; \
while(m_CircBuffer_i < size) \
{ \
    m_CircularBuffer_ReadByte(inst, ((UI08_t*)buffer)[m_CircBuffer_i++]); \
}

#define m_CircularBuffer_Available(inst, amount) \
amount = inst->circ_count;

#define m_CircularBuffer_Reset(inst, size) \
inst->circ_readPtr = 0; \
inst->circ_writePtr = 0; \
inst->circ_count = 0; \
inst->circ_size = size;

#endif
