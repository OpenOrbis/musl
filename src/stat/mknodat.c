#include <sys/stat.h>
#include <errno.h>
#include "syscall.h"

int mknodat(int fd, const char *path, mode_t mode, dev_t dev)
{
#ifndef PS4 //defined in libkernel_sys, but never called (maybe indirect call?) and not exported
	return syscall(SYS_mknodat, fd, path, mode, dev);
#else
	errno = ENOSYS;
	return -1;
#endif
}
