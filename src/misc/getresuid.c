#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_getresuid, ruid, euid, suid);
#endif
}
