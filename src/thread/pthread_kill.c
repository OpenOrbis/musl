#include "pthread_impl.h"
#include "lock.h"
#include <errno.h>

int pthread_kill(pthread_t t, int sig)
{
#ifdef PS4
	int thr_kill(thread_t, int);
#endif
	int r;
	LOCK(t->killlock);
	r = t->tid ? 
#ifdef PS4
		(thr_kill(t->tid, sig) ? errno : 0)
#else
		-__syscall(SYS_tkill, t->tid, sig)
#endif
		: (sig+0U >= _NSIG ? EINVAL : 0);
	UNLOCK(t->killlock);
	return r;
}
