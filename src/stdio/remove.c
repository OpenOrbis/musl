#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

int remove(const char *path)
{
	int r = unlink(path);
	if(r < 0 && errno == EISDIR)
		r = rmdir(path);
	return r;
}
