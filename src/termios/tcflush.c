#include <termios.h>
#include <sys/ioctl.h>

int tcflush(int fd, int queue)
{
#ifndef PS4
	return ioctl(fd, TCFLSH, queue);
#else
	return ioctl(fd, LINUX_TCFLSH, queue);
#endif
}
