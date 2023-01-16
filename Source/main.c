#include <stdio.h>

#include "swi.h"
#include "syscall.h"
#include "hal_uart.h"

#include "ARMCM3.h"

void init_semihost()
{
  _open(AngelSWI_CONSOLE_FILENAME, 3, 0);
  _open(AngelSWI_CONSOLE_FILENAME, 3, 0);
  _open(AngelSWI_CONSOLE_FILENAME, 3, 0);
}

int main()
{
#ifdef SEMIHOST
  init_semihost();
  printf("Init Semihosting Done.\n");
#endif

  hal_uart_init();
  hal_uart_printf("Init Uart Done.\n");

  while (1)
    ;

  return 0;
}
