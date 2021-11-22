#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

#ifndef PS4
int unlink(const char *path)
{
#ifdef SYS_unlink
	return syscall(SYS_unlink, path);
#else
	return syscall(SYS_unlinkat, AT_FDCWD, path, 0);
#endif
}
#endif
