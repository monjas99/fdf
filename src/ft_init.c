/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:11:03 by david             #+#    #+#             */
/*   Updated: 2023/10/03 10:45:21 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_read	*ft_init(t_read *file)
{
	t_window	*window;

	window = malloc(sizeof(*window));
	if (!window)
		return (0);
	file->w = 4500;
	file->h = 4500;
	file->win = window;
	file->win->mlx_ptr = mlx_init();
	file->win->win_ptr = mlx_new_window(
			file->win->mlx_ptr, 2500, 1200, "FDF");
	file->win->img = mlx_new_image(file->win->mlx_ptr,
			file->w, file->h);
	file->zoom = 10;
	file->zoom_z = 3;
	file->x = 0;
	file->y = 0;
	file->x_shift = 500;
	file->y_shift = 250;
	file->sen = 0.7;
	file->cos = 0.7;
	return (file);
}
