#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

int mknod(const char *path, mode_t mode, dev_t dev)
{
#ifndef PS4 //defined in libkernel_sys.sprx, but never called (*) and not exported
#ifdef SYS_mknod
	return syscall(SYS_mknod, path, mode, dev);
#else
	return syscall(SYS_mknodat, AT_FDCWD, path, mode, dev);
#endif
#else
	errno = ENOSYS;
	return -1;
#endif
}
