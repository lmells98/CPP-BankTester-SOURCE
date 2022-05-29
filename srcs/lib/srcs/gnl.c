#include "libft.h"

char	*updateBuff(char **buff, int nl_pos) {
	int		len;
	char	*tmp = NULL;

	len = strlen(*buff) - nl_pos;
	tmp = ft_strndup(*buff + nl_pos, len);
	freeStr(buff);
	*buff = ft_strndup(tmp, len);
	freeStr(&tmp);
	return (*buff);
}

char	*updateBuff_return(char **buff, int bytes, int nl_pos) {
	char	*output = NULL;

	if ((!*buff && bytes <= 0) || nl_pos == -5)
	{
		if (*buff)
			return (*buff);
		return NULL;
	}
	if (nl_pos == -1)
		nl_pos = ft_strlen(*buff);
	else
		nl_pos++;
	output = ft_strndup(*buff, nl_pos);
	if (nl_pos == (int)ft_strlen(*buff))
		freeStr(buff);
	else
		*buff = updateBuff(buff, nl_pos);
	return (output);
}

#define BUFF_SIZE 200
char	*getNextLine(int fd) {
	int 			bytes = 0;
	int 			nl_pos = 0;
	char			*read_buff = NULL;
	static char		*buff[10240];

	nl_pos = ft_strchrPos(buff[fd], '\n', 0);
	while (nl_pos == -1 && nl_pos != -5)
	{
		read_buff = malloc(BUFF_SIZE + 1);
		if (read_buff == NULL)
			return NULL;
		bytes = read(fd, read_buff, BUFF_SIZE);
		if (bytes <= 0)
			break ;
		read_buff[bytes] = '\0';
		buff[fd] = ft_strnjoin(buff[fd], read_buff, bytes);
		freeStr(&read_buff);
		nl_pos = ft_strchrPos(buff[fd], '\n', 1);
	}
	freeStr(&read_buff);
	return (updateBuff_return(&buff[fd], bytes, nl_pos));
}