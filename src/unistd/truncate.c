#include <unistd.h>
#include "syscall.h"

#ifndef PS4

int truncate(const char *path, off_t length)
{
	return syscall(SYS_truncate, path, __SYSCALL_LL_O(length));
}

weak_alias(truncate, truncate64);

#else

int truncate(const char *path, off_t length);

int truncate64(const char *path, off_t length)
{
	return truncate(path, length);
}

#endif
