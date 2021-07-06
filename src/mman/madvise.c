#include <sys/mman.h>
#include "syscall.h"

#ifndef PS4

int __madvise(void *addr, size_t len, int advice)
{
	return syscall(SYS_madvise, addr, len, advice);
}

weak_alias(__madvise, madvise);

#else

int madvise(void*, size_t, int);

int __madvise(void* addr, size_t len, int advice)
{
	return madvise(addr, len, advice);
}

#endif
