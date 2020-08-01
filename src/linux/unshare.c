#define _GNU_SOURCE
#include <sched.h>
#include <errno.h>
#include "syscall.h"

int unshare(int flags)
{
#ifndef PS4
	return syscall(SYS_unshare, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}
