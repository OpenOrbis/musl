/*__asm__(
".text \n"
".global " START " \n"
START ": \n"
"	xor %rbp,%rbp \n"
"	mov %rsp,%rdi \n"
".weak _DYNAMIC \n"
".hidden _DYNAMIC \n"
"	lea _DYNAMIC(%rip),%rsi \n"
"	andq $-16,%rsp \n"
"	call " START "_ps4_c \n"
);*/

__asm__(
".text \n"
".global " START " \n"
START ": \n"
"   jmp " START "_ps4_c \n"
);

/*__asm__(
".intel_syntax noprefix \n"
".global " START " \n"
START ": \n"
"sub rsp, 0x28 \n"
"mov rdi, r8 \n"
"call atexit \n"
"xor edx, edx \n"
"mov edi, r9d \n"
"mov rsi, r10 \n"
"call main \n"
"mov r11d, eax \n"
"mov edi, r11d \n"
"call exit \n"
".att_syntax prefix \n"
);*/

// sceLibcParam
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.rel.ro._sceLibcParam\" \n"
"_sceLibcParam: \n"
"	.quad   0x90 \n"
	// metadata
"	.quad 	0x10000000C \n"
"	.quad	sceLibcHeapSize \n"
"	.quad	0 \n"
"	.quad	sceLibcHeapExtendedAlloc \n"
"	.quad	0 \n"
"	.quad	sceLibcMallocReplace \n"
"	.quad 	sceLibcNewReplace \n"
"	.quad	0 \n"
	// Need_sceLibc
"	.quad	0 \n"
"	.quad	0 \n"
"	.quad	0 \n"
"	.quad	sceLibcMallocReplaceForTls \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad	0 \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

// sceKernelMemParam
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.rel.ro._sceKernelMemParam\" \n"
"_sceKernelMemParam: \n"
	// size
"	.quad   0x30 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

// sceKernelFsParam
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.rel.ro._sceKernelFsParam\" \n"
"_sceKernelFsParam: \n"
	// size
"	.quad 	0x10 \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

// sceLibcMallocReplace
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.rel.ro._sceLibcMallocReplace\" \n"
"sceLibcMallocReplace: \n"
	// size
"	.quad 	0x70 \n"
"	.quad 	1 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

// sceLibcNewReplace
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.rel.ro._sceLibcNewReplace\" \n"
"sceLibcNewReplace: \n"
	// size
"	.quad 	0x70 \n"
"	.quad 	2 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

// sceLibcMallocReplaceForTls
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.rel.ro._sceLibcMallocReplaceForTls\" \n"
"sceLibcMallocReplaceForTls: \n"
	// size
"	.quad 	0x38 \n"
"	.quad 	1 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

// sce_process_param
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".section \".data.sce_process_param\" \n"
"_sceProcessParam: \n"
	// size
"	.quad 	0x50 \n"
	// magic "ORBI"
"	.long   0x4942524F \n"
	// entry count
"	.long 	0x3 \n"
	// sdk version
"	.quad 	0x4508101 \n"
"	.quad 	0 \n"
"	.quad 	0 \n"
"	.quad	0 \n"
"	.quad 	0 \n"
"	.quad 	_sceLibcParam \n"
"	.quad 	_sceKernelMemParam \n"
"	.quad 	_sceKernelFsParam \n"
".att_syntax prefix \n"
);

// data globals
__asm__(
".intel_syntax noprefix \n"
".align 0x8 \n"
".data \n"
"sceLibcHeapExtendedAlloc: \n"
"	.quad	1 \n"
"sceLibcHeapSize: \n"
"	.quad	0xffffffffffffffff \n"
"sce_libc_heap_delayed_alloc: \n"
"	.long 	0 \n"
"sce_libc_heap_extended_alloc: \n"
"	.long 	0 \n"
"__dso_handle: \n"
"	.quad 	0 \n"
"_sceLibc: \n"
"	.quad 	0 \n"
".att_syntax prefix \n"
);

