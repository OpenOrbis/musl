#include "pthread_impl.h"
#include "lock.h"

int pthread_setschedprio(pthread_t t, int prio)
{
	int r;
	LOCK(t->killlock);
	r = !t->tid ? ESRCH : (sched_setparam(t->tid, &prio) ? errno : 0);
	UNLOCK(t->killlock);
	return r;
}
