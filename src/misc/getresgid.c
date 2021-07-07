#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_getresgid, rgid, egid, sgid);
#endif
}
