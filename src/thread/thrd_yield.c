#include <threads.h>
#include <sched.h>
#include "syscall.h"

void thrd_yield()
{
	sched_yield();
}
