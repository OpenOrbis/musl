#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

int dup2(int old, int new)
{
	int r;
#ifdef PS4
	int _dup2(int, int);
	int errno1 = errno;
	while((r=_dup2(old, new)) < 0 && errno == EBUSY);
	if(r >= 0)
		errno = errno1;
	return r;
#else
#ifdef SYS_dup2
	while ((r=__syscall(SYS_dup2, old, new))==-EBUSY);
#else
	if (old==new) {
		r = __syscall(SYS_fcntl, old, F_GETFD);
		if (r >= 0) return old;
	} else {
		while ((r=__syscall(SYS_dup3, old, new, 0))==-EBUSY);
	}
#endif
#endif
	return __syscall_ret(r);
}
