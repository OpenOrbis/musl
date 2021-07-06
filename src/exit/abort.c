#include <stdlib.h>
#include <signal.h>
#include "syscall.h"
#include "pthread_impl.h"
#include "atomic.h"
#include "lock.h"
#include "ksigaction.h"

hidden volatile int __abort_lock[1];

_Noreturn void abort(void)
{
	raise(SIGABRT);

	/* If there was a SIGABRT handler installed and it returned, or if
	 * SIGABRT was blocked or ignored, take an AS-safe lock to prevent
	 * sigaction from installing a new SIGABRT handler, uninstall any
	 * handler that may be present, and re-raise the signal to generate
	 * the default action of abnormal termination. */
	__block_all_sigs(0);
	LOCK(__abort_lock);
	sigaction(SIGABRT,
		&(struct sigaction){.sa_handler = SIG_DFL}, 0);
	raise(SIGABRT);
	sigprocmask(SIG_UNBLOCK,
		&(long[_NSIG/(8*sizeof(long))]){1UL<<(SIGABRT-1)}, 0);

	/* Beyond this point should be unreachable. */
	a_crash();
	raise(SIGKILL);
	_Exit(127);
}
