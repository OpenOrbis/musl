#include <mqueue.h>
#include "syscall.h"

int mq_setattr(mqd_t mqd, const struct mq_attr *restrict new, struct mq_attr *restrict old)
{
#ifdef PS4 //only in libkernel_sys.sprx
	int kmq_setattr(mqd_t, const struct mq_attr* restrict, struct mq_attr* restrict);
	return kmq_setattr(mqd, new, old);
#else
	return syscall(SYS_mq_getsetattr, mqd, new, old);
#endif
}
