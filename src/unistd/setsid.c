#include <unistd.h>
#include "syscall.h"

#ifndef PS4 //only in libkernel_sys.sprx
pid_t setsid(void)
{
	return syscall(SYS_setsid);
}
#endif
