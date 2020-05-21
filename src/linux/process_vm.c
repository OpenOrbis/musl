#define _GNU_SOURCE
#include <sys/uio.h>
#include "syscall.h"

ssize_t process_vm_writev(pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags)
{
#ifndef PS4
	return syscall(SYS_process_vm_writev, pid, lvec, liovcnt, rvec, riovcnt, flags);
#else
	return -1;
#endif
}

ssize_t process_vm_readv(pid_t pid, const struct iovec *lvec, unsigned long liovcnt, const struct iovec *rvec, unsigned long riovcnt, unsigned long flags)
{
#ifndef PS4
	return syscall(SYS_process_vm_readv, pid, lvec, liovcnt, rvec, riovcnt, flags);
#else
	return -1;
#endif
}
