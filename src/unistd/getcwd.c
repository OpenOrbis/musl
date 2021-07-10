#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include "syscall.h"

char *getcwd(char *buf, size_t size)
{
	char tmp[buf ? 1 : PATH_MAX];
	if (!buf) {
		buf = tmp;
		size = sizeof tmp;
	} else if (!size) {
		errno = EINVAL;
		return 0;
	}
	long ret;
#ifdef PS4
#ifdef PS4_LIBKERNEL_SYS
	{
		size_t __getcwd(char*, size_t);
		ret = __getcwd(buf, size);
	}
#else
	errno = ENOSYS;
	return 0;
#endif
#else
	ret = syscall(SYS_getcwd, buf, size);
#endif
	if (ret < 0)
		return 0;
	if (ret == 0 || buf[0] != '/') {
		errno = ENOENT;
		return 0;
	}
	return buf == tmp ? strdup(buf) : buf;
}
