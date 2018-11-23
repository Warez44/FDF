/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:00:36 by clingier          #+#    #+#             */
/*   Updated: 2018/11/23 18:06:30 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_a_band(void *mlx_ptr, void *win_ptr, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, j, i, color);
			j++;
		}
		i++;
	}
}

t_point	*strtopoint(char *str, int y)
{
	char	**tab;
	int		i;
	t_point *one_line;

	i = 0;
	tab = ft_strsplit(str, ' ');
	one_line = (t_point *)malloc(sizeof(t_point) * ft_tablen(tab));
	while (tab[i])
	{
		one_line[i].eol = 0;
		one_line[i].x = i;
		one_line[i].y = y;
		one_line[i].z = ft_atoi(tab[i]);
		i++;
	}
	one_line[i].eol = 1;
	return (one_line);
}

t_grid		grid_creator(char **file)
{
	int y;
	int j;
	t_grid grid;
	t_point **scalar_field;

	y = 0;
	scalar_field = (t_point **)malloc(sizeof(t_point *) * ft_tablen(file));
	while (file[y])
	{
		scalar_field[y] = strtopoint(file[y], y);
		y++;
	}
	grid.scalar_field = scalar_field;
	return (grid);
}

int		howmanylines(char *filename)
{
	int fd;
	char buf[255];
	int count;
	int ret;
	int i;

	count = 0;
	fd = open(filename, 0);
	while ((ret = read(fd, &buf, 254)))
	{
		buf[ret] = '\0';
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
				count++;
			i++;
		}
	}
	close(fd);
	return (count);
}

char	**filetochar(char *filename)
{
	int fd;
	int i;
	char **tab;

	fd = open(filename, 0);
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (howmanylines(filename) + 1));
	while (get_next_line(fd, &tab[i]))
		i++;
	tab[i] = NULL;
	return (tab);
}

#include <stdio.h>

int		main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	char **tab;

	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	tab = filetochar("test.txt");
	int i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
	i = 0;
	pointer = strtopoint(tab[0], 0);
}
