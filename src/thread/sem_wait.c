#include <semaphore.h>

int sem_wait(sem_t *sem)
{
#ifdef PS4
	return sem_timedwait(sem, 0);
#else
	int ksem_wait(void*);
	return ksem_wait(sem);
#endif
}
