#include <unistd.h>
#include "syscall.h"

#ifndef PS4
uid_t getuid(void)
{
	return __syscall(SYS_getuid);
}
#endif
