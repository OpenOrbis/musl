#include <sys/random.h>
#include <errno.h>
#include "syscall.h"

ssize_t getrandom(void *buf, size_t buflen, unsigned flags)
{
#ifndef PS4
	return syscall_cp(SYS_getrandom, buf, buflen, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}
