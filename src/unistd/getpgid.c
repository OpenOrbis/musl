#include <unistd.h>
#include <errno.h>
#include "syscall.h"

pid_t getpgid(pid_t pid)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_getpgid, pid);
#endif
}
