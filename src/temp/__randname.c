#include <time.h>
#include <stdint.h>

/* This assumes that a check for the
   template size has already been made */
char *__randname(char *template)
{
	int i;
	struct timespec ts;
	unsigned long r;

#ifndef PS4
	__clock_gettime(CLOCK_REALTIME, &ts);
#else
	clock_gettime(CLOCK_REALTIME, &ts);
#endif
	r = ts.tv_nsec*65537 ^ (uintptr_t)&ts / 16 + (uintptr_t)template;
	for (i=0; i<6; i++, r>>=5)
		template[i] = 'A'+(r&15)+(r&16)*2;

	return template;
}
