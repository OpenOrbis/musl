#include <sys/sendfile.h>
#include "syscall.h"

#ifndef PS4

ssize_t sendfile(int out_fd, int in_fd, off_t *ofs, size_t count)
{
	return syscall(SYS_sendfile, out_fd, in_fd, ofs, count);
}

weak_alias(sendfile, sendfile64);

#else
#warning "TODO: sendfile"
#endif
