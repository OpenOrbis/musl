#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"
#include "libc.h"

int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return __setxid(SYS_setresgid, rgid, egid, sgid);
#endif
}
