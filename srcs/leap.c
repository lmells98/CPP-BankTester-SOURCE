#include "tester.h"

leap_t *newLeap(size_t *leapSize, unsigned long long calc) {
	leap_t	*leap;

	leap = malloc(sizeof(leap_t));
	if (!leap)
		return NULL;
	leap->leapSize = leapSize;
	leap->calc = calc;
	return (leap);
}

size_t setLeapSkips(long long *sys, leap_t *leap, size_t max) {
	size_t	leapSkip = 0;

	if (!leap)
		return 0;
	*leap->leapSize = *sys / leap->calc;
	if (*leap->leapSize > max)
		*leap->leapSize = max;
	*sys -= (*leap->leapSize * leap->calc);
	leapSkip = *leap->leapSize;
	if (leap)
		free(leap);
	return (leapSkip);
}