#include <sys/reboot.h>
#include "syscall.h"

int reboot(int type)
{
#ifdef PS4
	int sceKernelReboot(int type);
	return sceKernelReboot(type);
#else
	return syscall(SYS_reboot, 0xfee1dead, 672274793, type);
#endif
}
