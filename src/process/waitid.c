#include <sys/wait.h>
#include <errno.h>
#include "syscall.h"

int waitid(idtype_t type, id_t id, siginfo_t *info, int options)
{
#ifndef PS4
	return syscall_cp(SYS_waitid, type, id, info, options, 0);
#else
	errno = ENOSYS;
	return -1;
#endif
}
