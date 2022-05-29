#include "tester.h"

static void	setDayMonth(long long sys, tStamp_t *stamp) {
	// quadricentennials, centennials, quadrennials, annuals
	size_t			qc, c, q, a;
	size_t			year, leap;
	size_t			month, yday, mday;
	const size_t	daysSinceStart[2][13] = {
		{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
		{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
	};
	// Reset sys time from 1970 to 1601;
	sys += 11644473600LL;
	// Remove multiple of 400 years (including 97 leap days).
	qc = sys / 12622780800ULL;
	sys %= 12622780800ULL;
	// Remove multiples of 100 years (including 24 leap days)
	// Cant be more than 3, beacuse multiples of 4*100=400 years (including leap days)
	// Have been removed.
	c = setLeapSkips(&sys, newLeap(&c, 3155673600ULL), 3);
	// Remove multiples of 4 years (including 1 leap day)
	// Cant be more than 24, beacuse multiples of 25*4=100 years (including leap days)
	// Have been removed.
	q = setLeapSkips(&sys, newLeap(&q, 126230400ULL), 24);
	// Remove multiples of years (including leap days)
	// Cant be more than 3, beacuse multiples of 4 years (including leap days)
	// Have been removed.
	a = setLeapSkips(&sys, newLeap(&a, 31536000ULL), 3);
	// Calculate the year and find if it is a leap year.
	year = 1601 + qc * 400 + c * 100 + q * 4 + a;
	leap = !(year % 4) && (year % 100 || !(year % 400));
	// Calculate month and find what day of the month.
	yday = sys / 86400;
	for (mday = month = 1; month < 13; month++)
	{
		if (yday < daysSinceStart[leap][month])
		{
			mday += yday - daysSinceStart[leap][month - 1];
			break;
		}
	}
	stamp->day = mday;
	stamp->mo = month;
}

static void	genTimestamp(long long *curr, long long *sys, tStamp_t *stamp) {
	setDayMonth(*sys, stamp);
	stamp->yr = *sys / (86400 * 365) + 1970;
	*sys %= 86400;
	stamp->hr = *sys / 3600;
	*sys %= 3600;
	stamp->min = *sys / 60;
	*sys %= 60;
	stamp->sec = *sys;
	*curr = stamp->yr * 100 + stamp->mo;
	*curr = *curr * 100 + stamp->day;
	*curr = *curr * 100 + stamp->hr;
	*curr = *curr * 100 + stamp->min;
	*curr = *curr * 100 + stamp->sec;
	*sys = 0;
}

long long	getCurrTimestamp(tStamp_t *stamp) {
	long long		sysTime = 0, currTime = 0;
	struct timeval	now;
	
	gettimeofday(&now, NULL);
	sysTime = now.tv_sec;
	sysTime += (3600 * 9.5);
	genTimestamp(&currTime, &sysTime, stamp);
	return (currTime);
}

char	*setTimestamp(char *timeStr) {
	char	*timeStamp = NULL;
	size_t	len = 0;

	if (!timeStr)
		return NULL;
	len = ft_strlen(timeStr);
	timeStamp = malloc(len + 4);
	if (!timeStamp)
		return NULL;
	timeStamp[0] = '[';
	for (size_t i = 1, j = 0; j < len + 1; j++)
	{
		if (i == 9)
		{
			timeStamp[i] = '_';
			i++;
		}
		timeStamp[i] = timeStr[j];
		i++;
	}
	timeStamp[len + 2] = ']';
	timeStamp[len + 3] = '\0';
	if (timeStr)
		free(timeStr);
	return (timeStamp);
}
