#define _GNU_SOURCE
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

ssize_t vmsplice(int fd, const struct iovec *iov, size_t cnt, unsigned flags)
{
#ifndef PS4
	return syscall(SYS_vmsplice, fd, iov, cnt, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}
