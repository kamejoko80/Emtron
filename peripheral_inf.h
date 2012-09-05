#ifndef TRITON_PERIPHERAL_INF
#define TRITON_PERIPHERAL_INF

#include "stddefs.h"
#include "task.h"


typedef enum PeripheralState_e
{
    PS_OPEN,
    PS_BUF_TX_IDLE,
    PS_BUF_RX_IDLE,
    PS_BUF_TX_BUSY,
    PS_BUF_RX_BUSY,
    PS_POLL_TX_IDLE,
    PS_POLL_TX_BUSY,
    PS_POLL_RX_IDLE,
    PS_POLL_RX_BUSY
} PeripheralState_t;

typedef enum PeripheralResult_e
{
    PR_OK,
    PR_BLOCKED,
    PR_NOT_EXIST,
    PR_TIMEOUT,
    PR_ACK,
    PR_NOT_ACK
} PeripheralResult_t;

typedef enum PeripheralModeReg_e
{
    MODE_TX_POLL,
    MODE_TX_BUFFER,
    MODE_TX_RTOS,
    MODE_RX_POLL,
    MODE_RX_BUFFER,
    MODE_RX_RTOS,
    MODE_SPEED,
    MODE_TX_PIN,
    MODE_RX_PIN,
    MODE_CLK_PIN,
    MODE_DATA_PIN,
    MODE_START,
    MODE_STOP
} PeripheralModeReg_t;

typedef struct PeripheralHandle_s
{
    UI08_t Use:1;
    UI08_t Driver:3;
    UI08_t Peripheral:4;

    PeripheralState_t StateTx;
    UI08_t TaskTx;
    Time_t TimeoutTx;

    PeripheralState_t StateRx;
    UI08_t TaskRx;
    Time_t TimeoutRx;

} PeripheralHandle_t;

// Standard function prototypes.
typedef void                (*HandlerInit) (PeripheralHandle_t* handle, void* args);
typedef PeripheralResult_t  (*HandlerMode) (PeripheralHandle_t* handle, PeripheralModeReg_t mode, void* data);
typedef PeripheralResult_t  (*HandlerTRx)  (PeripheralHandle_t* handle, UI08_t* buf, UI16_t length);
typedef PeripheralResult_t  (*HandlerTxRx) (PeripheralHandle_t* handle, UI08_t* tx_buf, UI08_t* rx_buf, UI16_t length);
typedef UI08_t              (*HandlerPin)  (PeripheralHandle_t* handle);

#endif
