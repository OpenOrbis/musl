#include <sys/ptrace.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4_LIBKERNEL_SYS
long ptrace(int req, ...)
{
#ifdef PS4
	errno = ENOSYS;
	return -1;
#else
	va_list ap;
	pid_t pid;
	void *addr, *data, *addr2 = 0;
	long ret, result;

	va_start(ap, req);
	pid = va_arg(ap, pid_t);
	addr = va_arg(ap, void *);
	data = va_arg(ap, void *);
	/* PTRACE_{READ,WRITE}{DATA,TEXT} (16...19) are specific to SPARC. */
#ifdef PTRACE_READDATA
	if ((unsigned)req - PTRACE_READDATA < 4)
		addr2 = va_arg(ap, void *);
#endif
	va_end(ap);

	if (req-1U < 3) data = &result;
	ret = syscall(SYS_ptrace, req, pid, addr, data, addr2);

	if (ret < 0 || req-1U >= 3) return ret;
	return result;
#endif
}
#endif
