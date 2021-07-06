#include <sys/times.h>
#include <errno.h>
#include "syscall.h"

clock_t times(struct tms *tms)
{
#ifdef PS4
	errno = ENOSYS; //times->lutimes does not make any sense
	return -1;
#else
	return __syscall(SYS_times, tms);
#endif
}
