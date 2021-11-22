#include <semaphore.h>

int sem_getvalue(sem_t *restrict sem, int *restrict valp)
{
#ifdef PS4
	int ksem_getvalue(void* restrict, int* restrict);
	return ksem_getvalue(sem, valp);
#else
	int val = sem->__val[0];
	*valp = val < 0 ? 0 : val;
	return 0;
#endif
}
