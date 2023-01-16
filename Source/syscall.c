#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "syscall.h"
#include "swi.h"

#ifdef SEMIHOST
int semihost_syscall(int op, ...)
{
    int ret = -1;
    va_list valist;

    va_start(valist, op);

    void *param = va_arg(valist, void *);
    __asm__ __volatile__(
        "mov r0, %[op]\n"
        "mov r1, %[param]\n"
#ifdef __thumb2__
        "bkpt %[angelswi]\n"
#else
        "swi %[angelswi]\n"
#endif
        "mov %[ret], r0\n"
        : [ret] "=r"(ret)
        : [op] "r"(op), [param] "r"(param), [angelswi] "I"(AngelSWI)
        : "r0", "r1");

    va_end(valist);

    return ret;
}
#endif

/* returns number of bytes written or -1 on error */
int _write(int file, char *ptr, int len)
{
    int ret = -1;
#ifdef SEMIHOST
    if (file == 1 || file == 2)
    {
        /* Semihosting */
        ret = semihost_syscall(AngelSWI_Reason_Write, (int[]){fds[1], (int)ptr, len});
    }
#endif
    return ret;
}

/* return number of bytes read or -1 on error */
int _read(int file, char *ptr, int len)
{
    int ret = -1;
#ifdef SEMIHOST
    if (file == 0)
    {
        /* Semihosting */
        ret = semihost_syscall(AngelSWI_Reason_Read, (int[]){fds[0], (int)ptr, len});
    }
#endif
    return ret;
}

/* return file handle on success or -1 on error */
int _open(char *file, int flags, int mode)
{
    int ret = -1;
#ifdef SEMIHOST
    if (!strcmp(file, AngelSWI_CONSOLE_FILENAME))
    {
        /* Semihosting */
        ret = semihost_syscall(AngelSWI_Reason_Open, (int[]){(int)file, flags, mode});
        fds[ret] = ret;
    }
#endif

    return ret;
}