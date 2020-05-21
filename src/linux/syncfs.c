#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

int syncfs(int fd)
{
#ifndef PS4
	return syscall(SYS_syncfs, fd);
#else
	return -1;
#endif
}
