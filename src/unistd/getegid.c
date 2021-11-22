#include <unistd.h>
#include "syscall.h"

#ifndef PS4
gid_t getegid(void)
{
	return __syscall(SYS_getegid);
}
#endif
