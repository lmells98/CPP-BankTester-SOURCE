#include "libft.h"

static size_t	getNbrLen(unsigned long long nbr) {
	size_t	len = 0;

	if (nbr == 0)
		return 1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*lltoa(long long nbr) {
	char	*out = NULL;
	bool	neg = false;
	size_t	len = 0;

	if (nbr < 0)
	{
		neg = true;
		nbr *= -1;
	}
	len = getNbrLen(nbr) + neg;
	out = malloc(len + 1);
	if (!out)
		return NULL;
	out[len] = '\0';
	if (neg)
		out[0] = '-';
	while (nbr != 0)
	{
		out[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (out);
}