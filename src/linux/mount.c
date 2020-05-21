#include <sys/mount.h>
#include "syscall.h"

int mount(const char *special, const char *dir, const char *fstype, unsigned long flags, const void *data)
{
	return syscall(SYS_mount, special, dir, fstype, flags, data);
}

int umount(const char *special)
{
#ifndef PS4
	return syscall(SYS_umount2, special, 0);
#else
	return syscall(SYS_unmount, special, 0);
#endif
}

int umount2(const char *special, int flags)
{
#ifndef PS4
	return syscall(SYS_umount2, special, flags);
#else
	return syscall(SYS_unmount, special, flags);
#endif
}
