#include <sys/stat.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int mkdirat(int fd, const char *path, mode_t mode)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_mkdirat, fd, path, mode);
#endif
}
#endif
