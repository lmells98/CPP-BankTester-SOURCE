#include "tester.h"

int	_error(int err) {
	char	*msg;
	char	*error = ft_strdup("Error: ");

	if (err == -1)
		msg = ft_strdup("Malloc failure!\n");
	else
		msg = ft_strdup("Failed to open files for comparison!\n");
	error = ft_strnjoin(error, msg, ft_strlen(msg));
	printf("%s", error);
	freeStr(&error);
	freeStr(&msg);
	return err;
}

static bool	printDataKO(size_t i, char **data) {
	char **blk;
	
	if ((*g_compare())->eof)
	{
		printf("\nDiff = Block [0]: (NULL)\n");
		return false;
	}
	blk = generateBlock(data);
	if (i > 0)
		i -= 1;
	if (blk[i])
		printf("\nDiff:\n => Block [%ld]: { %s }\n", i, blk[i]);
	freeChar2d(blk);
	return true;
}

char	*initLineKO(bool option) {
	char	*line = NULL;

	if (option)
	{
		line = ft_strdup(g_stock()->line);
		freeStr(&g_stock()->line);
	}
	else
	{
		line = ft_strdup((*g_compare())->line);
		freeStr(&(*g_compare())->line);
	}
	if (!line)	
		line =  ft_strdup("(NULL)");
	return (line);
}

void	printLineKO(size_t i) {
	char 	*stock = initLineKO(true);
	char 	*compare = initLineKO(false);
	
	printf("----------------\n");
	printf("Line %ld:\n", (*g_compare())->currLineCount);
	printf(" => %s\n", stock);
	printf(" => %s\n", compare);
	free(stock);
	free(compare);
	printDataKO(i, (*g_compare())->accountData);
	printf("----------------\nResult: KO!\n");
}
