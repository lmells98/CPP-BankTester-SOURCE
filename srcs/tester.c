#include "tester.h"

test_t	*g_stock() {
	static test_t	g_stock;

	return (&g_stock);
}

test_t	**g_compare() {
	static test_t	*g_compare;

	return (&g_compare);
}

static int	runTest(char **av) {
	int	err;

	err = _initialise(av);
	if (err < 0)
		return err;
	g_stock()->totalLineCount = getLineCount(&g_stock()->fd);
	compareTest(&err);
	if (err < 0)
	{
		if (err == -2)
			return (err);
		freeChar2d(g_stock()->accountData);
	}
	if ((*g_compare())->totalLineCount != g_stock()->totalLineCount)
		return ((*g_compare())->totalLineCount);
	return 0;
}

static void	_closeProg() {
	for (char *comp_dump = getNextLine((*g_compare())->fd); comp_dump != NULL; comp_dump = getNextLine((*g_compare())->fd))
		free(comp_dump);
	for (char *stock_dump = getNextLine(g_stock()->fd); stock_dump != NULL; stock_dump = getNextLine(g_stock()->fd))
		free(stock_dump);
	closefd(&g_stock()->fd);
	closefd(&(*g_compare())->fd);
	freeStructs((*g_compare()));
	free(g_stock()->timestamp);
}

int	main(int ac, char **av) {
	int	err;

	if (ac == 3)
	{
		err = runTest(av);
		if (err < 0)
			return (_error(err));
		else if (err == 0)
			printf("----------------\nResult: OK!\n => Perfect Match!\n");
		else
			printLineKO((*g_compare())->KOID);
		_closeProg();
	}
	return 0;
}