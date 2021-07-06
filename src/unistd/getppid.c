#include <unistd.h>
#include "syscall.h"

#ifndef PS4
pid_t getppid(void)
{
	return __syscall(SYS_getppid);
}
#endif
