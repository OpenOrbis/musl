#include <sys/mman.h>
#include "syscall.h"

static void dummy(void) { }
weak_alias(dummy, __vm_wait);

#ifndef PS4

int __munmap(void *start, size_t len)
{
	__vm_wait();
	return syscall(SYS_munmap, start, len);
}

weak_alias(__munmap, munmap);

#else

int munmap(void* start, size_t len);

int __munmap(void* start, size_t len)
{
	return munmap(start, len);
}

#endif
