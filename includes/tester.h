#ifndef TESTER_H
# define TESTER_H

# include <sys/time.h>
# include <stdio.h>
# include "libft.h"

typedef struct leap {
	size_t				*leapSize;
	unsigned long long	calc;
}	leap_t;

typedef struct timeTracker {
	int			yr;
	int			mo;
	int			day;
	int			hr;
	int			min;
	int 		sec;
}	tStamp_t;

typedef struct tester {
	int			fd;
	bool		eof;
	char		*log;
	char		*line;
	char		*timestamp;
	char		**accountData;
	size_t		totalLineCount;
	size_t		currLineCount;
	size_t		KOID;
}	test_t;

// Tester.c
test_t	*g_stock(void);
test_t	**g_compare(void);
// Init.c
int		_initialise(char **av);
int		openfd(int *fd, char *file);
void	closefd(int *fd);
// Compare.c
int		compareTest(int *result);
char	**generateBlock(char **data);
// Diff.c
size_t	compareData(char **stock, char **compare);
// ErrorKO.c
int		_error(int err);
void	printLineKO(size_t i);
// Utils.c
bool	isNull(char **array);
char	*noNewLineFree(char *str, bool free);
char	**append2dArray(char **dest, char **src);
size_t	get2dSize(char **array);
size_t	getLineCount(int *fd);
// Free.c
void	freeStr(char **str);
void	updateData(char **stock, char **compare, bool free);
void	freeChar2d(char **array);
void	freeStructs(test_t *compare);
// Output.c
void	printBlocks(char **stock, char **compare);
// Timestamp.c
char	*setTimestamp(char *timeStr);
long long	getCurrTimestamp(tStamp_t *stamp);
// Leap.c
leap_t	*newLeap(size_t *leapSize, unsigned long long calc);
size_t	setLeapSkips(long long *sys, leap_t *leap, size_t max);

#endif