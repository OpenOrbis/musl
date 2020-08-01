#include <sys/sysinfo.h>
#include <errno.h>
#include "syscall.h"

int __lsysinfo(struct sysinfo *info)
{
#ifndef PS4
	return syscall(SYS_sysinfo, info);
#else
	errno = ENOSYS;
	return -1;
#endif
}

weak_alias(__lsysinfo, sysinfo);
