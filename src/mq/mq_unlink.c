#include <mqueue.h>
#include <errno.h>
#include "syscall.h"

int mq_unlink(const char *name)
{
	int ret;
	if (*name == '/') name++;
#ifdef PS4
	{
		int kmq_unlink(const char*);
		ret = kmq_unlink(name);
	}
#else
	ret = __syscall_ret(__syscall(SYS_mq_unlink, name));
#endif
	if (ret < 0) {
		if (errno == EPERM) errno = EACCES;
		return -1;
	}
	return ret;
}
