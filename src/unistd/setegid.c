#include <unistd.h>
#include "libc.h"
#include "syscall.h"

#ifndef PS4
int setegid(gid_t egid)
{
	return __setxid(SYS_setresgid, -1, egid, -1);
}
#endif
