#include <time.h>
#include <limits.h>
#include "pthread_impl.h"

int timer_getoverrun(timer_t t)
{
	if ((intptr_t)t < 0) {
		pthread_t td = (void *)((uintptr_t)t << 1);
		t = (void *)(uintptr_t)(td->timer_id & INT_MAX);
	}
#ifdef PS4
	int ktimer_getoverrun(timer_t);
	return ktimer_getoverrun(t);
#else
	return syscall(SYS_timer_getoverrun, t);
#endif
}
