#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

char __printfBuffer[0x1000];

int printf(const char *restrict fmt, ...)
{
	int ret;
	va_list ap;
	va_start(ap, fmt);
	ret = vsnprintf(__printfBuffer, sizeof(__printfBuffer), fmt, ap);
	ret = write(1, __printfBuffer, ret);
	va_end(ap);
	return ret;
}
