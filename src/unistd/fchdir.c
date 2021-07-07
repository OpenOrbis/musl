#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
int fchdir(int fd)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	int ret = __syscall(SYS_fchdir, fd);
	if (ret != -EBADF || __syscall(SYS_fcntl, fd, F_GETFD) < 0)
		return __syscall_ret(ret);

	char buf[15+3*sizeof(int)];
	__procfdname(buf, fd);
	return syscall(SYS_chdir, buf);
#endif
}
#endif
