#define _GNU_SOURCE
#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include "syscall.h"

int fcntl(int fd, int cmd, ...)
{
#ifdef PS4
	int _fcntl(int fd, int cmd, ...);
#else
	#define _fcntl(...) syscall(SYS_fcntl, __VA_ARGS__)
#endif
	unsigned long arg;
	va_list ap;
	va_start(ap, cmd);
	arg = va_arg(ap, unsigned long);
	va_end(ap);
	if (cmd == F_SETFL) arg |= O_LARGEFILE;
	if (cmd == F_SETLKW) return _fcntl(fd, cmd, (void *)arg);
#ifndef PS4 // linux-specific hack
	if (cmd == F_GETOWN) {
		struct f_owner_ex ex;
		int ret = __syscall(SYS_fcntl, fd, F_GETOWN_EX, &ex);
		if (ret == -EINVAL) return __syscall(SYS_fcntl, fd, cmd, (void *)arg);
		if (ret) return __syscall_ret(ret);
		return ex.type == F_OWNER_PGRP ? -ex.pid : ex.pid;
	}
#endif
	if (cmd == F_DUPFD_CLOEXEC) {
		int ret = _fcntl(fd, F_DUPFD_CLOEXEC, arg);
		if (ret != -1 || errno != EINVAL) {
			if (ret >= 0)
			{
				int errno1 = errno;
				_fcntl(ret, F_SETFD, FD_CLOEXEC);
				errno = errno1;
			}
			return ret;
		}
		ret = _fcntl(fd, F_DUPFD_CLOEXEC, 0);
		if (ret != -1 || errno != EINVAL) {
			if (ret >= 0) close(ret);
			errno = -EINVAL;
			return -1;
		}
		ret = _fcntl(fd, F_DUPFD, arg);
		if (ret >= 0)
		{
			int errno1 = errno;
			_fcntl(ret, F_SETFD, FD_CLOEXEC);
			errno = errno1;
		}
		return ret;
	}
	switch (cmd) {
	case F_SETLK:
	case F_GETLK:
#ifndef PS4
	case F_GETOWN_EX:
	case F_SETOWN_EX:
#endif
		return _fcntl(fd, cmd, (void *)arg);
	default:
		return _fcntl(fd, cmd, arg);
	}
}
