#define _GNU_SOURCE
#include <sys/mman.h>
#include "syscall.h"

#ifndef PS4
int mincore (void *addr, size_t len, unsigned char *vec)
{
	return syscall(SYS_mincore, addr, len, vec);
}
#endif
