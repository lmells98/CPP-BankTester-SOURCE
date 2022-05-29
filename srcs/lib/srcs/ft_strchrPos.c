#include "libft.h"

int	ft_strchrPos(const char *str, int c, int flag) {
	int	i = 0;

	if (!str && flag == 1)
		return -5;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return -1;
}