#include <unistd.h>
#include "syscall.h"
#include "libc.h"

#ifndef PS4
int setreuid(uid_t ruid, uid_t euid)
{
	return __setxid(SYS_setreuid, ruid, euid, 0);
}
#endif
