/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 14:21:40 by clingier          #+#    #+#             */
/*   Updated: 2018/11/23 17:43:38 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static void		ft_getline(int fd, char **files, char **line)
{
	char *temp;
	char *cur;

	cur = ft_strchr(files[fd], '\n');
	temp = files[fd];
	*cur = '\0';
	*line = ft_strdup(files[fd]);
	files[fd] = ft_strdup(cur + 1);
	free(temp);
}

static void		ft_get_content(int fd, char **files)
{
	char	*buf;
	char	*temp;
	int		ret;

	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return ;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = files[fd];
		if (!(files[fd] = ft_strjoin(files[fd], buf)))
		{
			free(buf);
			return ;
		}
		free(temp);
		if (ft_strchr(files[fd], '\n'))
			break ;
	}
	free(buf);
}

int				get_next_line(int fd, char **line)
{
	static char *files[FD_LIMIT];

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, files, 0) < 0)
		return (-1);
	if (!files[fd])
		files[fd] = ft_strnew(1);
	ft_get_content(fd, files);
	if (files[fd] == NULL)
		return (-1);
	if (ft_strchr(files[fd], '\n'))
	{
		ft_getline(fd, files, line);
		if (!line || !files[fd])
			return (-1);
		return (1);
	}
	if (*files[fd])
	{
		if (!(*line = ft_strdup(files[fd])))
			return (-1);
		ft_strdel(&files[fd]);
		return (1);
	}
	return (0);
}
