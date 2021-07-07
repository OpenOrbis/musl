#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int unlinkat(int fd, const char *path, int flag)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_unlinkat, fd, path, flag);
#endif
}
#endif
