/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:55:25 by david             #+#    #+#             */
/*   Updated: 2023/10/16 12:58:49 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_file(void)
{
	perror ("");
	exit (1);
}

int	ft_close(void)
{
	exit (0);
}

void	ft_width_error(char *line, t_read *file)
{
	free (line);
	free (file);
	ft_printf("Error line len\n");
	exit (1);
}

void	ft_error_av(char *av)
{
	int	j;

	j = ft_strlen(av);
	j--;
	if (av[j] != 'f')
		ft_error_file();
		j--;
	if (av[j] != 'd')
		ft_error_file();
		j--;
	if (av[j] != 'f')
		ft_error_file();
		j--;
	if (av[j] != '.')
		ft_error_file();
}
