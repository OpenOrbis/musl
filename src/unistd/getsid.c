#include <unistd.h>
#include "syscall.h"

#ifndef PS4
pid_t getsid(pid_t pid)
{
	return syscall(SYS_getsid, pid);
}
#endif
