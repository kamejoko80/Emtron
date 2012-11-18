#include "RTOS/portable.h"
#include "RTOS/stddefs.h"

#ifdef TARGET_STM32

// 40020000 = A
// 40020400 = B

const IOPort_t IOPorts[NUM_PORTS] = {
  // in/out, in_value, out_value, pull-ups
  {PTR32(0x40020000+0x0), PTR32(0x40020010), PTR32(0x40020014), PTR32(0x4002000C)},
  {PTR32(0x40020400+0x0), PTR32(0x40020410), PTR32(0x40020414), PTR32(0x4002040C)},
  {PTR32(0x40020800+0x0), PTR32(0x40020810), PTR32(0x40020814), PTR32(0x4002080C)},
  {PTR32(0x40020C00+0x0), PTR32(0x40020C10), PTR32(0x40020C14), PTR32(0x40020C0C)},
//    {PTR32(GPIOA_BASE + 0x10), PTR32(0x2C2), PTR32(0x2C4), PTR32(0x2C6)} // Port A
    /*#if NUM_PORTS >= 2
        ,{PTR32(0x2C8), PTR32(0x2CA), PTR32(0x2CC), PTR32(0x2CE)} // Port B
    #endif
    #if NUM_PORTS >= 3
        ,{PTR32(0x2D0), PTR32(0x2D2), PTR32(0x2D4), PTR32(0x2D6)} // Port C
    #endif
    #if NUM_PORTS >= 4
        ,{PTR32(0x2D8), PTR32(0x2DA), PTR32(0x2DC), PTR32(0x2DE)} // Port D
    #endif*/
};
void FW_Init(void)
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
}

#endif