#include <sys/fsuid.h>
#include <errno.h>
#include "syscall.h"

int setfsuid(uid_t uid)
{
#ifndef PS4
	return syscall(SYS_setfsuid, uid);
#else
	errno = ENOSYS;
	return -1;
#endif
}
