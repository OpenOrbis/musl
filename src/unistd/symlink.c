#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int symlink(const char *existing, const char *new)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
#ifdef SYS_symlink
	return syscall(SYS_symlink, existing, new);
#else
	return syscall(SYS_symlinkat, existing, AT_FDCWD, new);
#endif
#endif
}
#endif
