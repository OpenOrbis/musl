#include <unistd.h>
#include "syscall.h"
#include "libc.h"

#ifndef PS4
int seteuid(uid_t euid)
{
	return __setxid(SYS_setresuid, -1, euid, -1);
}
#endif
