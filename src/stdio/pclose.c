#define _GNU_SOURCE
#include "stdio_impl.h"
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int pclose(FILE *f)
{
	int status, r;
	pid_t pid = f->pipe_pid;
	fclose(f);
	int errno1 = errno;
	while ((r=wait4(pid, &status, 0, 0)) == -1 && errno == EINTR);
	if (r<0) return r;
	else errno = errno1;
	return status;
}
