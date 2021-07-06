#include <sys/mman.h>
#include "syscall.h"

#ifndef PS4
int mlockall(int flags)
{
	return syscall(SYS_mlockall, flags);
}
#endif
