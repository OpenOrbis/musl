#define _BSD_SOURCE
#include <unistd.h>
#include <errno.h>
#include "syscall.h"
#include <stdarg.h>

#undef syscall

#ifdef PS4

#ifdef PS4_ENABLE_SYSCALL_FN
__attribute__((naked)) long syscall(long n, ...)
{
    __asm__ volatile(
       ".intel_suffix noprefix\n"
       "mov rax, rdi\n"
       "mov rdi, rsi\n"
       "mov rsi, rdx\n"
       "mov rdx, rcx\n"
       "mov rcx, r8\n"
       "mov r8, r9\n"
       "mov r9, [rsp+8]\n"
       "syscall\n"
       "jc .L1\n"
       "ret\n"
       ".L1:\n"
       "push rax\n"
       "call __error@PLT\n"
       "pop rcx\n"
       "mov [rax], ecx\n"
       "xor eax, eax\n"
       "dec rax\n"
       "ret\n"
       ".att_syntax prefix\n"
    );
}
#else
long syscall(long n, ...)
{
    errno = ENOSYS;
    return -1;
}
#endif

#else

long syscall(long n, ...)
{
	va_list ap;
	syscall_arg_t a,b,c,d,e,f;
	va_start(ap, n);
	a=va_arg(ap, syscall_arg_t);
	b=va_arg(ap, syscall_arg_t);
	c=va_arg(ap, syscall_arg_t);
	d=va_arg(ap, syscall_arg_t);
	e=va_arg(ap, syscall_arg_t);
	f=va_arg(ap, syscall_arg_t);
	va_end(ap);
	return __syscall_ret(__syscall(n,a,b,c,d,e,f));
}

#endif
