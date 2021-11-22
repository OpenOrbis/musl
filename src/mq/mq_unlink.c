#include <mqueue.h>
#include <errno.h>
#include "syscall.h"

int mq_unlink(const char *name)
{
	int ret;
	if (*name == '/') name++;
#ifdef PS4
#ifndef PS4_LIBKERNEL_SYS
	errno = ENOSYS;
	return -1;
#else
	{
		int kmq_unlink(const char*);
		ret = kmq_unlink(name);
	}
#endif
#else
	ret = __syscall_ret(__syscall(SYS_mq_unlink, name));
#endif
	if (ret < 0) {
		if (errno == EPERM) errno = EACCES;
		return -1;
	}
	return ret;
}
