/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <clingier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:43:50 by clingier          #+#    #+#             */
/*   Updated: 2018/11/23 17:15:02 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	draw_line(void *mlx_ptr, void *win_ptr, int color, t_line line)
{
	int		d_x;
	int		d_y;
	t_point p_i;
	double	slope;

	d_x = line.end.x - line.begin.x;
	d_y = line.end.y - line.begin.y;
	p_i.x = line.begin.x;
	if (d_x != 0)
	{
		slope = d_y / d_x;
		while (p_i.x < line.end.x)
		{
			p_i.y = slope * p_i.x + line.begin.y;
			mlx_pixel_put(mlx_ptr, win_ptr, p_i.y, p_i.x, color);
			p_i.x++;
		}
	}
	if (d_x == 0)
	{
		p_i.y = line.begin.y;
		while (p_i.y)
		{

			p_i.y++;
		}
	}
}
