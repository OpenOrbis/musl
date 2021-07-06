#define _GNU_SOURCE
#include <unistd.h>
#include <signal.h>
#include "syscall.h"

pid_t vfork(void)
{
	/* vfork syscall cannot be made from C code */
	return fork();
}
