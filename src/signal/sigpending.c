#include <signal.h>
#include "syscall.h"

int sigpending(sigset_t *set)
{
#ifndef PS4
	return syscall(SYS_rt_sigpending, set, _NSIG/8);
#else
	return syscall(SYS_sigpending, set, _NSIG/8);
#endif
}
