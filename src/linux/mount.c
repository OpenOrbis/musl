#include <sys/mount.h>
#include <errno.h>
#include "syscall.h"

int mount(const char *special, const char *dir, const char *fstype, unsigned long flags, const void *data)
{
#ifndef PS4
	return syscall(SYS_mount, special, dir, fstype, flags, data);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int umount(const char *special)
{
#ifndef PS4
	return syscall(SYS_umount2, special, 0);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int umount2(const char *special, int flags)
{
#ifndef PS4
	return syscall(SYS_umount2, special, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}
