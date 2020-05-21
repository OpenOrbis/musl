#define _GNU_SOURCE
#include <fcntl.h>
#include "syscall.h"

int open_by_handle_at(int mount_fd, struct file_handle *handle, int flags)
{
#ifndef PS4
	return syscall(SYS_open_by_handle_at, mount_fd, handle, flags);
#else
	return -1;
#endif
}
