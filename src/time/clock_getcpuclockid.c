#include <time.h>
#include <errno.h>
#include <unistd.h>
#include "syscall.h"

int clock_getcpuclockid(pid_t pid, clockid_t *clk)
{
	struct timespec ts;
	clockid_t id = (-pid-1)*8U + 2;
	int ret = clock_getres(id, &ts);
	if (ret) return errno;
	*clk = id;
	return 0;
}
