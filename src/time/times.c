#include <sys/times.h>
#include "syscall.h"

clock_t times(struct tms *tms)
{
#ifndef PS4
	return __syscall(SYS_times, tms);
#else
	return __syscall(SYS_lutimes, tms);
#endif
}
