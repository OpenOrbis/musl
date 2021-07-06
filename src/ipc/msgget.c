#include <sys/msg.h>
#include <errno.h>
#include "syscall.h"
#include "ipc.h"

int msgget(key_t k, int flag)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else

#ifndef SYS_ipc
	return syscall(SYS_msgget, k, flag);
#else
	return syscall(SYS_ipc, IPCOP_msgget, k, flag);
#endif

#endif
}
