#include <stdio.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int renameat(int oldfd, const char *old, int newfd, const char *new)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
#ifdef SYS_renameat
	return syscall(SYS_renameat, oldfd, old, newfd, new);
#else
	return syscall(SYS_renameat2, oldfd, old, newfd, new, 0);
#endif
#endif
}
#endif
