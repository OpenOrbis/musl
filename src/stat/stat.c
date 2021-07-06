#include <sys/stat.h>
#include <fcntl.h>

#ifndef PS4

int stat(const char *restrict path, struct stat *restrict buf)
{
	return fstatat(AT_FDCWD, path, buf, 0);
}

#if !_REDIR_TIME64
weak_alias(stat, stat64);
#endif

#else

int stat(const char* restrict, struct stat* restrict);

int stat64(const char* restrict path, struct stat* restrict buf)
{
	return stat(path, buf);
}

#endif
