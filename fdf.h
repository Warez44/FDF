/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:30:02 by clingier          #+#    #+#             */
/*   Updated: 2018/11/23 17:56:12 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <get_next_line.h>

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int eol;
}				t_point;

typedef struct	s_line
{
	t_point begin;
	t_point end;
}				t_line;

typedef struct 	s_grid
{
	t_point **scalar_field;
}				t_grid;

void	draw_line(void *mlx_ptr, void *win_ptr, int color, t_line line);

#endif
