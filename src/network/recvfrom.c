#include <sys/socket.h>
#include "syscall.h"

#ifndef PS4
ssize_t recvfrom(int fd, void *restrict buf, size_t len, int flags, struct sockaddr *restrict addr, socklen_t *restrict alen)
{
	return socketcall_cp(recvfrom, fd, buf, len, flags, addr, alen);
}
#endif
