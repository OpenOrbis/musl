#include <unistd.h>
#include "syscall.h"

#ifndef PS4
gid_t getgid(void)
{
	return __syscall(SYS_getgid);
}
#endif
