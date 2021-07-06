#include <unistd.h>
#include "syscall.h"

#ifndef PS4 //only in libkernel_sys.sprx
int setpgid(pid_t pid, pid_t pgid)
{
	return syscall(SYS_setpgid, pid, pgid);
}
#endif
