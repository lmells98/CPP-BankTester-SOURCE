#include "tester.h"

bool	isNull(char **array) {
	if (!array)
		return true;
	return false;
}

char	*noNewLineFree(char *str, bool free) {
	char	*out;
	size_t	len = ft_strlen(str);

	if (!str)
		return NULL;
	out = malloc(len);
	if (!out)
		return NULL;
	for (size_t i = 0; i <= len; i++)
	{
		if (str[i] == '\n')
			i++;
		if (str[i] == '\0')
			break ;
		out[i] = str[i];
	}
	out[len - 1] = '\0';
	if (free)
		freeStr(&str);
	return (out);
}

char	**append2dArray(char **dest, char **src) {
	char	**append = NULL;
	size_t	i = 0;

	if (!src)
		return (dest);
	append = malloc((get2dSize(dest) + get2dSize(src) + 1) * sizeof(char *));
	if (!append)
		return (dest);
	for (size_t j = 0; dest && dest[j]; j++)
		append[i++] = ft_strdup(dest[j]);
	for (size_t j = 0; src && src[j]; j++)
		append[i++] = ft_strdup(src[j]);
	append[i] = NULL;
	if (dest)
		freeChar2d(dest);
	return (append);
}

size_t	get2dSize(char **array) {
	size_t	len = 0;

	while (array && array[len])
		len++;
	return (len);
}

size_t	getLineCount(int *fd) {
	size_t	count = 0;

	for (char *line = getNextLine(*fd); line != NULL; line = getNextLine(*fd))
	{
		count++;
		free(line);
	}
	closefd(fd);
	return (count);
}
