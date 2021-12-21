#include <time.h>
#include "syscall.h"

time_t time(time_t *t)
{
	struct timespec ts;
#ifndef PS4
	__clock_gettime(CLOCK_REALTIME, &ts);
#else
	clock_gettime(CLOCK_REALTIME, &ts);
#endif
	if (t) *t = ts.tv_sec;
	return ts.tv_sec;
}
