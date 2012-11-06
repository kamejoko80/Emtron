#ifndef EMTRON_DEVICES_GraphicDisplay_H
#define EMTRON_DEVICES_GraphicDisplay_H
#include "RTOS/stddefs.h"

#define GraphicDisplay_RW_WRITE 0
#define GraphicDisplay_RW_READ 1

#define GraphicDisplay_INSTRUCTION 0x00
#define GraphicDisplay_DATA 0x01

typedef struct GraphicDisplayCfg_s
{
    UI08_t CMD_ON;
    UI08_t CMD_OFF;

    UI08_t CMD_RESET;
    UI08_t CMD_LINE;
    UI08_t CMD_SET_PAGE;
    UI08_t CMD_SET_COL;
    UI08_t CMD_SET_COL2; 
} GraphicDisplayCfg_t;
typedef const GraphicDisplayCfg_t GraphicDisplayCfg;

typedef struct GraphicDisplay_t * GraphicDisplay;

typedef struct GraphicDisplay_t
{
    GraphicDisplayCfg* Display;

    /*** IO CONFIG ***/
    IOPin_t IO_RS;
    IOPin_t IO_E;
    IOPin_t IO_RW;
    IOPin_t IO_DATA[8];

    /*** SETTINGS ***/

    UI08_t display_on:1;

    UI16_t height;
    UI16_t width;
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

extern GraphicDisplayCfg DISPLAY_SED1565;


void GraphicDisplay_Init(GraphicDisplay this, GraphicDisplayCfg* DisplayConfig, UI16_t w, UI16_t h);
void GraphicDisplay_Clear(GraphicDisplay this);
void GraphicDisplay_Test(GraphicDisplay this);
void GraphicDisplay_GPIO(GraphicDisplay this, GraphicDisplayIO io, const IOPin_t gpio);
void GraphicDisplay_Power(GraphicDisplay this, UI08_t p);

#endif
