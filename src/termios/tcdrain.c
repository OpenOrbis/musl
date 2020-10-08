#include <termios.h>
#include <sys/ioctl.h>
#include "syscall.h"

int tcdrain(int fd)
{
#ifndef PS4
	return syscall_cp(SYS_ioctl, fd, TCSBRK, 1);
#else
	return syscall_cp(SYS_ioctl, fd, LINUX_TCSBRK, 1);
#endif
}
