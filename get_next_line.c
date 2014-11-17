/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 15:47:59 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/16 15:47:59 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	my_buf(char **buf, int *i, char **line)
{
	while (*buf && (*buf)[(*i)])
	{
		if ((*buf)[(*i)] == '\n')
		{
			*line = ft_strjoin(*line, *buf, (*i));
			(*i)++;
			*buf = &(*buf)[(*i)];
			return (1);
		}
		(*i)++;
	}
	return (0);
}

int	my_read(int const fd, char **buf)
{
	int		ret;

	ret = 0;
	*buf = (char *)malloc((sizeof(char) * BUFF_SIZE) + 1);
	if (*buf == NULL)
		return (-1);
	ret = read(fd, *buf, BUFF_SIZE);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static	char 	*buff; 
	int				ret;
	char			*tmp;

	if(!buff)
		buff = ft_strnew(BUFF_SIZE + 1);
	while (ret = my_read(fd, line, BUFF_SIZE) && ft_strchr(line, '\n') == NULL) 
	{
		if (ft_buf(&buf, &i, line) == 1)
			return (1);
		*line = tmp;
		while (ft_strchr(line, '\n'))
			i++;
		tmp = ft_strjoin(*line, buf, i);
		ret = my_read(fd, &line);
		buff[ret] = '\n';
	}
	return (ret);
}
		
int  main (int ac, char **av)
{
	int ret;
	char *line;
	int fd

	fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	close(fd);
	return (0);
}
