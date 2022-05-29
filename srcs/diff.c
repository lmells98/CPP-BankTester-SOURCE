#include "tester.h"

size_t	compareData(char **stock, char **compare) {
	size_t i = 0;
	
	if (stock[0])
	{
		free(stock[0]);
		stock[0] = ft_strdup(g_stock()->timestamp);
	}
	while (stock[i] && compare[i])
	{
		if (ft_strcmp(stock[i], compare[i]))
			break ;
		i++;
	}
	if (i == get2dSize(stock))
		return 0;
	return (i + 1);
}