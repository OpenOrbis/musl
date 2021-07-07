#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS

int fchownat(int fd, const char *path, uid_t uid, gid_t gid, int flag)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_fchownat, fd, path, uid, gid, flag);
#endif
}

#endif
