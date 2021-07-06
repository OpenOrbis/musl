#include <time.h>
#include <limits.h>
#include "pthread_impl.h"

int timer_delete(timer_t t)
{
	if ((intptr_t)t < 0) {
		pthread_t td = (void *)((uintptr_t)t << 1);
		a_store(&td->timer_id, td->timer_id | INT_MIN);
#ifdef PS4
		int thr_kill(long, int);
		thr_kill(td->tid, SIGTIMER);
#else
		__syscall(SYS_tkill, td->tid, SIGTIMER);
#endif
		return 0;
	}
#ifdef PS4
	int ktimer_delete(int);
	return ktimer_delete((intptr_t)t);
#else
	return __syscall(SYS_timer_delete, t);
#endif
}
