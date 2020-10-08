#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

int tcsetpgrp(int fd, pid_t pgrp)
{
	int pgrp_int = pgrp;
#ifndef PS4
	return ioctl(fd, TIOCSPGRP, &pgrp_int);
#else
	return ioctl(fd, LINUX_TIOCSPGRP, &pgrp_int);
#endif
}
