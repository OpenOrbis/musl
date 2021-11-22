#include <unistd.h>
#include "syscall.h"

#ifndef PS4

int ftruncate(int fd, off_t length)
{
	return syscall(SYS_ftruncate, fd, __SYSCALL_LL_O(length));
}

weak_alias(ftruncate, ftruncate64);

#else

int ftruncate(int fd, off_t length);

int ftruncate64(int fd, off_t length)
{
	return ftruncate(fd, length);
}

#endif
