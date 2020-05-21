#include "syscall.h"

int pivot_root(const char *new, const char *old)
{
#ifndef PS4
	return syscall(SYS_pivot_root, new, old);
#else
	return -1;
#endif
}
