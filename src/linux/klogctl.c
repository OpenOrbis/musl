#include <sys/klog.h>
#include "syscall.h"

int klogctl (int type, char *buf, int len)
{
#ifndef PS4
	return syscall(SYS_syslog, type, buf, len);
#else
	return -1;
#endif
}
