#include <time.h>
#include <limits.h>
#include "pthread_impl.h"

int timer_delete(timer_t t)
{
	if ((intptr_t)t < 0) {
		pthread_t td = (void *)((uintptr_t)t << 1);
		a_store(&td->timer_id, td->timer_id | INT_MIN);
#ifndef PS4
		__syscall(SYS_tkill, td->tid, SIGTIMER);
#else
		__syscall(SYS_thr_kill, td->tid, SIGTIMER);
#endif
		return 0;
	}
#ifndef PS4
	return __syscall(SYS_timer_delete, t);
#else
	return __syscall(SYS_ktimer_delete, t);
#endif
}
