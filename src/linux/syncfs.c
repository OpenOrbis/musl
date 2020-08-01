#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int syncfs(int fd)
{
#ifndef PS4
	return syscall(SYS_syncfs, fd);
#else
	errno = ENOSYS;
	return -1;
#endif
}
