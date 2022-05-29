#include "libft.h"

int	ft_strlcpy(const char *src, char *dest, size_t bytes) {
	size_t	i = 0;

	if (!src || !dest ||  bytes <= 0)
		return -1;
	while (src[i] != '\0' && i < bytes)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
