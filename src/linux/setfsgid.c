#include <sys/fsuid.h>
#include <errno.h>
#include "syscall.h"

int setfsgid(gid_t gid)
{
#ifndef PS4
	return syscall(SYS_setfsgid, gid);
#else
	errno = ENOSYS;
	return -1;
#endif
}
