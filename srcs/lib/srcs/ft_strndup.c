#include "libft.h"

char	*ft_strndup(const char *src, size_t size) {
	char	*dup = NULL;
	size_t	i = 0;

	if (!src || size == 0)
		return NULL;
	dup = malloc(size + 1);
	if (!dup)
		return NULL;
	while (src[i] != '\0' && i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
