#include "pthread_impl.h"
#include "atomic.h"
#include "syscall.h"
/* cheat and reuse CRTJMP macro from dynlink code */
#include "dynlink.h"
#include <stdlib.h>

static void *unmap_base;
static size_t unmap_size;
static char shared_stack[256];

static void do_unmap()
{
	munmap(unmap_base, unmap_size);
#ifndef PS4
	__syscall(SYS_exit);
#else
	int thr_exit(void*);
	thr_exit(0);
	_Exit(0);
#endif
}

void __unmapself(void *base, size_t size)
{
	char *stack = shared_stack + sizeof shared_stack;
	stack -= (uintptr_t)stack % 16;
	unmap_base = base;
	unmap_size = size;
	CRTJMP(do_unmap, stack);
}
