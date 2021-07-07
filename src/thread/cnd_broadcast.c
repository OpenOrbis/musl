#include <threads.h>
#include <pthread.h>

int cnd_broadcast(cnd_t *c)
{
	/* This internal function never fails, and always returns zero,
	 * which matches the value thrd_success is defined with. */
#ifndef PS4
	return __private_cond_signal((pthread_cond_t *)c, -1);
#else
	return pthread_cond_broadcast((pthread_cond_t *)c);
#endif
}
