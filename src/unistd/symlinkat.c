#include <unistd.h>
#include "syscall.h"

#ifndef PS4 //only in libkernel_sys.sprx
int symlinkat(const char *existing, int fd, const char *new)
{
	return syscall(SYS_symlinkat, existing, fd, new);
}
#endif
