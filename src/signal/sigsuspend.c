#include <signal.h>
#include "syscall.h"

#ifndef PS4
int sigsuspend(const sigset_t *mask)
{
	return syscall_cp(SYS_rt_sigsuspend, mask, _NSIG/8);
}
#endif
