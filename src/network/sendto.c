#include <sys/socket.h>
#include "syscall.h"

#ifndef PS4
ssize_t sendto(int fd, const void *buf, size_t len, int flags, const struct sockaddr *addr, socklen_t alen)
{
	return socketcall_cp(sendto, fd, buf, len, flags, addr, alen);
}
#endif
