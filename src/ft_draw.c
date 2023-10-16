/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:23:16 by david             #+#    #+#             */
/*   Updated: 2023/10/16 12:17:32 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_read *file, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0) && (y >= 0))
	{
		file->win->addr = mlx_get_data_addr
			(file->win->img, &file->win->bits_per_pixel,
				&file->win->line_length, &file->win->endian);
		dst = file->win->addr + (y * file->win->line_length + x * (
					file->win->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	ft_isometric(float *x, float *y, int z, t_read *file)
{
	*x = (*x - *y) * cos(file->cos);
	*y = (*x + *y) * sin(file->sen) - z;
}

static void	ft_take_param(t_read *file, float x1, float y1)
{
	file->coor->x = file->x;
	file->coor->y = file->y;
	file->coor->x_next = x1;
	file->coor->y_next = y1;
	file->coor->z = file->z[file->y][file->x];
	file->coor->z_next = file->z[(int)y1][(int)x1];
	file->coor->x *= file->zoom;
	file->coor->x_next *= file->zoom;
	file->coor->y *= file->zoom;
	file->coor->y_next *= file->zoom;
	file->coor->color = file->color[file->y][file->x].rgb;
	file->coor->z *= file->zoom_z;
	file->coor->z_next *= file->zoom_z;
}

void	ft_bresenham(t_read *file, float x1, float y1)
{
	float	max;

	ft_take_param(file, x1, y1);
	ft_isometric(&file->coor->x, &file->coor->y, file->coor->z, file);
	ft_isometric(&file->coor->x_next,
		&file->coor->y_next, file->coor->z_next, file);
	file->coor->x += file->x_shift;
	file->coor->y += file->y_shift;
	file->coor->x_next += file->x_shift;
	file->coor->y_next += file->y_shift;
	file->coor->x_step = file->coor->x_next - file->coor->x;
	file->coor->y_step = file->coor->y_next - file->coor->y;
	max = max1(absolut(file->coor->x_step), absolut(file->coor->y_step));
	file->coor->x_step /= max;
	file->coor->y_step /= max;
	while ((int)(file->coor->x - file->coor->x_next) ||
		(int)(file->coor->y - file->coor->y_next))
	{
		my_mlx_pixel_put(file, file->coor->x, file->coor->y, file->coor->color);
		file->coor->x += file->coor->x_step;
		file->coor->y += file->coor->y_step;
	}
}
