#include <sys/socket.h>
#include <sys/ioctl.h>

#ifndef PS4
int sockatmark(int s)
{
	int ret;
	if (ioctl(s, SIOCATMARK, &ret) < 0)
		return -1;
	return ret;
}
#else
int sockatmark(int s)
{
	return -1;
}
#endif

