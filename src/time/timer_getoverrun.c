#include <time.h>
#include <limits.h>
#include "pthread_impl.h"

int timer_getoverrun(timer_t t)
{
	if ((intptr_t)t < 0) {
		pthread_t td = (void *)((uintptr_t)t << 1);
		t = (void *)(uintptr_t)(td->timer_id & INT_MAX);
	}
#ifndef PS4
	return syscall(SYS_timer_getoverrun, t);
#else
	return syscall(SYS_ktimer_getoverrun, t);
#endif
}
