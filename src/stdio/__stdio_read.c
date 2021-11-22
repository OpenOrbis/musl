#include "stdio_impl.h"
#include <sys/uio.h>

#ifdef PS4

ssize_t _read(int fd, void* buf, size_t cnt);
ssize_t _readv(int fd, const struct iovec* iov, int iovcnt);

#else

static ssize_t _readv(int fd, const struct iovec* iov, int iovcnt)
{
	return syscall(SYS_readv, fd, iov, iovcnt);
}

static int _read(int fd, void* buf, size_t cnt)
{
	return syscall(SYS_read, fd, buf, cnt);
}

#endif

size_t __stdio_read(FILE *f, unsigned char *buf, size_t len)
{
	struct iovec iov[2] = {
		{ .iov_base = buf, .iov_len = len - !!f->buf_size },
		{ .iov_base = f->buf, .iov_len = f->buf_size }
	};
	ssize_t cnt;

	cnt = iov[0].iov_len ? _readv(f->fd, iov, 2)
		: _read(f->fd, iov[1].iov_base, iov[1].iov_len);
	if (cnt <= 0) {
		f->flags |= cnt ? F_ERR : F_EOF;
		return 0;
	}
	if (cnt <= iov[0].iov_len) return cnt;
	cnt -= iov[0].iov_len;
	f->rpos = f->buf;
	f->rend = f->buf + cnt;
	if (f->buf_size) buf[len-1] = *f->rpos++;
	return len;
}
