#include "tester.h"

char	**generateBlock(char **data) {
	char	**tmp;
	char	**block = NULL;

	for (size_t i = 0; data && data[i] != NULL; i++)
	{
		tmp = ft_split(data[i], ';');
		if (!tmp)
			return NULL;
		block = append2dArray(block, tmp);
		freeChar2d(tmp);
	}
	return (block);
}

static int	compareLine() {
	char	**stockBLK;
	char	**compareBLK;

	stockBLK = generateBlock(g_stock()->accountData);
	if (!stockBLK)
		return -1;
	compareBLK = generateBlock((*g_compare())->accountData);
	if (!compareBLK)
	{
		if (stockBLK)
			freeChar2d(stockBLK);
		return -1;
	}
	// printBlocks(stockBLK, compareBLK);
	(*g_compare())->KOID = compareData(stockBLK, compareBLK);
	freeChar2d(stockBLK);
	freeChar2d(compareBLK);
	return ((*g_compare())->KOID);
}

static int	checkResult(int result, char *stock, char *compare) {
	if (result < 0)
	{
		if (result == -3)
		{
			freeStr(&stock);
			return (result + 2);
		}
		freeStr(&compare);
	}
	if (result)
	{
		freeChar2d(g_stock()->accountData);
		if (stock)
			g_stock()->line = ft_strndup(stock, ft_strlen(stock));
		else
			g_stock()->line = ft_strdup("(NULL)");
		result = (*g_compare())->currLineCount;
	}
	return (result);
}

static int	compareDataOutput(char *stock, char *compare) {
	size_t	i = (*g_compare())->currLineCount;

	if (!isNull((*g_compare())->accountData))
		freeChar2d((*g_compare())->accountData);
	if (!stock && compare)
	{
		(*g_compare())->accountData = ft_split(compare, ' ');
		if ((*g_compare())->accountData == NULL)
			return -1;
		printf("Error %ld:\n => No Stock line to compare...\n", i);
		printf(" => Your output is too long!\n");
		return 1;
	}
	if (stock && compare)
	{
		g_stock()->accountData = ft_split(stock, ' ');
		if (g_stock()->accountData == NULL)
			return -1;
		(*g_compare())->accountData = ft_split(compare, ' ');
		if ((*g_compare())->accountData == NULL)
			return -3;
		return (checkResult(compareLine(), stock, compare));
	}
	return 0;
}

static int	checkEOF(int *result) {
	char	*line = NULL;

	line = getNextLine((*g_compare())->fd);
	if (!line)
	{
		(*g_compare())->eof = true;
		freeChar2d((*g_compare())->accountData);
		g_stock()->line = noNewLineFree(getNextLine(g_stock()->fd), true);
		if (g_stock()->line)
		{
			freeStr(&(*g_compare())->line);
			(*g_compare())->currLineCount++;
		}
		(*g_compare())->totalLineCount = (*g_compare())->currLineCount;
	}
	else
		freeStr(&line);
	(*g_compare())->totalLineCount = (*g_compare())->currLineCount;
	return (*result);
}

int	compareTest(int *result) {
	char	*stock = NULL;

	*result = openfd(&g_stock()->fd, g_stock()->log);
	if (*result == -2)
		return (*result);
	for (char *compare = noNewLineFree(getNextLine((*g_compare())->fd), true); compare != NULL; compare = noNewLineFree(getNextLine((*g_compare())->fd), true))
	{
		(*g_compare())->currLineCount++;
		stock = noNewLineFree(getNextLine(g_stock()->fd), true);
		*result = compareDataOutput(stock, compare);
		if (*result < 0)
			return (*result);
		else if (!*result)
		{
			updateData(&stock, &compare, true);
			g_stock()->currLineCount++;
		}
		else
		{
			updateData(&stock, &compare, false);
			break ;
		}	
	}
	printf(" => Finished comparing files\n");
	return (checkEOF(result));
}
