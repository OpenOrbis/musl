#include <unistd.h>
#include "syscall.h"

#ifndef PS4

ssize_t pwrite(int fd, const void *buf, size_t size, off_t ofs)
{
	return syscall_cp(SYS_pwrite, fd, buf, size, __SYSCALL_LL_PRW(ofs));
}

weak_alias(pwrite, pwrite64);

#else

ssize_t pwrite(int fd, const void *buf, size_t size, off_t ofs);

ssize_t pwrite64(int fd, const void *buf, size_t size, off_t ofs)
{
	return pwrite(fd, buf, size, ofs);
}

#endif
