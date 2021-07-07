#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"
#include "libc.h"

int setresuid(uid_t ruid, uid_t euid, uid_t suid)
{
#ifndef PS4
	return __setxid(SYS_setresuid, ruid, euid, suid);
#else
	errno = ENOSYS;
	return -1;
#endif
}
