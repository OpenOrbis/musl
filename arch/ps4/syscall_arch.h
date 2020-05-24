#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

static __inline long __syscall0(long n)
{
	unsigned long ret;

	__asm__ __volatile__
	(
		".intel_syntax\n\t"
		"syscall\n\t"
		"jnc syscallexit%=\n\t"
		"neg rax\n\t"
		"syscallexit%=:\n\t" : "=a"(ret) :
                                       "a"(n) :
                                       "rcx", "r8", "r9", "r10", "r11", "memory"
	);

	return ret;
}

static __inline long __syscall1(long n, long a1)
{
	unsigned long ret;

	__asm__ __volatile__
	(
		".intel_syntax\n\t"
		"syscall\n\t"
		"jnc syscallexit%=\n\t"
		"neg rax\n\t"
		"syscallexit%=:\n\t" : "=a"(ret) :
                                       "a"(n), "D"(a1) :
                                       "rcx", "r8", "r9", "r10", "r11", "memory"
	);

	return ret;
}

static __inline long __syscall2(long n, long a1, long a2)
{
	unsigned long ret;

	__asm__ __volatile__
	(
		".intel_syntax\n\t"
		"syscall\n\t"
		"jnc syscallexit%=\n\t"
		"neg rax\n\t"
		"syscallexit%=:\n\t" : "=a"(ret) :
                                       "a"(n), "D"(a1), "S"(a2) :
                                       "rcx", "r8", "r9", "r10", "r11", "memory"
	);

	return ret;
}

static __inline long __syscall3(long n, long a1, long a2, long a3)
{
	unsigned long ret;

	__asm__ __volatile__
	(
		".intel_syntax\n\t"
		"syscall\n\t"
		"jnc syscallexit%=\n\t"
		"neg rax\n\t"
		"syscallexit%=:\n\t" : "=a"(ret) :
                                       "a"(n), "D"(a1), "S"(a2), "d"(a3) :
                                       "rcx", "r8", "r9", "r10", "r11", "memory"
	);

	return ret;
}

static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	
	__asm__ __volatile__
	(
		".intel_syntax\n\t"
		"syscall\n\t"
		"jnc syscallexit%=\n\t"
		"neg rax\n\t"
		"syscallexit%=:\n\t" : "=a"(ret), "+r"(r10) :
                                       "a"(n), "D"(a1), "S"(a2), "d"(a3) :
                                       "rcx", "r8", "r9", "r11", "memory"
	);

	return ret;
}

static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;

	__asm__ __volatile__
	(
		".intel_syntax\n\t"
		"syscall\n\t"
		"jnc syscallexit%=\n\t"
		"neg rax\n\t"
		"syscallexit%=:\n\t" : "=a"(ret), "+r"(r10), "+r"(r8) :
                                       "a"(n), "D"(a1), "S"(a2), "d"(a3) :
                                       "rcx", "r9", "r11", "memory"
	);

	return ret;
}

static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	register long r9 __asm__("r9") = a6;

	__asm__ __volatile__
	(
		".intel_syntax\n\t"
		"syscall\n\t"
		"jnc syscallexit%=\n\t"
		"neg rax\n\t"
		"syscallexit%=:\n\t" : "=a"(ret), "+r"(r10), "+r"(r8), "+r"(r9) :
                                       "a"(n), "D"(a1), "S"(a2), "d"(a3) :
                                       "rcx", "r11", "memory"
	);

	return ret;
}

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0
