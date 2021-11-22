#include <unistd.h>
#include <stdlib.h>

#ifndef PS4
_Noreturn void _exit(int status)
{
	_Exit(status);
}
#endif
