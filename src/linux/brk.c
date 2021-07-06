#define _BSD_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

int brk(void *end)
{
	errno = ENOMEM;
	return -1;
}
