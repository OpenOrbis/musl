#include <unistd.h>
#include "syscall.h"

#ifndef PS4
int chdir(const char *path)
{
	return syscall(SYS_chdir, path);
}
#endif
