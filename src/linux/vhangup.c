#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int vhangup(void)
{
#ifndef PS4
	return syscall(SYS_vhangup);
#else
	errno = ENOSYS;
	return -1;
#endif
}
