#include <stdlib.h>
#include "syscall.h"

_Noreturn void _Exit(int ec)
{
#ifdef PS4
	void _exit(int);
	for (;;) _exit(ec);
#else
	__syscall(SYS_exit_group, ec);
	for (;;) __syscall(SYS_exit, ec);
#endif
}
