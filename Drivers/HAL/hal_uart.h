#ifndef HAL_UART_H
#define HAL_UART_H

#include <stdint.h>

void hal_uart_init(void);
void hal_uart_enable_it(void);

void hal_uart_putchar(uint8_t);
uint8_t hal_uart_getchar(void);

void hal_uart_printf(const char *);

/* Interrupt handler */
void UART0_Handler(void);

#endif /* HAL_UART_H */