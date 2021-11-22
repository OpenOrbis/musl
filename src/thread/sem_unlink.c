#include <semaphore.h>
#include <sys/mman.h>

int sem_unlink(const char *name)
{
#ifndef PS4
	return shm_unlink(name);
#else
	int ksem_unlink(const char*);
	return ksem_unlink(name);
#endif
}
