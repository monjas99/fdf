/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:44:59 by david             #+#    #+#             */
/*   Updated: 2023/10/16 12:28:16 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	ft_get_color(char *line)
{
	t_color	color;

	color.rgb = 0;
	if (ft_strchr_fdf(line, ',') != 0)
		color = ft_color_lon(ft_strchr_fdf(line, ','), color);
	else
		color.rgb = 0xFFFFFF;
	return (color);
}

static int	ft_get_heigth(char *av, t_read *file)
{
	int		heigth;
	int		fd;
	char	*line;

	heigth = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error_file();
	line = get_next_line(fd);
	if (line[0] == '\n')
		ft_width_error(line, file);
	while (line)
	{
		free (line);
		heigth++;
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (heigth);
}

static int	ft_get_width(char *av, t_read *file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error_file();
	line = get_next_line(fd);
	width = ft_num(line, ' ');
	free (line);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_num(line, ' ') != width)
			ft_width_error(line, file);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
	return (width);
}

static void	ft_get_z(t_read *file, int i, int fd)
{
	char	*gn;
	char	**line;
	int		j;

	line = NULL;
	gn = get_next_line(fd);
	i = 0;
	while (gn)
	{
		j = -1;
		while (++j <= file->width - 1)
		{
			line = ft_split(gn, ' ');
			ft_map_error(line[j]);
			file->z[i][j] = ft_atoi(line[j]);
			file->color[i][j] = ft_get_color(line[j]);
			ft_free_line (line);
		}
		i++;
		free (gn);
		gn = get_next_line(fd);
	}
	free (gn);
	close(fd);
}

void	ft_file(t_read *file, char *av)
{
	int	i;
	int	fd;

	i = -1;
	file->heigth = ft_get_heigth(av, file);
	file->width = ft_get_width(av, file);
	file->z = malloc(sizeof(int *) * (file->heigth + 1));
	if (!file->z)
		return ;
	file->color = malloc(sizeof(t_color *) * (file->heigth + 1));
	if (!file->color)
		return ;
	while (++i <= file->heigth)
	{
		file->z[i] = malloc(sizeof(int) * (file->width + 1));
		if (!file->z[i])
			return ;
		file->color[i] = malloc(sizeof(t_color) * (file->width + 1));
		if (!file->color[i])
			return ;
	}
	fd = open (av, O_RDONLY);
	if (fd < 1)
		ft_error_file();
	ft_get_z(file, i, fd);
}
