/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:24:34 by dmonjas-          #+#    #+#             */
/*   Updated: 2023/10/09 11:08:27 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include "mlx.h"
# include <errno.h>
# include <math.h>

# define HEIGTH 2000
# define WIDTH 3000

typedef struct window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_window;

typedef struct coor
{
	float	x;
	float	y;
	float	x_next;
	float	y_next;
	int		z;
	int		z_next;
	int		color;
	float	x_step;
	float	y_step;
}	t_coor;

typedef struct color
{
	int	r;
	int	gr;
	int	bl;
	int	rgb;
}	t_color;

typedef struct file
{
	int			width;
	int			heigth;
	int			**z;
	int			x;
	int			y;
	int			zoom;
	int			zoom_z;
	int			w;
	int			h;
	float		x_shift;
	float		y_shift;
	float		sen;
	float		cos;
	t_color		**color;
	t_window	*win;
	t_coor		*coor;
}	t_read;

void		ft_print(t_read *file);
void		ft_file(t_read *file, char *av);
void		ft_error_file(void);
void		my_mlx_pixel_put(t_read *file, int x, int y, int color);
void		ft_draw(t_read *file);
void		ft_window_control(t_window *window, t_read *file);
void		ft_bresenham(t_read *file, float x1, float y1);
void		ft_map_error(char *line, t_read *file);
void		ft_width_error(char *line, t_read *file);
void		ft_error_av(char *av);
char		*ft_strchr_fdf(const char *s, int c);
size_t		ft_strlen_fdf(const char *c);
int			ft_num(const char *s, char c);
int			ft_close(t_read *file);
int			ft_hex_int(char hex, char hex2);
float		absolut(float x);
float		max1(float x, float y);
t_read		*ft_init(t_read *window);
t_color		ft_color_lon(char *hex, t_color color);

#endif
