#include <sys/sysinfo.h>
#include "syscall.h"

int __lsysinfo(struct sysinfo *info)
{
#ifndef PS4
	return syscall(SYS_sysinfo, info);
#else
	return -1;
#endif
}

weak_alias(__lsysinfo, sysinfo);
