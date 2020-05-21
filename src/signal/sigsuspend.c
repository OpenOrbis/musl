#include <signal.h>
#include "syscall.h"

int sigsuspend(const sigset_t *mask)
{
#ifndef PS4
	return syscall_cp(SYS_rt_sigsuspend, mask, _NSIG/8);
#else
	return syscall_cp(SYS_sigsuspend, mask, _NSIG/8);
#endif
}
