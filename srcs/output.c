#include "tester.h"

static void	printSep(size_t len) {
	if (len <= 14)
		printf("\t\t|\t");
	else
		printf("\t|\t");
}

void	printBlocks(char **stock, char **compare) {
	char	*out;

	printf("\n");
	for (size_t i = 0; stock[i] || compare[i]; i++)
	{
		printf("[%ld]:\t", i);
		if (stock[i])
		{
			out = ft_strdup(stock[i]);
			printf("[%s]", out);
			freeStr(&out);
		}
		else
			printf("[(NULL)]");
		printSep(ft_strlen(stock[i]));
		if (compare[i])
		{
			out = ft_strdup(compare[i]);
			printf("[%s]", out);
			freeStr(&out);
		}
		else
			printf("[(NULL)]");
		printf("\n");
	}
}
