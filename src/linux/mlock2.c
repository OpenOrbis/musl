#define _GNU_SOURCE 1
#include <sys/mman.h>
#include "syscall.h"

int mlock2(const void *addr, size_t len, unsigned flags)
{
#ifdef PS4
	return mlock(addr, len);
#else
	if (flags == 0)
		return mlock(addr, len);
	return syscall(SYS_mlock2, addr, len, flags);
#endif
}
