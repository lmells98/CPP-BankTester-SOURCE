#include "libft.h"

char	*ft_strnjoin(char *old, char *new, int size) {
	int		i = 0;
	int		j = 0;
	char	*append;

	if (!new)
		return (old);
	append = malloc(ft_strlen(old) + ft_strlen(new) + 1);
	if (!append)
		return (old);
	while (old && old[i] != '\0')
	{
		append[i] = old[i];
		i++;
	}
	while (new && new[j] != '\0' && (j < size))
	{
		append[i] = new[j];
		i++;
		j++;
	}
	append[i] = '\0';
	if (old)
		free(old);
	return (append);
}
