#include "syscall.h"
#include <sys/fanotify.h>

int fanotify_init(unsigned flags, unsigned event_f_flags)
{
#ifndef PS4
	return syscall(SYS_fanotify_init, flags, event_f_flags);
#else
	return -1;
#endif
}

int fanotify_mark(int fanotify_fd, unsigned flags, unsigned long long mask,
	          int dfd, const char *pathname)
{
#ifndef PS4
	return syscall(SYS_fanotify_mark, fanotify_fd, flags, __SYSCALL_LL_E(mask), dfd, pathname);
#else
	return -1;
#endif
}

