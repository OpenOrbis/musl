#include <sys/utsname.h>
#include <errno.h>
#include "syscall.h"

int uname(struct utsname *uts)
{
#ifndef PS4
	return syscall(SYS_uname, uts);
#else
	errno = ENOSYS;
	return -1;
#endif
}
