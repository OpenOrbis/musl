#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int link(const char *existing, const char *new)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
#ifdef SYS_link
	return syscall(SYS_link, existing, new);
#else
	return syscall(SYS_linkat, AT_FDCWD, existing, AT_FDCWD, new, 0);
#endif
#endif
}
#endif
