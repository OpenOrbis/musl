#include <fcntl.h>
#include <stdarg.h>
#include "syscall.h"

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;

	if ((flags & O_CREAT)
#ifndef PS4
           || (flags & O_TMPFILE) == O_TMPFILE
#endif
        ) {
		va_list ap;
		va_start(ap, flags);
		mode = va_arg(ap, mode_t);
		va_end(ap);
	}

	int fd;
#ifndef PS4
	fd = __syscall_ret(__sys_open_cp(filename, flags, mode));
#else
	{
		int _open(const char*, int, mode_t);
		fd = _open(filename, flags, mode);
	}
#endif
	if (fd>=0 && (flags & O_CLOEXEC))
		fcntl(fd, F_SETFD, FD_CLOEXEC);

	return fd;
}

weak_alias(open, open64);
