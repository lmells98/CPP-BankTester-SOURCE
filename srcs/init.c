#include "tester.h"

int	openfd(int *fd, char *file) {
	*fd = open(file, O_RDONLY, 0444);
	if (*fd < 0)
		return -2;
	return 0;
}

void	closefd(int *fd) {
	close(*fd);
	*fd = 0;
}

static bool	_initTime() {
	tStamp_t	*tStamp = NULL;
	
	tStamp = malloc(sizeof(tStamp_t));
	if (!tStamp)
		return false;
	memset(tStamp, 0, sizeof(tStamp_t));
	g_stock()->timestamp = setTimestamp(lltoa(getCurrTimestamp(tStamp)));
	if (tStamp)
		free(tStamp);
	if (!g_stock()->timestamp)
		return false;
	return true;
}

int	_initialise(char **av) {
	int	err;

	memset(g_stock(), 0, sizeof(test_t));
	if (!_initTime())
		return -1;
	g_stock()->log = av[1];
	err = openfd(&g_stock()->fd, g_stock()->log);
	(*g_compare()) = malloc(1 * sizeof(test_t));
	if (!(*g_compare()))
		return -1;
	memset((*g_compare()), 0, sizeof(test_t));
	(*g_compare())->log = av[2];
	err = openfd(&(*g_compare())->fd, (*g_compare())->log);
	return (err);
}