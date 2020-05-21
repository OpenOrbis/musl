#include <signal.h>
#include <stdint.h>
#include "syscall.h"
#include "pthread_impl.h"

int raise(int sig)
{
	sigset_t set;
	__block_app_sigs(&set);
#ifndef PS4
	int ret = syscall(SYS_tkill, __pthread_self()->tid, sig);
#else
	int ret = syscall(SYS_thr_kill, __pthread_self()->tid, sig);
#endif
	__restore_sigs(&set);
	return ret;
}
