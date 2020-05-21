#include <sys/utsname.h>
#include "syscall.h"

int uname(struct utsname *uts)
{
#ifndef PS4
	return syscall(SYS_uname, uts);
#else
	return -1;
#endif
}
