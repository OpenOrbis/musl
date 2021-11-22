#include "pthread_impl.h"
#include "lock.h"
#include <errno.h>

int pthread_setschedparam(pthread_t t, int policy, const struct sched_param *param)
{
	int r;
	LOCK(t->killlock);
	r = !t->tid ? ESRCH : (sched_setscheduler(t->tid, policy, param) ? errno : 0);
	UNLOCK(t->killlock);
	return r;
}
