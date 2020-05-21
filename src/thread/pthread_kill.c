#include "pthread_impl.h"
#include "lock.h"

int pthread_kill(pthread_t t, int sig)
{
	int r;
	LOCK(t->killlock);
#ifndef PS4
	r = t->tid ? -__syscall(SYS_tkill, t->tid, sig)
		: (sig+0U >= _NSIG ? EINVAL : 0);
#else
	r = t->tid ? -__syscall(SYS_thr_kill, t->tid, sig)
		: (sig+0U >= _NSIG ? EINVAL : 0);
#endif
	UNLOCK(t->killlock);
	return r;
}
