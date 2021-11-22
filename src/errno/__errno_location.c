#include <errno.h>
#include "pthread_impl.h"

int *__errno_location(void)
{
#ifdef PS4
	int* __error(void);
	return __error();
#else
	return &__pthread_self()->errno_val;
#endif
}

weak_alias(__errno_location, ___errno_location);
