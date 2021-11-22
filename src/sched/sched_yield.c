#include <sched.h>
#include "syscall.h"

#ifndef PS4
int sched_yield()
{
	return syscall(SYS_sched_yield);
}
#endif
