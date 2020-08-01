#define _GNU_SOURCE
#include <sys/resource.h>
#include <errno.h>
#include "syscall.h"

#define FIX(x) do{ if ((x)>=SYSCALL_RLIM_INFINITY) (x)=RLIM_INFINITY; }while(0)

int prlimit(pid_t pid, int resource, const struct rlimit *new_limit, struct rlimit *old_limit)
{
	struct rlimit tmp;
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	int r;
	if (new_limit && SYSCALL_RLIM_INFINITY != RLIM_INFINITY) {
		tmp = *new_limit;
		FIX(tmp.rlim_cur);
		FIX(tmp.rlim_max);
		new_limit = &tmp;
	}
	r = syscall(SYS_prlimit64, pid, resource, new_limit, old_limit);
	if (!r && old_limit && SYSCALL_RLIM_INFINITY != RLIM_INFINITY) {
		FIX(old_limit->rlim_cur);
		FIX(old_limit->rlim_max);
	}
	return r;
#endif
}

#undef prlimit64
weak_alias(prlimit, prlimit64);
