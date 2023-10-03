/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:57:13 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/10/03 10:48:11 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_read *file)
{
	if (key == 69 || key == 30)
	{
		if (file->zoom < 15)
		{
			file->zoom += 1;
			file->w += 200;
			file->h += 200;
		}
	}
	else if (key == 78 || key == 44)
	{
		if (file->zoom > 5)
			file->zoom -= 1;
	}
}

void	ft_move(int key, t_read *file)
{
	if (key == 126)
		file->y_shift -= 50;
	else if (key == 125)
		file->y_shift += 50;
	else if (key == 124)
		file->x_shift += 50;
	else if (key == 123)
		file->x_shift -= 50;
}

void	ft_iso(int key, t_read *file)
{
	if (key == 13)
		file->sen += 0.2;
	else if (key == 1)
		file->sen -= 0.2;
	else if (key == 2)
		file->cos += 0.2;
	else if (key == 0)
		file->cos -= 0.2;
}

int	ft_key_press(int key, t_read *file)
{
	if (key == 53)
	{
		mlx_clear_window(file->win->mlx_ptr, file->win->win_ptr);
		mlx_destroy_window(file->win->mlx_ptr, file->win->win_ptr);
		ft_close();
	}
	ft_zoom(key, file);
	ft_move(key, file);
	ft_iso(key, file);
	mlx_clear_window(file->win->mlx_ptr, file->win->win_ptr);
	mlx_destroy_image(file->win->mlx_ptr, file->win->img);
	file->win->img = mlx_new_image(file->win->mlx_ptr,
			file->w, file->h);
	ft_draw(file);
	mlx_put_image_to_window
		(file->win->mlx_ptr, file->win->win_ptr, file->win->img, 0, 0);
	return (0);
}

void	ft_window_control(t_window *window, t_read *file)
{
	mlx_hook(window->win_ptr, 2, 0, ft_key_press, file);
	mlx_hook(window->win_ptr, 17, 0, ft_close, window);
}
