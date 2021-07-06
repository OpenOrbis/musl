#include <unistd.h>
#include "syscall.h"

#ifndef PS4
pid_t getpid(void)
{
	return __syscall(SYS_getpid);
}
#endif
