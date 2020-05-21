#include <setjmp.h>
#include <signal.h>
#include "syscall.h"

hidden int __sigsetjmp_tail(sigjmp_buf jb, int ret)
{
	void *p = jb->__ss;
#ifndef PS4
	__syscall(SYS_rt_sigprocmask, SIG_SETMASK, ret?p:0, ret?0:p, _NSIG/8);
#else
	__syscall(SYS_sigprocmask, SIG_SETMASK, ret?p:0, ret?0:p, _NSIG/8);
#endif
	return ret;
}
