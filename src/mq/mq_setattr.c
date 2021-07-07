#include <mqueue.h>
#include <errno.h>
#include "syscall.h"

int mq_setattr(mqd_t mqd, const struct mq_attr *restrict new, struct mq_attr *restrict old)
{
#ifdef PS4
#ifndef PS4_LIBKERNEL_SYS
	errno = ENOSYS;
	return -1;
#else
	int kmq_setattr(mqd_t, const struct mq_attr* restrict, struct mq_attr* restrict);
	return kmq_setattr(mqd, new, old);
#endif
#else
	return syscall(SYS_mq_getsetattr, mqd, new, old);
#endif
}
