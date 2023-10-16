/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:44:51 by david             #+#    #+#             */
/*   Updated: 2023/10/13 16:37:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	ft_free(t_read *file)
{
	int	i;
	int	j;

	i = 0;
	while (i < file->heigth)
	{
		j = 0;
		free (file->z[i]);
		//free (file->color[i]);
		i++;
	}
	free (file->z);
	free (file->color);
	free (file);
}*/

static void	ft_error_col(t_read *file)
{
	free (file);
	ft_printf("Invalid color map\n");
	exit (1);
}

static void	ft_error_num(void)
{
	ft_printf("Invalid number map\n");
	exit (1);
}

static void	ft_error_color(char	*line, t_read *file)
{
	int	size;
	int	i;

	i = 1;
	size = ft_strlen_fdf(line) - 1;
	if (size > 8 || size < 4)
		ft_error_col(file);
	if (line[i] != '0')
		ft_error_col(file);
	i++;
	if (line[i] != 'x' && line[i] != 'X')
		ft_error_col(file);
	i++;
	while (line[i] && line[i] != '\n')
	{
		if ((line[i] < 'a' || line[i] > 'f')
			&& (line[i] < 'A' || line[i] > 'F')
			&& (line[i] < '0' || line[i] > '9'))
			ft_error_col(file);
		i++;
	}
}

void	ft_map_error(char *line, t_read *file)
{
	int	i;

	i = 0;
	if (line[0] == '+' || line[0] == '-')
	i++;
	while (line[i] && line[i] != ',')
	{
			if (line[i] == '\n')
			break ;
		if (line[i] > '9' || line[i] < '0')
		{
			ft_error_num();
		}
		i++;
	}
	if (line[i] == ',')
		ft_error_color(ft_strchr(line, ','), file);
}
