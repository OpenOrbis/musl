#include <unistd.h>
#include "syscall.h"

#ifndef PS4

off_t __lseek(int fd, off_t offset, int whence)
{
#ifdef SYS__llseek
	off_t result;
	return syscall(SYS__llseek, fd, offset>>32, offset, &result, whence) ? -1 : result;
#else
	return syscall(SYS_lseek, fd, offset, whence);
#endif
}

weak_alias(__lseek, lseek);

#else

off_t lseek(int fd, off_t offset, int whence);

off_t __lseek(int fd, off_t offset, int whence)
{
	return lseek(fd, offset, whence);
}

#endif

weak_alias(__lseek, lseek64);
