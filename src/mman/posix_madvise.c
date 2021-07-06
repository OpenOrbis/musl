#define _GNU_SOURCE
#include <sys/mman.h>
#include <errno.h>
#include "syscall.h"

int posix_madvise(void *addr, size_t len, int advice)
{
	if (advice == MADV_DONTNEED) return 0;
	int rv = madvise(addr, len, advice);
	return rv ? errno : rv;
}
