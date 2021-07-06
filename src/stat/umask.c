#include <sys/stat.h>
#include "syscall.h"

#ifndef PS4 //only defined in libkernel_sys.sprx
mode_t umask(mode_t mode)
{
	return syscall(SYS_umask, mode);
}
#endif
