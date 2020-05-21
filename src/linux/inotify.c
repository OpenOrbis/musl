#include <sys/inotify.h>
#include <errno.h>
#include "syscall.h"

int inotify_init()
{
	return inotify_init1(0);
}
int inotify_init1(int flags)
{
#ifndef PS4
	int r = __syscall(SYS_inotify_init1, flags);
#ifdef SYS_inotify_init
	if (r==-ENOSYS && !flags) r = __syscall(SYS_inotify_init);
#endif
	return __syscall_ret(r);
#else
	return -1;
#endif
}

int inotify_add_watch(int fd, const char *pathname, uint32_t mask)
{
#ifndef PS4
	return syscall(SYS_inotify_add_watch, fd, pathname, mask);
#else
	return -1;
#endif
}

int inotify_rm_watch(int fd, int wd)
{
#ifndef PS4
	return syscall(SYS_inotify_rm_watch, fd, wd);
#else
	return -1;
#endif
}
