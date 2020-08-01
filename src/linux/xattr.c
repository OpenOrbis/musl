#include <sys/xattr.h>
#include <errno.h>
#include "syscall.h"

ssize_t getxattr(const char *path, const char *name, void *value, size_t size)
{
#ifndef PS4
	return syscall(SYS_getxattr, path, name, value, size);
#else
	errno = ENOSYS;
	return -1;
#endif
}

ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size)
{
#ifndef PS4
	return syscall(SYS_lgetxattr, path, name, value, size);
#else
	errno = ENOSYS;
	return -1;
#endif
}

ssize_t fgetxattr(int filedes, const char *name, void *value, size_t size)
{
#ifndef PS4
	return syscall(SYS_fgetxattr, filedes, name, value, size);
#else
	errno = ENOSYS;
	return -1;
#endif
}

ssize_t listxattr(const char *path, char *list, size_t size)
{
#ifndef PS4
	return syscall(SYS_listxattr, path, list, size);
#else
	errno = ENOSYS;
	return -1;
#endif
}

ssize_t llistxattr(const char *path, char *list, size_t size)
{
#ifndef PS4
	return syscall(SYS_llistxattr, path, list, size);
#else
	errno = ENOSYS;
	return -1;
#endif
}

ssize_t flistxattr(int filedes, char *list, size_t size)
{
#ifndef PS4
	return syscall(SYS_flistxattr, filedes, list, size);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int setxattr(const char *path, const char *name, const void *value, size_t size, int flags)
{
#ifndef PS4
	return syscall(SYS_setxattr, path, name, value, size, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags)
{
#ifndef PS4
	return syscall(SYS_lsetxattr, path, name, value, size, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int fsetxattr(int filedes, const char *name, const void *value, size_t size, int flags)
{
#ifndef PS4
	return syscall(SYS_fsetxattr, filedes, name, value, size, flags);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int removexattr(const char *path, const char *name)
{
#ifndef PS4
	return syscall(SYS_removexattr, path, name);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int lremovexattr(const char *path, const char *name)
{
#ifndef PS4
	return syscall(SYS_lremovexattr, path, name);
#else
	errno = ENOSYS;
	return -1;
#endif
}

int fremovexattr(int fd, const char *name)
{
#ifndef PS4
	return syscall(SYS_fremovexattr, fd, name);
#else
	errno = ENOSYS;
	return -1;
#endif
}
