#include <time.h>
#include "syscall.h"

int nanosleep(const struct timespec *req, struct timespec *rem)
{
#ifndef PS4
	return __syscall_ret(-__clock_nanosleep(CLOCK_REALTIME, 0, req, rem));
#else
	int _nanosleep(const struct timespec*, struct timespec*);
	return _nanosleep(req, rem);
#endif
}
