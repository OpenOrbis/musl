#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

int pipe2(int fd[2], int flag)
{
	int ret;
#ifndef PS4
	if (!flag) return pipe(fd);
	ret = __syscall(SYS_pipe2, fd, flag);
	if (ret != -ENOSYS) return __syscall_ret(ret);
#endif
	ret = pipe(fd);
	if (ret) return ret;
	int errno1 = errno;
	if (flag & O_CLOEXEC) {
		fcntl(fd[0], F_SETFD, FD_CLOEXEC);
		fcntl(fd[1], F_SETFD, FD_CLOEXEC);
	}
	if (flag & O_NONBLOCK) {
		fcntl(fd[0], F_SETFL, O_NONBLOCK);
		fcntl(fd[1], F_SETFL, O_NONBLOCK);
	}
	errno = errno1;
	return 0;
}
