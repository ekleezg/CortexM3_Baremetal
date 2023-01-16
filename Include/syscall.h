#ifndef SYSCALL_H
#define SYSCALL_H

#ifdef SEMIHOST
static int fds[3] = {0, 1, 2};
#endif

int semihost_syscall(int op, ...);

int _write(int file, char *buf, int len);
int _read(int file, char *buf, int len);
int _open(char *file, int flags, int mode);

#endif /* SYSCALL_H */