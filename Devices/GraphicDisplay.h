#ifndef EMTRON_DEVICES_GraphicDisplay_H
#define EMTRON_DEVICES_GraphicDisplay_H
#include "RTOS/stddefs.h"

#define GraphicDisplay_RW_WRITE 0
#define GraphicDisplay_RW_READ 1

#define GraphicDisplay_INSTRUCTION 0x00
#define GraphicDisplay_DATA 0x01

typedef struct GraphicDisplay_DeviceCfg_s
{
    UI08_t CMD_ON;
    UI08_t CMD_OFF;

    UI08_t CMD_RESET;
    UI08_t CMD_LINE;
    UI08_t CMD_SET_PAGE;
    UI08_t CMD_SET_COL;
    UI08_t CMD_SET_COL2; 
} GraphicDisplay_DeviceCfg_t;
typedef const GraphicDisplay_DeviceCfg_t GraphicDisplay_DeviceCfg;

typedef struct GraphicDisplay_GPIOCfg_s
{
    IOPin_t IO_E;
    IOPin_t IO_RS;
    IOPin_t IO_RW;
    IOPin_t IO_DATA[8];
    
} GraphicDisplay_GPIOCfg_t;
typedef const GraphicDisplay_GPIOCfg_t GraphicDisplay_GPIOCfg;


typedef struct GraphicDisplay_t * GraphicDisplay;

typedef struct GraphicDisplay_t
{
    GraphicDisplay_DeviceCfg* Display;

    /*** IO CONFIG ***/
#ifndef DEVICES_GRAPHIC_DISPLAY_USE_STATIC_IO
    IOPin_t IO_RS;
    IOPin_t IO_E;
    IOPin_t IO_RW;
    IOPin_t IO_DATA[8];
#else
    GraphicDisplay_GPIOCfg* io;
#endif

    /*** SETTINGS ***/

    UI08_t IODirection:1;
    UI08_t DisplayOn:1;
    UI08_t UseBuffer:1;

    UI16_t width;
    UI16_t height;

    /*** WORK REGISTERS ***/
    UI16_t x;
    UI16_t y;

    UI08_t page;
    UI08_t column_1;
    UI08_t column_2;

    /*** BUFFER ***/
    #ifdef DEVICES_GRAPHIC_DISPLAY_USE_BUFFER
    UI08_t* buffer;
    #endif
}  GraphicDisplay_t;

typedef enum GraphicDisplayIO
{
    GraphicDisplay_IO_E,
    GraphicDisplay_IO_RS,
    GraphicDisplay_IO_RW,
    GraphicDisplay_IO_D0 = 0x10,
    GraphicDisplay_IO_D1,
    GraphicDisplay_IO_D2,
    GraphicDisplay_IO_D3,
    GraphicDisplay_IO_D4,
    GraphicDisplay_IO_D5,
    GraphicDisplay_IO_D6,
    GraphicDisplay_IO_D7
} GraphicDisplayIO;

extern GraphicDisplay_DeviceCfg DISPLAY_SED1565;

#ifdef DEVICES_GRAPHIC_DISPLAY_USE_BUFFER
void GraphicDisplay_AssignBuffer(GraphicDisplay this, UI08_t* bf);
#endif
#ifdef DEVICES_GRAPHIC_DISPLAY_USE_STATIC_IO
void GraphicDisplay_Init(GraphicDisplay this, GraphicDisplay_DeviceCfg* DisplayConfig, GraphicDisplay_GPIOCfg* GPIO, UI16_t w, UI16_t h);
#else
void GraphicDisplay_Init(GraphicDisplay this, GraphicDisplay_DeviceCfg* DisplayConfig, UI16_t w, UI16_t h);
void GraphicDisplay_GPIO(GraphicDisplay this, GraphicDisplayIO io, const IOPin_t gpio);
#endif
void GraphicDisplay_SetIODirection(GraphicDisplay this, UI08_t direction);
void GraphicDisplay_Clear(GraphicDisplay this);
void GraphicDisplay_Test(GraphicDisplay this);
void GraphicDisplay_Power(GraphicDisplay this, UI08_t p);

UI08_t GraphicDisplay_Read(GraphicDisplay this, UI08_t type);
void GraphicDisplay_Write(GraphicDisplay this, UI08_t type, UI08_t code);

void GraphicDisplay_WritePixel(GraphicDisplay this, UI16_t x, UI16_t y, UI08_t to);
UI08_t GraphicDisplay_ReadPixel(GraphicDisplay this, UI16_t x, UI16_t y);
void GraphicDisplay_Goto(GraphicDisplay this, UI16_t x, UI16_t y);
#endif
