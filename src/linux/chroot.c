#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int chroot(const char *path)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_chroot, path);
#endif
}
#endif
