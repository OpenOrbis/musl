#include <unistd.h>
#include "syscall.h"

#ifndef PS4
void sync(void)
{
	__syscall(SYS_sync);
}
#endif
