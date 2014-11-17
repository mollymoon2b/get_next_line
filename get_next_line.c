/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 15:47:59 by ade-bonn          #+#    #+#             */
/*   Updated: 2014/11/17 14:05:57 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static char		*tmp;
	int				len;
	char *tmp2;

	if (!tmp)
		tmp = ft_strnew(0);
	ret = 0;
	while ((ft_strchr(tmp, '\n')) == NULL
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp2 = tmp;
		tmp = ft_strjoin(tmp, buff);
		ft_strdel(&tmp2);
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && ft_strchr(tmp, '\n') == NULL)
	{
		*line = tmp;
		tmp == NULL;
		return (0);
	}
	len = ft_strchr(tmp, '\n') - tmp;
	*line = ft_strsub(tmp, 0, len);
	tmp2 = tmp;
	tmp = ft_strchr(tmp, '\n') + 1;
	ft_strdel(&tmp2);
	return (1);
}

int	main(int ac, char **av)
{
	int		ret;
	char	*line;
	int		fd;
	int		i;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		free(line);
	}
	close(fd);
	return (0);
}
