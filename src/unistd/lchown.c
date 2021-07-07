#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int lchown(const char *path, uid_t uid, gid_t gid)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
#ifdef SYS_lchown
	return syscall(SYS_lchown, path, uid, gid);
#else
	return syscall(SYS_fchownat, AT_FDCWD, path, uid, gid, AT_SYMLINK_NOFOLLOW);
#endif
#endif
}
#endif
