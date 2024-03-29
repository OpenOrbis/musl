#include <semaphore.h>
#include "pthread_impl.h"

int sem_trywait(sem_t *sem)
{
#ifndef PS4
	int val;
	while ((val=sem->__val[0]) > 0) {
		int new = val-1-(val==1 && sem->__val[1]);
		if (a_cas(sem->__val, val, new)==val) return 0;
	}
	errno = EAGAIN;
	return -1;
#else
	int ksem_trywait(void*);
	return ksem_trywait(sem);
#endif
}
