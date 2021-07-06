#include <unistd.h>
#include "syscall.h"

#ifndef PS4
int fsync(int fd)
{
	return syscall_cp(SYS_fsync, fd);
}
#endif
