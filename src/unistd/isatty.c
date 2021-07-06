#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include "syscall.h"

int isatty(int fd)
{
	struct winsize wsz;
#ifndef PS4
	unsigned long r = syscall(SYS_ioctl, fd, TIOCGWINSZ, &wsz);
#else
	unsigned long r = ioctl(fd, LINUX_TIOCGWINSZ, &wsz);
#endif
	if (r == 0) return 1;
	if (errno != EBADF) errno = ENOTTY;
	return 0;
}
