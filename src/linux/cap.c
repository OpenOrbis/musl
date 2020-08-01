#include "syscall.h"
#include <errno.h>

int capset(void *a, void *b)
{
#ifndef PS4
	return syscall(SYS_capset, a, b);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int capget(void *a, void *b)
{
#ifndef PS4
	return syscall(SYS_capget, a, b);
#else
	errno = ENOSYS;
	return -1;
#endif
}
