#include <stdio.h>
#include <string.h>

#include "ARMCM3.h"
#include "hal_uart.h"
#include "uart.h"

void hal_uart_init(void)
{
    uint32_t baud_rate = 115200;

    /* UART disable */
    ((UARTCTL_TYPE *)&UART0->UARTCTL)->b.UARTEN = (0x0UL);

    /* Write integer portion of the BRD */
    UART0->UARTIBRD = (uint32_t)(20000000 / (16 * baud_rate));

    /* Write fractional portion of the BRD */
    UART0->UARTFBRD = (uint32_t)(((double)20000000 / (double)(16 * baud_rate) - 20000000 / (16 * baud_rate)) * 64 + 0.5);

    /* Write serial parameters to the UARTLCRH */
    /* 8 bit word lenght, no parity bits, one stop bit, FIFOs disabled */
    UART0->UARTLCRH = 0x00000060;

    /* UART enable */
    ((UARTCTL_TYPE *)&UART0->UARTCTL)->b.UARTEN = (0x1UL);

    /* Interrupt enable */
    hal_uart_enable_it();
}

void UART0_Handler(void)
{
    uint32_t mis = ((UARTMIS_TYPE *)&UART0->UARTMIS)->w;

    if (((UARTMIS_TYPE)mis).b.RXMIS)
    {
        /* Simply echo */
        hal_uart_putchar(hal_uart_getchar());
    }
}

void hal_uart_enable_it(void)
{
    /* Promotes the RXIM interrupt */
    ((UARTIM_TYPE *)&UART0->UARTIM)->b.RXIM = 1;

    /* Enable interrupt */
    NVIC_EnableIRQ(UART0_IRQn);
}

void hal_uart_putchar(uint8_t c)
{
    while (UART0->UARTFR & UART_UARTFR_TXFF_Msk)
        ;
    ((UARTDR_TYPE *)&UART0->UARTDR)->b.DATA = c;
}

uint8_t hal_uart_getchar(void)
{
    while (UART0->UARTFR & UART_UARTFR_RXFE_Msk)
        ;

    return (uint8_t)((UARTDR_TYPE *)&UART0->UARTDR)->b.DATA;
}

void hal_uart_printf(const char *msg)
{
    uint32_t i;
    uint32_t msglen = strlen(msg);

    for (i = 0; i < msglen; i++)
    {
        hal_uart_putchar(msg[i]);
    }
}