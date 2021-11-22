#include <sys/quota.h>
#include <errno.h>
#include "syscall.h"

int quotactl(int cmd, const char *special, int id, char *addr)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_quotactl, cmd, special, id, addr);
#endif
}
