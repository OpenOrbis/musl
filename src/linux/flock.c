#include <sys/file.h>
#include "syscall.h"

#ifndef PS4
int flock(int fd, int op)
{
	return syscall(SYS_flock, fd, op);
}
#endif
