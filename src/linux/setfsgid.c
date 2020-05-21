#include <sys/fsuid.h>
#include "syscall.h"

int setfsgid(gid_t gid)
{
#ifndef PS4
	return syscall(SYS_setfsgid, gid);
#else
	return -1;
#endif
}
