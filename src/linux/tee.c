#define _GNU_SOURCE
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

ssize_t tee(int src, int dest, size_t len, unsigned flags)
{
#ifndef PS4
	return syscall(SYS_tee, src, dest, len, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}
