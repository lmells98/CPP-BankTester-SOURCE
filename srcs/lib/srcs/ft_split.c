#include "libft.h"

static size_t	count_words(const char *str, char delim) {
	size_t	i = 0, wc = 0;

	while (str && str[i] != '\0')
	{
		while (str[i] == delim && str[i] != '\0')
			i++;
		while (str[i] != delim && str[i] != '\0')
			i++;
		if (str[i] == delim && str[i] != '\0')
			i++;
		wc++;
	}
	return (wc);
}

static bool	isAlnum(char c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		return true;
	return false;
}

static char **populate2dArray(char **array, const char *str, size_t wc, char delim) {
	size_t	i = 0, wlen = 0, index = 0;
	
	while (str && str[i] != '\0')
	{
		while (str[i] == delim && str[i] != '\0')
			i++;
		while (str[i] != delim && str[i] != '\0')
		{
			wlen++;
			i++;
		}
		if (str[i] != '\0' && str[i] == delim)
		{
			if (!isAlnum(str[i + 1]))
			{
				wlen++;
				i++;
			}
		}
		if (index < wc)
		{
			array[index] = malloc(wlen + 1);
			if (ft_strlcpy(str + (i - wlen), array[index], wlen) == -1)
			{
				while (index <= 0)
					freeStr(&array[index--]);
				return NULL;
			}
			index++;
		}
		wlen = 0;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(const char *str, char delim) {
	char	**array = NULL;
	size_t	wc = 0;

	if (!str)
		return NULL;
	wc = count_words(str, delim);
	if (wc)
	{
		array = (char **)malloc((wc + 1) * sizeof(char *));
		if (!array)
			return NULL;
		array = populate2dArray(array, str, wc, delim);	
		return (array);
	}
	return NULL;
}

// int main() {
// 	char	**split;
// 	char 	*test = "[20220520_163027] index:0;amount:42;created\n";

// 	split = ft_split(test, ' ');
// 	for (size_t i = 0; i < get2dLen(split); i++)
// 	{
// 		if (split && split[i])
// 			printf("%ld: %s\n", i, split[i]);
// 	}
// 	freeChar2d(split);
// 	test = NULL;
// 	return 0;
// }
