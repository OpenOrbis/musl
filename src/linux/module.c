#include "syscall.h"
#include <errno.h>

int init_module(void *a, unsigned long b, const char *c)
{
#ifndef PS4
	return syscall(SYS_init_module, a, b, c);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int delete_module(const char *a, unsigned b)
{
#ifndef PS4
	return syscall(SYS_delete_module, a, b);
#else
	errno = ENOSYS;
	return -1;
#endif
}
