#include <sys/shm.h>
#include <errno.h>
#include "syscall.h"
#include "ipc.h"

#ifdef PS4
void* shmat(int id, const void* addr, int flag)
{
	errno = ENOSYS;
	return -1;
}
#else

#ifndef SYS_ipc
void *shmat(int id, const void *addr, int flag)
{
	return (void *)syscall(SYS_shmat, id, addr, flag);
}
#else
void *shmat(int id, const void *addr, int flag)
{
	unsigned long ret;
	ret = syscall(SYS_ipc, IPCOP_shmat, id, flag, &addr, addr);
	return (ret > -(unsigned long)SHMLBA) ? (void *)ret : (void *)addr;
}
#endif

#endif
