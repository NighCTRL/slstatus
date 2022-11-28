/* See LICENSE file for copyright and license details. */
#include "../slstatus.h"
#if defined(__linux__)
	#include <stdint.h>
	#include <stdio.h>

	#include "../util.h"

	#define ENTROPY_AVAIL "/proc/sys/kernel/random/entropy_avail"

	const char *
	entropy(const char *unused)
	{
		uintmax_t num;

		if (pscanf(ENTROPY_AVAIL, "%ju", &num) != 1)
			return NULL;

		return bprintf("%ju", num);
	}
#elif defined(__OpenBSD__) | defined(__FreeBSD__)
	const char *
	entropy(const char *unused)
	{
		/* Unicode Character 'INFINITY' (U+221E) */
		return "\xe2\x88\x9e";
	}
#endif
