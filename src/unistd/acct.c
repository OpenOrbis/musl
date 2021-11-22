#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int acct(const char *filename)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	return syscall(SYS_acct, filename);
#endif
}
