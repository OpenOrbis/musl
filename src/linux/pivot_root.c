#include "syscall.h"
#include <errno.h>

int pivot_root(const char *new, const char *old)
{
#ifndef PS4
	return syscall(SYS_pivot_root, new, old);
#else
	errno = ENOSYS;
	return -1;
#endif
}
