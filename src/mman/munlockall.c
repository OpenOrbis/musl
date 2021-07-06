#include <sys/mman.h>
#include "syscall.h"

#ifndef PS4
int munlockall(void)
{
	return syscall(SYS_munlockall);
}
#endif
