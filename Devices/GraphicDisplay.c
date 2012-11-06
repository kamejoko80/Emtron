#include "Devices/GraphicDisplay.h"
#include "RTOS/Task.h"

GraphicDisplayCfg DISPLAY_SED1565 = {
    0xAF,
    0xAE,

    0xE2,

    0x40,
    0xB0,
    0x10,
    0x00,
};

void GraphicDisplay_Write(GraphicDisplay this, UI08_t type, UI08_t code);
void GraphicDisplay_Control(GraphicDisplay this);
void GraphicDisplay_Delay(void);

void GraphicDisplay_Init(GraphicDisplay this, GraphicDisplayCfg* DisplayConfig, UI16_t w, UI16_t h)
{
    this->width = w;
    this->height = h;
    this->Display = DisplayConfig;

}

void GraphicDisplay_Power(GraphicDisplay this, UI08_t p)
{
    this->display_on = p;
    //GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, (this->display_on) ? this->Display->CMD_ON : this->Display->CMD_OFF);
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, 0b10101111); // power
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, 0b10100001); // adc
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, 0b10100110); // display normal
}

void GraphicDisplay_GPIO(GraphicDisplay this, GraphicDisplayIO io, const IOPin_t gpio)
{
    switch(io)
    {
        case GraphicDisplay_IO_E:
            this->IO_E = gpio;
            break;
        case GraphicDisplay_IO_RS:
            this->IO_RS = gpio;
            break;
        case GraphicDisplay_IO_RW:
            this->IO_RW = gpio;
            break;
        case GraphicDisplay_IO_D0:
        case GraphicDisplay_IO_D1:
        case GraphicDisplay_IO_D2:
        case GraphicDisplay_IO_D3:
        case GraphicDisplay_IO_D4:
        case GraphicDisplay_IO_D5:
        case GraphicDisplay_IO_D6:
        case GraphicDisplay_IO_D7:
            this->IO_DATA[(io&0xF)] = gpio;
            break;
    }

    SGPIO_DirectionGPIO(gpio, OUTPUT);
    SGPIO_WriteGPIO(gpio, 0);
}

void GraphicDisplay_Clear(GraphicDisplay this)
{
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_RESET);
}
void GraphicDisplay_Test(GraphicDisplay this)
{
    UI08_t i =0, j = 0, p =0;
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_LINE);

    for( p = 0; p < 8; p++)
    {

        for(  i = 0; i <= 0b1111; i++)
        {
            for (j = 0; j < 8; j++)
            {

            GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_PAGE | p);
            GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_COL | j);
            GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_COL2 | i);

            GraphicDisplay_Write(this, GraphicDisplay_DATA, 0xAA);
            }
        }
    }
}

void GraphicDisplay_Write(GraphicDisplay this, UI08_t type, UI08_t code)
{
    SI08_t v=0,i = 7;

    if (type & GraphicDisplay_DATA )
    {
        SGPIO_WriteGPIO(this->IO_RS, GraphicDisplay_DATA);
    }
    else
    {
        SGPIO_WriteGPIO(this->IO_RS, GraphicDisplay_INSTRUCTION);
    }

    SGPIO_WriteGPIO(this->IO_RW, GraphicDisplay_RW_WRITE);

    for (; i >= 0; i--)
    {
        v=((code>>i)&0x1);
        SGPIO_WriteGPIO( this->IO_DATA[i] , v);
    }

    // Pulse E
    SGPIO_Write1GPIO( this->IO_E );
    SGPIO_Write0GPIO( this->IO_E );
}

