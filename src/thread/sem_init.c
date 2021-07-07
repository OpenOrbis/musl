#include <semaphore.h>
#include <limits.h>
#include <errno.h>

int sem_init(sem_t *sem, int pshared, unsigned value)
{
#ifdef PS4
	if (pshared)
	{
		errno = EPERM; //from freebsd man
		return -1;
	}
	int ksem_init(void*, unsigned int);
	return ksem_init(sem, value);
#else	
	if (value > SEM_VALUE_MAX) {
		errno = EINVAL;
		return -1;
	}
	sem->__val[0] = value;
	sem->__val[1] = 0;
	sem->__val[2] = pshared ? 0 : 128;
	return 0;
#endif
}
