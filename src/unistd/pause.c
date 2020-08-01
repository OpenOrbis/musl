#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int pause(void)
{
#ifndef PS4
#ifdef SYS_pause
	return syscall_cp(SYS_pause);
#else
	return syscall_cp(SYS_ppoll, 0, 0, 0, 0);
#endif
#else
	errno = ENOSYS;
	return -1;
#endif
}
