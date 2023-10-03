/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:28:22 by david             #+#    #+#             */
/*   Updated: 2023/10/03 09:01:06 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	ft_color_lon(char *hex, t_color color)
{
	color.gr = 0;
	color.r = 0;
	if (ft_strlen(hex) == 2)
		color.bl = ft_hex_int(hex[0], hex[1]);
	else if (ft_strlen(hex) == 4)
	{
		color.gr = ft_hex_int(hex[0], hex[1]);
		color.bl = ft_hex_int(hex[2], hex[3]);
	}
	else if (ft_strlen(hex) == 6)
	{
		color.r = ft_hex_int(hex[0], hex[1]);
		color.gr = ft_hex_int(hex[2], hex[3]);
		color.bl = ft_hex_int(hex[4], hex[5]);
	}
	color.rgb = ((color.r << 16) | (color.gr << 8) | color.bl);
	return (color);
}

int	ft_hex_int(char hex, char hex2)
{
	int		rgb;
	char	p[2];
	int		i;
	int		lon;

	i = 0;
	rgb = 0;
	p[0] = hex;
	p[1] = hex2;
	lon = ft_strlen(p);
	while (i < 2)
	{
		rgb <<= 4;
		if (p[i] >= '0' && p[i] <= '9')
			rgb |= (p[i] - '0');
		else if (p[i] >= 'a' && p[i] <= 'f')
			rgb |= (p[i] - 'a' + 10);
		else if (p[i] >= 'A' && p[i] <= 'F')
			rgb |= (p[i] - 'A' + 10);
		i++;
	}
	return (rgb);
}
