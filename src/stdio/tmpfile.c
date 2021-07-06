#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "stdio_impl.h"

#define MAXTRIES 100

FILE *tmpfile(void)
{
	char s[] = "/tmp/tmpfile_XXXXXX";
	int fd;
	FILE *f;
	int try;
	for (try=0; try<MAXTRIES; try++) {
		__randname(s+13);
		fd = sys_open(s, O_RDWR|O_CREAT|O_EXCL, 0600);
		if (fd >= 0) {
#ifdef PS4
			{
				int errno1 = errno;
				unlink(s);
				errno = errno1;
			}
#else
#ifdef SYS_unlink
			__syscall(SYS_unlink, s);
#else
			__syscall(SYS_unlinkat, AT_FDCWD, s, 0);
#endif
#endif
			f = __fdopen(fd, "w+");
			if (!f)
			{
				int errno1 = errno;
				close(fd);
				errno = errno1;
			}
			return f;
		}
	}
	return 0;
}

weak_alias(tmpfile, tmpfile64);
