#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int setpgid(pid_t pid, pid_t pgid)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_setpgid, pid, pgid);
#endif
}
#endif
