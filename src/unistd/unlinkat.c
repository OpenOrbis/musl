#include <unistd.h>
#include "syscall.h"

#ifndef PS4 //only in libkernel_sys.sprx
int unlinkat(int fd, const char *path, int flag)
{
	return syscall(SYS_unlinkat, fd, path, flag);
}
#endif
