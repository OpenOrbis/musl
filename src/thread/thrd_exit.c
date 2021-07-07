#include <threads.h>
#include <pthread.h>
#include <stdint.h>

_Noreturn void thrd_exit(int result)
{
	pthread_exit((void*)(intptr_t)result);
}
