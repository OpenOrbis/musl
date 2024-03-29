#include <unistd.h>
#include <errno.h>
#include "syscall.h"

ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf, size_t bufsize)
{
#ifndef PS4
	return syscall(SYS_readlinkat, fd, path, buf, bufsize);
#else
	errno = ENOSYS;
	return -1;
#endif
}
