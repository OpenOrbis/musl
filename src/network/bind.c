#include <sys/socket.h>
#include "syscall.h"

#ifndef PS4
int bind(int fd, const struct sockaddr *addr, socklen_t len)
{
	return socketcall(bind, fd, addr, len, 0, 0, 0);
}
#endif
