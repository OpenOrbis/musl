#include "syscall.h"

int capset(void *a, void *b)
{
#ifndef PS4
	return syscall(SYS_capset, a, b);
#else
	return -1;
#endif
}

int capget(void *a, void *b)
{
#ifndef PS4
	return syscall(SYS_capget, a, b);
#else
	return -1;
#endif
}
