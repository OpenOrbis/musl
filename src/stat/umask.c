#include <sys/stat.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
mode_t umask(mode_t mode)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_umask, mode);
#endif
}
#endif
