#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int chown(const char *path, uid_t uid, gid_t gid)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
#ifdef SYS_chown
	return syscall(SYS_chown, path, uid, gid);
#else
	return syscall(SYS_fchownat, AT_FDCWD, path, uid, gid, 0);
#endif
#endif
}
#endif
