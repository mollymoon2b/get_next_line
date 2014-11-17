#ifndef GET-NEXT-LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

int	get_next_line(int fd, char **line);
int	my_read(int const fd, char **buf);
int	my_buf(char **buf, int *i, char **line);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
