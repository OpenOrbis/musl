#define _GNU_SOURCE
#include <sched.h>
#include <string.h>
#include "pthread_impl.h"
#include "syscall.h"

int sched_setaffinity(pid_t tid, size_t size, const cpu_set_t *set)
{
#ifndef PS4
	return syscall(SYS_sched_setaffinity, tid, size, set);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int pthread_setaffinity_np(pthread_t td, size_t size, const cpu_set_t *set)
{
#ifndef PS4
	return -__syscall(SYS_sched_setaffinity, td->tid, size, set);
#else
	errno = ENOSYS;
	return -1;
#endif
}

static int do_getaffinity(pid_t tid, size_t size, cpu_set_t *set)
{
#ifndef PS4
	long ret = __syscall(SYS_sched_getaffinity, tid, size, set);
	if (ret < 0) return ret;
	if (ret < size) memset((char *)set+ret, 0, size-ret);
	return 0;
#else
	errno = ENOSYS;
	return -1;
#endif
}

int sched_getaffinity(pid_t tid, size_t size, cpu_set_t *set)
{
#ifndef PS4
	return __syscall_ret(do_getaffinity(tid, size, set));
#else
	errno = ENOSYS;
	return -1;
#endif
}

int pthread_getaffinity_np(pthread_t td, size_t size, cpu_set_t *set)
{
#ifndef PS4
	return -do_getaffinity(td->tid, size, set);
#else
	errno = ENOSYS;
	return -1;
#endif
}
