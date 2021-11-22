#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
#ifdef SYS_readlink
	return syscall(SYS_readlink, path, buf, bufsize);
#else
	return syscall(SYS_readlinkat, AT_FDCWD, path, buf, bufsize);
#endif
#endif
}
#endif
