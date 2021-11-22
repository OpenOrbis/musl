#include <sys/statvfs.h>
#include <sys/statfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "syscall.h"

#ifndef PS4

static int __statfs(const char *path, struct statfs *buf)
{
	*buf = (struct statfs){0};
#ifdef SYS_statfs64
	return syscall(SYS_statfs64, path, sizeof *buf, buf);
#else
	return syscall(SYS_statfs, path, buf);
#endif
}

static int __fstatfs(int fd, struct statfs *buf)
{
	*buf = (struct statfs){0};
#ifdef SYS_fstatfs64
	return syscall(SYS_fstatfs64, fd, sizeof *buf, buf);
#else
	return syscall(SYS_fstatfs, fd, buf);
#endif
}

weak_alias(__statfs, statfs);

#else

int _fstatfs(int fd, struct statfs* buf);

static int __fstatfs(int fd, struct statfs* buf)
{
	return _fstatfs(fd, buf);
}

int statfs(const char* path, struct statfs* buf)
{
	int fd = open(path, O_PATH|O_RDONLY);
	if(fd < 0)
		return -1;
	int rv = fstatfs(fd, buf);
	int errno1 = errno;
	close(fd);
	errno = errno1;
	return fd;
}

#define __statfs statfs

#endif

weak_alias(__fstatfs, fstatfs);

#ifndef PS4
static void fixup(struct statvfs *out, const struct statfs *in)
{
	*out = (struct statvfs){0};
	out->f_bsize = in->f_bsize;
	out->f_frsize = in->f_frsize ? in->f_frsize : in->f_bsize;
	out->f_blocks = in->f_blocks;
	out->f_bfree = in->f_bfree;
	out->f_bavail = in->f_bavail;
	out->f_files = in->f_files;
	out->f_ffree = in->f_ffree;
	out->f_favail = in->f_ffree;
	out->f_fsid = in->f_fsid.__val[0];
	out->f_flag = in->f_flags;
	out->f_namemax = in->f_namelen;
	out->f_namelen = in->f_namelen;
}
#endif

int statvfs(const char *restrict path, struct statvfs *restrict buf)
{
	struct statfs kbuf;
	if (__statfs(path, &kbuf)<0) return -1;
#ifndef PS4
	fixup(buf, &kbuf);
#endif
	return 0;
}

int fstatvfs(int fd, struct statvfs *buf)
{
	struct statfs kbuf;
	if (__fstatfs(fd, &kbuf)<0) return -1;
#ifndef PS4
	fixup(buf, &kbuf);
#endif
	return 0;
}

weak_alias(statvfs, statvfs64);
weak_alias(statfs, statfs64);
weak_alias(fstatvfs, fstatvfs64);
weak_alias(__fstatfs, fstatfs64);
