#define _BSD_SOURCE
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

#ifndef PS4
int fstat(int fd, struct stat *st)
{
	if (fd<0) return __syscall_ret(-EBADF);
	return fstatat(fd, "", st, AT_EMPTY_PATH);
}
#else
int fstat(int fd, struct stat* st)
{
	int _fstat(int, struct stat*);
	return _fstat(fd, st);
}
#endif

#if !_REDIR_TIME64
weak_alias(fstat, fstat64);
#endif
