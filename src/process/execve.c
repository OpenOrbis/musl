#include <unistd.h>
#include "syscall.h"

int execve(const char *path, char *const argv[], char *const envp[])
{
#ifdef PS4
	int _execve(const char* path, char* const* argv, char* const* envp);
	return _execve(path, argv, envp);
#else
	/* do we need to use environ if envp is null? */
	return syscall(SYS_execve, path, argv, envp);
#endif
}
