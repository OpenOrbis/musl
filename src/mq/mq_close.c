#include <mqueue.h>
#include <unistd.h>
#include "syscall.h"

int mq_close(mqd_t mqd)
{
	return close(mqd);
}
