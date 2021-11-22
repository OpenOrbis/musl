#include <sys/swap.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int swapon(const char *path, int flags)
{
#ifndef PS4
	return syscall(SYS_swapon, path, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}
#endif

int swapoff(const char *path)
{
#ifndef PS4
	return syscall(SYS_swapoff, path);
#else
	errno = ENOSYS;
	return -1;
#endif
}
