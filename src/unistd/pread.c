#include <unistd.h>
#include "syscall.h"

#ifndef PS4

ssize_t pread(int fd, void *buf, size_t size, off_t ofs)
{
	return syscall_cp(SYS_pread, fd, buf, size, __SYSCALL_LL_PRW(ofs));
}

weak_alias(pread, pread64);

#else

ssize_t pread(int fd, void *buf, size_t size, off_t ofs);

ssize_t pread64(int fd, void *buf, size_t size, off_t ofs)
{
	return pread(fd, buf, size, ofs);
}

#endif
