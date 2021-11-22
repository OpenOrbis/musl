#include <signal.h>
#include "syscall.h"

#ifndef PS4
int kill(pid_t pid, int sig)
{
	return syscall(SYS_kill, pid, sig);
}
#endif
