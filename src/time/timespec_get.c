#include <time.h>

/* There is no other implemented value than TIME_UTC; all other values
 * are considered erroneous. */
int timespec_get(struct timespec * ts, int base)
{
	if (base != TIME_UTC) return 0;
#ifndef PS4
	int ret = __clock_gettime(CLOCK_REALTIME, ts);
#else
	int ret = clock_gettime(CLOCK_REALTIME, ts);
#endif
	return ret < 0 ? 0 : base;
}
