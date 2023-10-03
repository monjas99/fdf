/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:57:59 by david             #+#    #+#             */
/*   Updated: 2023/10/02 12:49:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_num(const char *s, char c)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && j == 0 && s[i] != '\n')
		{
			j = 1;
			count++;
		}
		else if (s[i] == c)
			j = 0;
		i++;
	}
	return (count);
}

char	*ft_strchr_fdf(const char *s, int c)
{
	int	i;
	int	j;

	j = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	while (i <= j)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i + 3]);
		}
		i++;
	}
	return (0);
}

float	max1(float x, float y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

float	absolut(float x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}

size_t	ft_strlen_fdf(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
	{
		if (c[i] == '\n')
			break ;
		i++;
	}
	return (i);
}
