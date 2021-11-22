#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
pid_t setsid(void)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_setsid);
#endif
}
#endif
