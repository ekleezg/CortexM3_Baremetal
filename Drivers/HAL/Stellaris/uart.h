#include <stdint.h>

#define __IM volatile const /*! Defines 'read only' structure member permissions */
#define __OM volatile       /*! Defines 'write only' structure member permissions */
#define __IOM volatile      /*! Defines 'read / write' structure member permissions */

typedef struct
{
    __IOM uint32_t UARTDR;  /* offset: 0x000, UART Data */
    __IOM uint32_t UARTRSR; /* offset: 0x004, UART Receive Status/Error Clear */
    uint32_t RESERVED0[4];
    __IM uint32_t UARTFR; /* offset: 0x018, UART Flag */
    uint32_t RESERVED1[2];
    __IOM uint32_t UARTIBRD; /* offset: 0x024, UART Integer Baud-Rate Divisor */
    __IOM uint32_t UARTFBRD; /* offset: 0x028, UART Fractional Baud-Rate Divisor */
    __IOM uint32_t UARTLCRH; /* offset: 0x02c, UART Line Control */
    __IOM uint32_t UARTCTL;  /* offset: 0x030, UART Control */
    __IOM uint32_t UARTIFLS; /* offset: 0x034, UART Interrupt FIFO Level Select */
    __IOM uint32_t UARTIM;   /* offset: 0x038, UART Interrupt Mask */
    __IM uint32_t UARTRIS;   /* offset: 0x03c, UART Raw Interrupt Status */
    __IM uint32_t UARTMIS;   /* offset: 0x040, UART Masked Interrupt Status */
    __OM uint32_t UARTICR;   /* offset: 0x044, UART Interrupt Clear */
    uint32_t RESERVED2[994];
    __IM uint32_t UARTPeriphID4; /* offset: 0xfd0, UART Peripheral Identification 4 */
    __IM uint32_t UARTPeriphID5; /* offset: 0xfd4, UART Peripheral Identification 5 */
    __IM uint32_t UARTPeriphID6; /* offset: 0xfd8, UART Peripheral Identification 6 */
    __IM uint32_t UARTPeriphID7; /* offset: 0xfdc, UART Peripheral Identification 7 */
    __IM uint32_t UARTPeriphID0; /* offset: 0xfe0, UART Peripheral Identification 0 */
    __IM uint32_t UARTPeriphID1; /* offset: 0xfe4, UART Peripheral Identification 1 */
    __IM uint32_t UARTPeriphID2; /* offset: 0xfe8, UART Peripheral Identification 2 */
    __IM uint32_t UARTPeriphID3; /* offset: 0xfec, UART Peripheral Identification 3 */
    __IM uint32_t UARTPCellID0;  /* offset: 0xff0, UART Peripheral Identification 0 */
    __IM uint32_t UARTPCellID1;  /* offset: 0xff4, UART Peripheral Identification 1 */
    __IM uint32_t UARTPCellID2;  /* offset: 0xff8, UART Peripheral Identification 2 */
    __IM uint32_t UARTPCellID3;  /* offset: 0xffc, UART Peripheral Identification 3 */
} UART_TYPE;

typedef union
{
    struct
    {
        uint32_t UARTEN : 1;
        uint32_t RESERVED0 : 6;
        uint32_t LBE : 1;
        uint32_t TXE : 1;
        uint32_t RXE : 1;
        uint32_t RESERVED1 : 22;
    } b;
    uint32_t w;
} UARTCTL_TYPE;

typedef union
{
    struct
    {
        uint32_t DATA;
        uint32_t FE : 1;
        uint32_t PE : 1;
        uint32_t BE : 1;
        uint32_t OE : 1;
        uint32_t RESERVED : 20;
    } b;
    uint32_t w;
} UARTDR_TYPE;

typedef union
{
    struct
    {
        uint32_t RESERVED0 : 4;
        uint32_t RXIM : 1;
        uint32_t TXIM : 1;
        uint32_t RTIM : 1;
        uint32_t FEIM : 1;
        uint32_t PEIM : 1;
        uint32_t BEIM : 1;
        uint32_t OEIM : 1;
        uint32_t RESERVED1 : 21;
    } b;
    uint32_t w;
} UARTIM_TYPE;

typedef union
{
    struct
    {
        uint32_t RESERVED0 : 4;
        uint32_t RXMIS : 1;
        uint32_t TXMIS : 1;
        uint32_t RTMIS : 1;
        uint32_t FEMIS : 1;
        uint32_t PEMIS : 1;
        uint32_t BEMIS : 1;
        uint32_t OEMIS : 1;
        uint32_t RESERVED1 : 21;
    } b;
    uint32_t w;
} UARTMIS_TYPE;

#define UART_UARTCTL_UARTEN_Pos 0U
#define UART_UARTCTL_UARTEN_Msk (0x1UL << UART_UARTCTL_UARTEN_Pos)

#define UART_UARTCTL_LBE_Pos 7U
#define UART_UARTCTL_LBE_Msk (0x1UL << UART_UARTCTL_LBE_Pos)

#define UART_UARTCTL_TXE_Pos 8U
#define UART_UARTCTL_TXE_Msk (0x1UL << UART_UARTCTL_TXE_Pos)

#define UART_UARTCTL_RXE_Pos 9U
#define UART_UARTCTL_RXE_Msk (0x1UL << UART_UARTCTL_RXE_Pos)

#define UART_UARTFR_BUSY_Pos 3U
#define UART_UARTFR_BUSY_Msk (0x1UL << UART_UARTFR_BUSY_Pos)

#define UART_UARTFR_RXFE_Pos 4U
#define UART_UARTFR_RXFE_Msk (0x1UL << UART_UARTFR_RXFE_Pos)

#define UART_UARTFR_TXFF_Pos 5U
#define UART_UARTFR_TXFF_Msk (0x1UL << UART_UARTFR_TXFF_Pos)

#define UART_UARTFR_RXFF_Pos 6U
#define UART_UARTFR_RXFF_Msk (0x1UL << UART_UARTFR_RXFF_Pos)

#define UART_UARTFR_TXFE_Pos 7U
#define UART_UARTFR_TXFE_Msk (0x1UL << UART_UARTFR_TXFE_Pos)

#define UART_UARTDR_DATA_Pos 0U
#define UART_UARTDR_DATA_Msk (0xFUL << UART_UARTDR_DATA_Pos)

#define UART_UARTMIS_RXMIS_Pos 4U
#define UART_UARTMIS_RXMIS_Msk (0xFUL << UART_UARTMIS_RXMIS_Pos)

#define UART_UARTMIS_TXMIS_Pos 5U
#define UART_UARTMIS_TXMIS_Msk (0xFUL << UART_UARTMIS_TXMIS_Pos)

#define UART_UARTMIS_RTMIS_Pos 6U
#define UART_UARTMIS_RTMIS_Msk (0xFUL << UART_UARTMIS_RTMIS_Pos)

#define UART_UARTMIS_FEMIS_Pos 7U
#define UART_UARTMIS_FEMIS_Msk (0xFUL << UART_UARTMIS_FEMIS_Pos)

#define UART_UARTMIS_PEMIS_Pos 8U
#define UART_UARTMIS_PEMIS_Msk (0xFUL << UART_UARTMIS_PEMIS_Pos)

#define UART_UARTMIS_BEMIS_Pos 9U
#define UART_UARTMIS_BEMIS_Msk (0xFUL << UART_UARTMIS_BEMIS_Pos)

#define UART_UARTMIS_OEMIS_Pos 10U
#define UART_UARTMIS_OEMIS_Msk (0xFUL << UART_UARTMIS_OEMIS_Pos)

#define UART0 ((UART_TYPE *)0x4000C000UL)
#define UART1 ((UART_TYPE *)0x4000D000UL)