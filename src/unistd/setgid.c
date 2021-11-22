#include <unistd.h>
#include <errno.h>
#include "syscall.h"
#include "libc.h"

int setgid(gid_t gid)
{
#ifndef PS4
	return __setxid(SYS_setgid, gid, 0, 0);
#else
	errno = ENOSYS;
	return -1;
#endif
}
