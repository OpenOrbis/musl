#include <unistd.h>
#include "syscall.h"

#ifndef PS4
ssize_t write(int fd, const void *buf, size_t count)
{
	return syscall_cp(SYS_write, fd, buf, count);
}
#endif
