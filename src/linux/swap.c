#include <sys/swap.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4 //only in libkernel_sys.sprx
int swapon(const char *path, int flags)
{
	return syscall(SYS_swapon, path, flags);
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
