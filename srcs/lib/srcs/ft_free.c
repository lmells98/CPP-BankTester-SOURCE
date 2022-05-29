#include "libft.h"

void	freeStr(char **str) {
	if (*str)
		free(*str);
	*str = NULL;
}