#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>

int tcsetattr(int fd, int act, const struct termios *tio)
{
	if (act < 0 || act > 2) {
		errno = EINVAL;
		return -1;
	}
#ifndef PS4
	return ioctl(fd, TCSETS+act, tio);
#else
	return ioctl(fd, LINUX_TCSETS+act, tio);
#endif
}
