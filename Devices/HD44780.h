#ifndef EMTRON_DEVICES_HD44780_H
#define EMTRON_DEVICES_HD44780_H
#include "RTOS/stddefs.h"

#define HD44780_RW_WRITE 0
#define HD44780_RW_READ 1

#define HD44780_RS_INSTRUCTION 0x00
#define HD44780_RS_DATA 0x01
#define HD44780_E_CONTROLLER1 0x10
#define HD44780_E_CONTROLLER2 0x20
#define HD44780_E_CONTROLLER12 0x30

typedef struct HD44780_t * HD44780;
typedef enum HD44780Mode
{
    HD44780_4BIT,
    HD44780_8BIT

} HD44780Mode;

typedef enum HD44780IO
{
    HD44780_IO_E1,
    HD44780_IO_E2,
    HD44780_IO_RS,
    HD44780_IO_RW,
    HD44780_IO_D0 = 0x10,
    HD44780_IO_D1,
    HD44780_IO_D2,
    HD44780_IO_D3,
    HD44780_IO_D4,
    HD44780_IO_D5,
    HD44780_IO_D6,
    HD44780_IO_D7
} HD44780IO;

void HD44780_Init(HD44780 this, UI08_t w, UI08_t h);
void HD44780_Clear(HD44780 this);
void HD44780_Mode(HD44780 this, HD44780Mode mode);
void HD44780_GPIO(HD44780 this, HD44780IO io, const IOPin_t gpio);
void HD44780_Power(HD44780 this, UI08_t p);
void HD44780_PutChar(HD44780 this, UI08_t row, UI08_t col, char k);
void HD44780_PutString(HD44780 this, UI08_t row, UI08_t col, char* k);
void HD44780_Cursor(HD44780 this, UI08_t p, UI08_t blink);

typedef struct HD44780_t
{
    /*** IO CONFIG ***/
    IOPin_t IO_E1;
    IOPin_t IO_E2;
    IOPin_t IO_RS;
    IOPin_t IO_RW;
    IOPin_t IO_DATA[8];

    /*** SETTINGS ***/

    HD44780Mode mode:1;
    UI08_t dualcontroller:1;
    UI08_t display_on:1;
    UI08_t cursor_on:1;
    UI08_t cursor_blink:1;
    
    UI08_t height:3;
    UI08_t width;
}  HD44780_t;

#endif
