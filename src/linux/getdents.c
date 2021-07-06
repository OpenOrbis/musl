#define _BSD_SOURCE
#include <dirent.h>
#include <limits.h>
#include "syscall.h"

#ifndef PS4

int getdents(int fd, struct dirent *buf, size_t len)
{
	if (len>INT_MAX) len = INT_MAX;
	return syscall(SYS_getdents, fd, buf, len);
}

weak_alias(getdents, getdents64);

#else

int getdents(int fd, struct dirent* buf, size_t len);

int getdents64(int fd, struct dirent* buf, size_t len)
{
	return getdents(fd, buf, len);
}

#endif
