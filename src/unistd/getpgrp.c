#include <unistd.h>
#include <errno.h>
#include "syscall.h"

pid_t getpgrp(void)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return __syscall(SYS_getpgid, 0);
#endif
}
