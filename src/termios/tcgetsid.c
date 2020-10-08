#include <termios.h>
#include <sys/ioctl.h>

pid_t tcgetsid(int fd)
{
	int sid;
#ifndef PS4
	if (ioctl(fd, TIOCGSID, &sid) < 0)
#else
	if (ioctl(fd, LINUX_TIOCGSID, &sid) < 0)
#endif
		return -1;
	return sid;
}
