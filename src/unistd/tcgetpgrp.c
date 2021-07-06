#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

#ifndef PS4
pid_t tcgetpgrp(int fd)
{
	int pgrp;
#ifndef PS4
	if (ioctl(fd, TIOCGPGRP, &pgrp) < 0)
#else
	if (ioctl(fd, LINUX_TIOCGPGRP, &pgrp) < 0)
#endif
		return -1;
	return pgrp;
}
#endif
