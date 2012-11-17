#include "Devices/GraphicDisplay.h"
#include "RTOS/Task.h"


GraphicDisplay_DeviceCfg DISPLAY_SED1565 = {
    0xAF,
    0xAE,

    0xE2,

    0x40,
    0xB0,
    0x10,
    0x00,
};

void GraphicDisplay_Control(GraphicDisplay this);

#ifdef DEVICES_GRAPHIC_DISPLAY_USE_BUFFER
void GraphicDisplay_AssignBuffer(GraphicDisplay this, UI08_t* bf)
{
    this->buffer = bf;
    this->UseBuffer = 1;
    memset(bf, 0, this->width * this->height / 8+1);
}
#endif

#ifdef DEVICES_GRAPHIC_DISPLAY_USE_STATIC_IO
void GraphicDisplay_Init(GraphicDisplay this, GraphicDisplay_DeviceCfg* DisplayConfig, GraphicDisplay_GPIOCfg* GPIO, UI16_t w, UI16_t h)
{
    this->width = w;
    this->height = h;
    this->io = GPIO;
    this->Display = DisplayConfig;
    this->IODirection = INPUT;

    SGPIO_DirectionGPIO(GPIO->IO_E, OUTPUT);
    SGPIO_DirectionGPIO(GPIO->IO_RS, OUTPUT);
    SGPIO_DirectionGPIO(GPIO->IO_RW, OUTPUT);

    SGPIO_Write0GPIO(GPIO->IO_E);
    SGPIO_Write0GPIO(GPIO->IO_RS);
    SGPIO_Write0GPIO(GPIO->IO_RW);

    GraphicDisplay_SetIODirection(this, OUTPUT);

}

void GraphicDisplay_SetIODirection(GraphicDisplay this, UI08_t direction)
{
    UI08_t i ;
    if (this->IODirection != direction)
    {
        this->IODirection = direction;
        for(i = 0; i < 8; i++)
        {
            SGPIO_DirectionGPIO(this->io->IO_DATA[i], direction);
            SGPIO_Write0GPIO(this->io->IO_DATA[i]);
        }
    }
}
#else
void GraphicDisplay_Init(GraphicDisplay this, GraphicDisplay_DeviceCfg* DisplayConfig, UI16_t w, UI16_t h)
{
    this->width = w;
    this->height = h;
    this->Display = DisplayConfig;

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
void GraphicDisplay_SetIODirection(GraphicDisplay this, UI08_t direction)
{
    UI08_t i ;
    if (this->IODirection != direction)
    {
        this->IODirection = direction;
        for(i = 0; i < 8; i++)
        {
            SGPIO_DirectionGPIO(this->IO_DATA[i], direction);
            SGPIO_Write0GPIO(this->IO_DATA[i]);
        }
    }
}
#endif

void GraphicDisplay_Power(GraphicDisplay this, UI08_t p)
{
    this->DisplayOn = p;
    //GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, (this->display_on) ? this->Display->CMD_ON : this->Display->CMD_OFF);
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, 0b10101111); // power
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, 0b10100001); // adc
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, 0b10100110); // display normal
}

void GraphicDisplay_Clear(GraphicDisplay this)
{
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_RESET);
}
UI08_t l = 0;
void GraphicDisplay_Test(GraphicDisplay this)
{
    UI16_t x = 0, y = 0;
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_LINE);

    l = 1 - l;
    
    /*for( p = 0; p < 8; p++)
    {

        for(  i = 0; i <= 0b1111; i++)
        {
            for (j = 0; j < 8; j++)
            {

            GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_PAGE | p);
            GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_COL | j);
            GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_COL2 | i);

            if (l > 0)
            GraphicDisplay_Write(this, GraphicDisplay_DATA, 0x55);
            else
            GraphicDisplay_Write(this, GraphicDisplay_DATA, 0xAA);
            }

            //UI08_t t = GraphicDisplay_Read(this, GraphicDisplay_DATA);
           //GraphicDisplay_Write(this, GraphicDisplay_DATA, t);
            
        }
    }*/

    for (x=0; x < this->width; x++)
    {
        for(y = 0; y < this->height; y++)
        {
            //GraphicDisplay_Goto(this, x, y);
            GraphicDisplay_WritePixel(this, x, y, ((x%2 == l)?1:0));
            //GraphicDisplay_WritePixel(this, x, y+1, 1-l);
         }
    }
    for (x=0; x < this->width; x++)
    {
        for(y = 0; y < this->height; y++)
        {
            GraphicDisplay_Goto(this, x, y);
            UI08_t t = GraphicDisplay_Read(this, GraphicDisplay_DATA);
            GraphicDisplay_Goto(this, x, y);
            t = GraphicDisplay_Read(this, GraphicDisplay_DATA);
            
            GraphicDisplay_Goto(this, x, y);
            GraphicDisplay_Write(this, GraphicDisplay_DATA, t);
         }
    }
}

void GraphicDisplay_Goto(GraphicDisplay this, UI16_t x, UI16_t y)
{
    this->page = y/8;
    this->column_1 = x >> 4;
    this->column_2 = x & 0x0F;
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_PAGE | this->page);
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_COL  | this->column_1);
    GraphicDisplay_Write(this, GraphicDisplay_INSTRUCTION, this->Display->CMD_SET_COL2 | this->column_2);
}

void GraphicDisplay_WritePixel(GraphicDisplay this, UI16_t x, UI16_t y, UI08_t to)
{
    UI08_t bit_index = y%8;
    UI08_t data = 0;
    
#ifdef DEVICES_GRAPHIC_DISPLAY_USE_BUFFER
    UI16_t byte_index = y*this->width + x;
    byte_index /= 8;
    data = this->buffer[byte_index];
#else
    data = GraphicDisplay_ReadPixel(this, x, y);
#endif

    if (to)
        data |= 1<<bit_index;
    else
        data &= ~(1<<bit_index);

#ifdef DEVICES_GRAPHIC_DISPLAY_USE_BUFFER
    this->buffer [byte_index] = data;
#endif

    GraphicDisplay_Goto(this, x, y);
    GraphicDisplay_Write(this, GraphicDisplay_DATA, data);
}

UI08_t GraphicDisplay_ReadPixel(GraphicDisplay this, UI16_t x, UI16_t y)
{
    UI08_t bit_index = y%8;
    UI08_t data = 0;
#ifdef DEVICES_GRAPHIC_DISPLAY_USE_BUFFER
    UI08_t byte_index = x*y+x;
    byte_index /= 8;
     data = this->buffer[byte_index];
#else
    GraphicDisplay_Goto(this, x, y);
    data = GraphicDisplay_Read(this, GraphicDisplay_DATA);
#endif

    return ((data>>bit_index) & 0x1);
   
}

#ifndef DEVICES_GRAPHIC_DISPLAY_USE_STATIC_IO
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

// TODO: GraphicDisplay_Read
#else

void GraphicDisplay_Write(GraphicDisplay this, UI08_t type, UI08_t code)
{
    SI08_t i;

    if (type & GraphicDisplay_DATA )
    {
        SGPIO_WriteGPIO(this->io->IO_RS, GraphicDisplay_DATA);
    }
    else
    {
        SGPIO_WriteGPIO(this->io->IO_RS, GraphicDisplay_INSTRUCTION);
    }

    SGPIO_WriteGPIO(this->io->IO_RW, GraphicDisplay_RW_WRITE);


    GraphicDisplay_SetIODirection(this, OUTPUT);
    for (i = 7; i >= 0; i--)
    {
        SGPIO_WriteGPIO( this->io->IO_DATA[i] , ((code>>i)&0x1));
    }

    // Pulse E
    SGPIO_WriteGPIO( this->io->IO_E, 1 );
    SGPIO_WriteGPIO( this->io->IO_E, 0  );
}

UI08_t GraphicDisplay_Read(GraphicDisplay this, UI08_t type)
{
    SI08_t i;
    UI08_t data = 0;
    
    if (type & GraphicDisplay_DATA )
    {
        SGPIO_WriteGPIO(this->io->IO_RS, GraphicDisplay_DATA);
    }
    else
    {
        SGPIO_WriteGPIO(this->io->IO_RS, GraphicDisplay_INSTRUCTION);
    }

    SGPIO_WriteGPIO(this->io->IO_RW, GraphicDisplay_RW_READ);
    GraphicDisplay_SetIODirection(this, INPUT);

    // Pulse E
    SGPIO_WriteGPIO( this->io->IO_E, 1 );
    SGPIO_WriteGPIO( this->io->IO_E, 0  );

    for (i = 7; i >= 0; i--)
    {
        if ( SGPIO_ReadGPIO( this->io->IO_DATA[i]))
            data |= 1 << i;
    }
    return data;
}
#endif