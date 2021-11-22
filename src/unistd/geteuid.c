#include <unistd.h>
#include "syscall.h"

#ifndef PS4
uid_t geteuid(void)
{
	return __syscall(SYS_geteuid);
}
#endif
