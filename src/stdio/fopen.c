#include "stdio_impl.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

FILE *fopen(const char *restrict filename, const char *restrict mode)
{
	FILE *f;
	int fd;
	int flags;

	/* Check for valid initial mode character */
	if (!strchr("rwa", *mode)) {
		errno = EINVAL;
		return 0;
	}

	/* Compute the flags to pass to open() */
	flags = __fmodeflags(mode);

	fd = sys_open(filename, flags, 0666);
	if (fd < 0) return 0;
	if (flags & O_CLOEXEC)
	{
		int errno1 = errno;
		fcntl(fd, F_SETFD, FD_CLOEXEC);
		errno = errno1;
	}

	f = __fdopen(fd, mode);
	if (f) return f;

	{
		int errno1 = errno;
		close(fd);
		errno = errno1;
	}
	return 0;
}

weak_alias(fopen, fopen64);
