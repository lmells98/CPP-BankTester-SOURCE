#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2) {
	int	i = 0;

	while ((s1 && (s1[i] != '\0')) && (s2 && (s2[i] != '\0')))
	{
		if (s1[i] != s2[i])
			return (i);
		i++;
	}
	if ((s1[i] != '\0' && s2[i] == '\0') || (s2[i] != '\0' && s1[i] == '\0'))
		return (i);
	return 0;
}