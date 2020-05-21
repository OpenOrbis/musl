#include <unistd.h>
#include "syscall.h"

int fdatasync(int fd)
{
#ifndef PS4
	return syscall_cp(SYS_fdatasync, fd);
#else
	return -1;
#endif
}
