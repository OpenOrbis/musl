#define _GNU_SOURCE
#include <fcntl.h>
#include "syscall.h"

ssize_t readahead(int fd, off_t pos, size_t len)
{
#ifndef PS4
	return syscall(SYS_readahead, fd, __SYSCALL_LL_O(pos), len);
#else
	return -1;
#endif
}
