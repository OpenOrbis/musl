#include <unistd.h>
#include "syscall.h"

#ifndef PS4
int dup(int fd)
{
	return syscall(SYS_dup, fd);
}
#endif
