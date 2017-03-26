/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:15:07 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/26 11:35:37 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define W_SIZE_W 1000
# define W_SIZE_H 1000
# define ESC 53
# define DELETE 117
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_R_UP 4
# define MOUSE_R_DN 5
# define ZOOM_PL 69
# define ZOOM_MN 78
# define ROT_X_UP 91
# define ROT_X_DN 84
# define ROT_Y_UP 86
# define ROT_Y_DN 88
# define ENTER 36
# define SHIFT 258
# define SPACE 49
# define ITER_PLUS 67
# define ITER_MINUS 75
# define ITERATIONS 50
# define ZOOM 3
# define MANDELBROT 3
# define TRICORN 2
# define JULIA 1
# define BURNING_SHIP 4
# define NEWTON 5
# define M 46
# define N 45
# define B 11
# define J 38
# define T 17
# define COLOR_1 18
# define COLOR_2 19
# define COLOR_3 20
# define COLOR_4 21
# define ML mlx_string_put

typedef struct	s_pixel
{
	double		x;
	double		y;
}				t_pixel;

typedef struct	s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	double		phase;
	double		center;
	double		width;
	double		freq;
}				t_color;

typedef struct	s_fractal
{
	t_complex	c;
	t_complex	z;
	t_complex	old;
	t_pixel		pt1;
	t_pixel		pt2;
	t_pixel		image;
	t_pixel		real;
	double		m_iter;
	double		zoom;
	double		x;
	double		y;
	double		tmp;
	double		i;
}				t_fractal;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*win1;
	void		*img;
	int			bpp;
	char		*pix;
	int			s_line;
	int			i;
	t_fractal	*julia;
	t_fractal	*mandelbrot;
	t_fractal	*tricorn;
	t_fractal	*burn_ship;
	t_fractal	*newton;
	int			fractal_type;
	int			colorscheme;
}				t_env;

void			create_window(char *header, int weight, int height, t_env *e);
void			put_img(t_env *e);
void			put_pix_img(t_env *e, int x, int y, t_color *c);
void			put_julia(t_env *e, t_fractal *ftl);
void			put_mandelbrot(t_env *e, t_fractal *ftl);
void			put_tricorn(t_env *e, t_fractal *f);
void			put_burn_ship(t_env *e, t_fractal *ftl);
void			put_newton(t_env *e, t_fractal *ftl);
void			fractal_create(t_env *e);
void			julia(t_fractal *ftl);
void			mandelbrot(t_fractal *ftl);
void			newton(t_fractal *ftl);
void			tricorn(t_fractal *ftl);
void			burn_ship(t_fractal *ftl);
void			freq_color(t_env *e, t_pixel v, double i, double m_iter);
int				key_hook_init(int key, t_env *e);
void			key_h_env(int key, t_env *e);
void			key_h_zoom(int key, t_fractal *ftl);
void			key_h_reload(int key, t_env *e);
int				expose_hook(t_env *e);
void			put_fractal(t_env *e, t_fractal *ftl);
int				mouse_hook_init(int key, int x, int y, t_env *e);
void			mouse_hook(int key, int x, int y, t_fractal *f);
void			key_h_color(int key, t_env *e);
void			calc_hook(int key, t_fractal *ftl);
void			key_chang_ftl(int key, t_env *e);
void			key_h_mv_and_iter(int key, t_fractal *ftl);
int				motion_hook(int x, int y, t_env *e);
void			ft_menu(t_env *e);
int				menu_key_funct(int key, t_env *e);
#endif
