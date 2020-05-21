#include <fcntl.h>
#include "syscall.h"

int posix_fallocate(int fd, off_t base, off_t len)
{
#ifdef PS4
	return -1;
#else
	return -__syscall(SYS_fallocate, fd, 0, __SYSCALL_LL_E(base),
		__SYSCALL_LL_E(len));
#endif
}

weak_alias(posix_fallocate, posix_fallocate64);
