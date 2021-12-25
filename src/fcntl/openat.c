#include <fcntl.h>
#include <stdarg.h>
#include "syscall.h"

int openat(int fd, const char *filename, int flags, ...)
{
	mode_t mode = 0;

	if ((flags & O_CREAT)
#ifndef PS4
         || (flags & O_TMPFILE) == O_TMPFILE
#endif
        ) {
		va_list ap;
		va_start(ap, flags);
		mode = va_arg(ap, int); //mode_t
		va_end(ap);
	}

#ifdef PS4
	int _openat(int fd, const char* path, int flags, mode_t mode);
	return _openat(fd, filename, flags|O_LARGEFILE, mode);
#else
	return syscall_cp(SYS_openat, fd, filename, flags|O_LARGEFILE, mode);
#endif
}

weak_alias(openat, openat64);
