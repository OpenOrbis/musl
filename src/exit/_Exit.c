#include <stdlib.h>
#include "syscall.h"

_Noreturn void _Exit(int ec)
{
#ifndef PS4
	__syscall(SYS_exit_group, ec);
#endif
	for (;;) __syscall(SYS_exit, ec);
}
