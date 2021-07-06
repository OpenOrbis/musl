#include <unistd.h>
#include "syscall.h"

#ifndef PS4
int getgroups(int count, gid_t list[])
{
	return syscall(SYS_getgroups, count, list);
}
#endif
