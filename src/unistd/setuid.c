#include <unistd.h>
#include "syscall.h"
#include "libc.h"

#ifndef PS4
int setuid(uid_t uid)
{
	return __setxid(SYS_setuid, uid, 0, 0);
}
#endif
