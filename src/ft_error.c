/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:44:51 by david             #+#    #+#             */
/*   Updated: 2023/10/16 12:28:02 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_error_col(void)
{
	ft_printf("Invalid color map\n");
	exit (1);
}

static void	ft_error_num(void)
{
	ft_printf("Invalid number map\n");
	exit (1);
}

static void	ft_error_color(char	*line)
{
	int	size;
	int	i;

	i = 1;
	size = ft_strlen_fdf(line) - 1;
	if (size > 8 || size < 4)
		ft_error_col();
	if (line[i] != '0')
		ft_error_col();
	i++;
	if (line[i] != 'x' && line[i] != 'X')
		ft_error_col();
	i++;
	while (line[i] && line[i] != '\n')
	{
		if ((line[i] < 'a' || line[i] > 'f')
			&& (line[i] < 'A' || line[i] > 'F')
			&& (line[i] < '0' || line[i] > '9'))
			ft_error_col();
		i++;
	}
}

void	ft_free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free (line[i]);
		i++;
	}
	free (line);
}

void	ft_map_error(char *line)
{
	int		j;

	j = 0;
	if (line[0] == '+' || line[0] == '-')
	j++;
	while (line[j] && line[j] != ',')
	{
		if (line[j] == '\n')
			break ;
		if (line[j] > '9' || line[j] < '0')
			ft_error_num();
		j++;
	}
	if (line[j] == ',')
		ft_error_color(ft_strchr(line, ','));
}
