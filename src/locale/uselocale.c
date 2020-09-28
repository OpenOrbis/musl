#include "locale_impl.h"
#include "pthread_impl.h"
#include "libc.h"

locale_t __uselocale(locale_t new)
{
	locale_t old = CURRENT_LOCALE;
	locale_t global = &libc.global_locale;

	if (new) CURRENT_LOCALE = new == LC_GLOBAL_LOCALE ? global : new;

	return old == global ? LC_GLOBAL_LOCALE : old;
}

weak_alias(__uselocale, uselocale);
