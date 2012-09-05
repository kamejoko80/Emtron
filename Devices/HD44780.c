#include "HD44780.h"
#include "stddefs.h"


void HD44780_Write(HD44780 this, UI08_t type, UI08_t code);
void HD44780_Control(HD44780 this);
void HD44780_Delay(void);

void HD44780_Delay(void)
{
    // TODO: Detect OS
    // TODO: Globalize
    UI16_t  j =0 ;
    for(j = 0; j < 200; j++)
        asm volatile("nop");

}

void HD44780_Init(HD44780 this, UI08_t w, UI08_t h)
{
    this->width = w;
    this->height = h;

    this->mode = HD44780_8BIT;
    this->cursor_blink = 0;
    this->cursor_on = 1;
    this->display_on = 0;

    HD44780_Write(this, HD44780_E_CONTROLLER12 | HD44780_RS_INSTRUCTION, 0b00111000);
}

void HD44780_Power(HD44780 this, UI08_t p)
{
    this->display_on = p;
    HD44780_Control(this);
}
void HD44780_Cursor(HD44780 this, UI08_t p, UI08_t blink)
{
    this->cursor_on = p;
    this->cursor_blink = blink;
    HD44780_Control(this);
}

void HD44780_Mode(HD44780 this, HD44780Mode mode)
{
    this->mode = mode;
}

void HD44780_GPIO(HD44780 this, HD44780IO io, const IOPin_t gpio)
{
    switch(io)
    {
        case HD44780_IO_E1:
            this->IO_E1 = gpio;
            break;
        case HD44780_IO_E2:
            this->dualcontroller = 1;
            this->IO_E2 = gpio;
            break;
        case HD44780_IO_RS:
            this->IO_RS = gpio;
            break;
        case HD44780_IO_RW:
            this->IO_RW = gpio;
            break;
        case HD44780_IO_D0:
        case HD44780_IO_D1:
        case HD44780_IO_D2:
        case HD44780_IO_D3:
        case HD44780_IO_D4:
        case HD44780_IO_D5:
        case HD44780_IO_D6:
        case HD44780_IO_D7:
            this->IO_DATA[(io&0xF)] = gpio;
            break;
    }

    SGPIO_DirectionGPIO(gpio, OUTPUT);
    SGPIO_WriteGPIO(gpio, 1);
}

void HD44780_Clear(HD44780 this)
{
    HD44780_Write(this, HD44780_E_CONTROLLER12 | HD44780_RS_INSTRUCTION, 0);
}

void HD44780_Control(HD44780 this)
{
    HD44780_Write(this, HD44780_E_CONTROLLER12 | HD44780_RS_INSTRUCTION,
            (1<<3) |
            (this->display_on<<2) |
            (this->cursor_on << 1) |
            (this->cursor_blink));
}

void HD44780_PutChar(HD44780 this, UI08_t row, UI08_t col, char k)
{
    int row_offsets[] = { 0x00, 0x40, this->width, 0x40+this->width};
    volatile UI08_t control = 0;
    if(this->dualcontroller)
    {
        if(row == 0 || row == 1)
        {
            control = HD44780_E_CONTROLLER1;
        }
        else
        {
            control = HD44780_E_CONTROLLER2;
            row -= 2;
        }
    }
    else
       control = HD44780_E_CONTROLLER1;
    HD44780_Write(this, control | HD44780_RS_INSTRUCTION,
            (1<<7) |
            (0x7F & (row_offsets[row] + col)));
    HD44780_Write(this, control | HD44780_RS_DATA,
            k);

}

void HD44780_PutString(HD44780 this, UI08_t row, UI08_t col, char* k)
{
    UI08_t c = col, r=row;
    while(*k != '\0')
    {
        HD44780_PutChar(this, r, c, *k);
        k++;
        c++;
        if(c==this->width)
        {
            c = 0;
            r++;
        }
    }

}

void HD44780_Write(HD44780 this, UI08_t type, UI08_t code)
{
    SI08_t v=0,i = ((this->mode == HD44780_4BIT)?3:7);

    if (type & HD44780_RS_DATA )
    {
        SGPIO_WriteGPIO(this->IO_RS, HD44780_RS_DATA);
    }
    else
    {
        SGPIO_WriteGPIO(this->IO_RS, HD44780_RS_INSTRUCTION);
    }

     SGPIO_WriteGPIO(this->IO_RW, HD44780_RW_WRITE);

    for (; i >= 0; i--)
    {
        v=((code>>i)&0x1);
        SGPIO_WriteGPIO( this->IO_DATA[i] , v);
    }

    // Pulse E 0
    if((type & HD44780_E_CONTROLLER1) != 0)
    {
        SGPIO_Write0GPIO( this->IO_E1 );
        SGPIO_Write1GPIO( this->IO_E1 );
    }
    if (this->dualcontroller && (type & HD44780_E_CONTROLLER2) != 0)
    {
        SGPIO_Write0GPIO( this->IO_E2 );
        SGPIO_Write1GPIO( this->IO_E2 );
    }
    HD44780_Delay();
}

