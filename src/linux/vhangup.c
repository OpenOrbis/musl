#define _GNU_SOURCE
#include <unistd.h>
#include "syscall.h"

int vhangup(void)
{
#ifndef PS4
	return syscall(SYS_vhangup);
#else
	return -1;
#endif
}
