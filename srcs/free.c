#include "tester.h"

void	freeStr(char **str) {
	if (*str)
		free(*str);
	*str = NULL;
}

void	updateData(char **stock, char **compare, bool free) {
	if (!isNull(&(*g_compare())->line))
		freeStr(&(*g_compare())->line);
	(*g_compare())->line = ft_strdup(*compare);
	freeStr(stock);
	freeStr(compare);
	if (free && !isNull((g_stock())->accountData))
		freeChar2d(g_stock()->accountData);
}

void	freeChar2d(char **array) {
	int	i = 0;

	while (array && array[i])
		i++;
	i -= 1;
	while (i >= 0)
	{
		freeStr(&array[i]);
		i--;
	}
	free(array);
	array = NULL;
}

void	freeStructs(test_t *compare) {
	if (compare)
	{
		if (compare->eof == false)
			freeChar2d(compare->accountData);
		if (compare->line)
			freeStr(&compare->line);
		if (!isNull(&compare->log) && !isNull(&g_stock()->log))
		{
			g_stock()->log = NULL;
			compare->log = NULL;
		}
		free(compare);
		compare = NULL;
	}
}
