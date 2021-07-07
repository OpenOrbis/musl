#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int symlinkat(const char *existing, int fd, const char *new)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_symlinkat, existing, fd, new);
#endif
}
#endif
