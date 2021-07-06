#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "syscall.h"
#include "libc.h"
#include "pthread_impl.h"

static void dummy(int x)
{
}

weak_alias(dummy, __fork_handler);

#ifdef PS4

__attribute__((naked)) pid_t rfork(int flags)
{
    __asm__ volatile(
        ".intel_syntax noprefix\n"
        "mov rsi, rsp\n"
        "lea rdx, [rip+.L1]\n"
        "jmp rfork_thread@PLT\n"
        ".L1:\n"
        "xor eax, eax\n"
        "add rsp, 8\n"
        "ret\n"
        ".att_syntax prefix\n"
    );
}

pid_t fork(void)
{
    return rfork(0);
}

#else

pid_t fork(void)
{
	pid_t ret;
	sigset_t set;
	__fork_handler(-1);
	__block_all_sigs(&set);
#ifdef SYS_fork
	ret = __syscall(SYS_fork);
#else
	ret = __syscall(SYS_clone, SIGCHLD, 0);
#endif
	if (!ret) {
		pthread_t self = __pthread_self();
		self->tid = __syscall(SYS_gettid);
		self->robust_list.off = 0;
		self->robust_list.pending = 0;
		self->next = self->prev = self;
		__thread_list_lock = 0;
		libc.threads_minus_1 = 0;
	}
	__restore_sigs(&set);
	__fork_handler(!ret);
	return __syscall_ret(ret);
}

#endif
