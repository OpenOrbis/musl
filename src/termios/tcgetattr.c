#include <termios.h>
#include <sys/ioctl.h>

int tcgetattr(int fd, struct termios *tio)
{
#ifndef PS4
	if (ioctl(fd, TCGETS, tio))
#else
	if (ioctl(fd, LINUX_TCGETS, tio))
#endif
		return -1;
	return 0;
}
