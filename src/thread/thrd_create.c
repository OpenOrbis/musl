#include "pthread_impl.h"
#include <threads.h>

int thrd_create(thrd_t *thr, thrd_start_t func, void *arg)
{
	//XXX: attributes here vs on PS4, are they compatible?
	int ret = pthread_create(thr, __ATTRP_C11_THREAD, (void *(*)(void *))func, arg);
	switch (ret) {
	case 0:      return thrd_success;
	case EAGAIN: return thrd_nomem;
	default:     return thrd_error;
	}
}
