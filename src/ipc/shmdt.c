#include <sys/shm.h>
#include <errno.h>
#include "syscall.h"
#include "ipc.h"

int shmdt(const void *addr)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else

#ifndef SYS_ipc
	return syscall(SYS_shmdt, addr);
#else
	return syscall(SYS_ipc, IPCOP_shmdt, 0, 0, 0, addr);
#endif

#endif
}
