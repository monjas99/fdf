/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:44:56 by david             #+#    #+#             */
/*   Updated: 2023/10/09 11:54:05 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print(t_read *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->heigth)
	{
		j = 0;
		while (j < file->width)
		{
			ft_printf("%d", file->color[i][j].rgb);
			ft_printf(" ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	ft_draw(t_read *file)
{
	file->y = 0;
	while (file->y <= file->heigth - 1)
	{
		file->x = 0;
		while (file->x <= file->width - 1)
		{
			if (file->x < file->width - 1)
				ft_bresenham(file, file->x + 1, file->y);
			if (file->y < file->heigth - 1)
				ft_bresenham(file, file->x, file->y + 1);
			file->x++;
		}
	file->y++;
	}
}

void	leaks(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	t_read		*file;

	atexit(leaks);
	if (ac != 2)
		return (ft_printf("Number of arguments incorrent"));
	ft_error_av(av[1]);
	file = malloc(sizeof(*file));
	if (!file)
		return (0);
	ft_file(file, av[1]);
	ft_init(file);
	file->coor = malloc(sizeof(*file->coor));
	//ft_print(file);
	ft_draw(file);
	mlx_put_image_to_window
		(file->win->mlx_ptr, file->win->win_ptr, file->win->img, 0, 0);
	ft_window_control(file->win, file);
	mlx_loop(file->win->mlx_ptr);
	return (0);
}
