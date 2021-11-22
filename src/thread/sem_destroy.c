#include <semaphore.h>

int sem_destroy(sem_t *sem)
{
#ifdef PS4
	int ksem_destroy(void*);
	return ksem_destroy(sem);
#else
	return 0;
#endif
}
