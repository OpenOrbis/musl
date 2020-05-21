#include <sys/fsuid.h>
#include "syscall.h"

int setfsuid(uid_t uid)
{
#ifndef PS4
	return syscall(SYS_setfsuid, uid);
#else
	return -1;
#endif
}
