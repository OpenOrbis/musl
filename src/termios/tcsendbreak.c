#include <termios.h>
#include <sys/ioctl.h>

int tcsendbreak(int fd, int dur)
{
	/* nonzero duration is implementation-defined, so ignore it */
#ifndef PS4
	return ioctl(fd, TCSBRK, 0);
#else
	return ioctl(fd, LINUX_TCSBRK, 0);
#endif
}
