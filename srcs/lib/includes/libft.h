#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchrPos(const char *str, int c, int flag);
int		ft_strlcpy(const char *src, char *dest, size_t bytes);
char	*getNextLine(int fd);
char	*lltoa(long long nbr);
char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, size_t size);
char	*ft_strnjoin(char *old, char *append, int size);
char	**ft_split(const char *str, char delim);
void	freeStr(char **str);
size_t	ft_strlen(const char *str);

#endif