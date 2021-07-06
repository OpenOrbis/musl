#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4
int fdatasync(int fd)
{
#ifndef PS4
	return syscall_cp(SYS_fdatasync, fd);
#else
	errno = ENOSYS;
	return -1;
#endif
}
#endif
