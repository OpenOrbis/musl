#include <mqueue.h>
#include "syscall.h"

int mq_setattr(mqd_t mqd, const struct mq_attr *restrict new, struct mq_attr *restrict old)
{
#ifndef PS4
	return syscall(SYS_mq_getsetattr, mqd, new, old);
#else
	return syscall(SYS_kmq_setattr, mqd, new, old);
#endif
}
