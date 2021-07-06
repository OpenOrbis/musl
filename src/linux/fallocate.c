#define _GNU_SOURCE
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

int fallocate(int fd, int mode, off_t base, off_t len)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_fallocate, fd, mode, __SYSCALL_LL_E(base),
		__SYSCALL_LL_E(len));
#endif
}

#undef fallocate64
weak_alias(fallocate, fallocate64);
