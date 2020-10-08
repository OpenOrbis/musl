#include <termios.h>
#include <sys/ioctl.h>

int tcflow(int fd, int action)
{
#ifndef PS4
	return ioctl(fd, TCXONC, action);
#else
	return ioctl(fd, LINUX_TCXONC, action);
#endif
}
