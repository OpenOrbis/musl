#define _GNU_SOURCE
#include <sched.h>
#include "syscall.h"

int unshare(int flags)
{
#ifndef PS4
	return syscall(SYS_unshare, flags);
#else
	return -1;
#endif
}
