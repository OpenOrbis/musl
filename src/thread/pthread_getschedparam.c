#include "pthread_impl.h"
#include "lock.h"

int pthread_getschedparam(pthread_t t, int *restrict policy, struct sched_param *restrict param)
{
	int r;
	LOCK(t->killlock);
	if (!t->tid) {
		r = ESRCH;
	} else {
		r = (sched_getparam(t->tid, param) ? errno : 0);
		if (!r) {
			*policy = sched_getscheduler(t->tid);
		}
	}
	UNLOCK(t->killlock);
	return r;
}
