#include "libft.h"

char	*ft_strdup(const char *src) {
	char	*dup = NULL;
	size_t	i = 0;

	if (!src)
		return NULL;
	dup = malloc(ft_strlen(src) + 1);
	if (!dup)
		return NULL;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
