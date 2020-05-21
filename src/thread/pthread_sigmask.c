#include <signal.h>
#include <errno.h>
#include "syscall.h"

int pthread_sigmask(int how, const sigset_t *restrict set, sigset_t *restrict old)
{
	int ret;
	if (set && (unsigned)how - SIG_BLOCK > 2U) return EINVAL;
#ifndef PS4
	ret = -__syscall(SYS_rt_sigprocmask, how, set, old, _NSIG/8);
#else
	ret = -__syscall(SYS_sigprocmask, how, set, old, _NSIG/8);
#endif
	if (!ret && old) {
		if (sizeof old->__bits[0] == 8) {
			old->__bits[0] &= ~0x380000000ULL;
		} else {
			old->__bits[0] &= ~0x80000000UL;
			old->__bits[1] &= ~0x3UL;
		}
	}
	return ret;
}
