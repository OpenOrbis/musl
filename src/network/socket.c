#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"

#ifdef PS4

int __sys_socketex(const char* name, int domain, int type, int protocol);
#define _socket(domain, type, protocol) __sys_socketex("", domain, type, protocol)

#else

#define _socket(domain, type, protocol) __syscall_ret(__socketcall(socket, domain, type, protocol, 0, 0, 0))

#endif

int socket(int domain, int type, int protocol)
{
	int s = _socket(domain, type, protocol);
	if (s < 0 && (errno==EINVAL || errno==EPROTONOSUPPORT)
	    && (type&(SOCK_CLOEXEC|SOCK_NONBLOCK))) {
		s = _socket(domain,
			type & ~(SOCK_CLOEXEC|SOCK_NONBLOCK),
			protocol);
		if (s < 0) return s;
		if (type & SOCK_CLOEXEC)
			fcntl(s, F_SETFD, FD_CLOEXEC);
		if (type & SOCK_NONBLOCK)
			fcntl(s, F_SETFL, O_NONBLOCK);
	}
	return s;
}
