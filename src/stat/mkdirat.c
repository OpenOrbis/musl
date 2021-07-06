#include <sys/stat.h>
#include "syscall.h"

#ifndef PS4 //only defined in libkernel_sys.sprx
int mkdirat(int fd, const char *path, mode_t mode)
{
	return syscall(SYS_mkdirat, fd, path, mode);
}
#endif
