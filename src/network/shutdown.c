#include <sys/socket.h>
#include "syscall.h"

#ifndef PS4
int shutdown(int fd, int how)
{
	return socketcall(shutdown, fd, how, 0, 0, 0, 0);
}
#endif
