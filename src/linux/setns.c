#define _GNU_SOURCE
#include <sched.h>
#include "syscall.h"

int setns(int fd, int nstype)
{
#ifndef PS4
	return syscall(SYS_setns, fd, nstype);
#else
	return -1;
#endif
}
