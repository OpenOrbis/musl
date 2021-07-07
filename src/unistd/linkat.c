#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int linkat(int fd1, const char *existing, int fd2, const char *new, int flag)
{
#ifdef PS4
#ifndef PS4_LIBKERNEL_SYS
	errno = ENOSYS;
	return -1;
#else
	int __PS4_NID_BiHHifIvX88(int, const char*, int, const char*, int);
	return __PS4_NID_BiHHifIvX88(fd1, existing, fd2, new, flag);
#endif
#else
	return syscall(SYS_linkat, fd1, existing, fd2, new, flag);
#endif
}
