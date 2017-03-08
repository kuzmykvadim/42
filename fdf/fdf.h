/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:15:07 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:45:22 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define W_SIZE_W 2000
# define W_SIZE_H 1000
# define GO_UP -100
# define GO_DOWN 100
# define GO_LEFT -100
# define GO_RIGHT 100
# define ZOOM_PLUS 1.1
# define ZOOM_MINUS 0.9
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define M mlx_string_put
# define STEP_X 20
# define STEP_Y 20
# define ROT_X_UP 91
# define ROT_X_DN 84
# define ROT_Y_UP 86
# define ROT_Y_DN 88
# define ROT_Z_UP 83
# define ROT_Z_DN 92
# define STR_UP 1.1
# define STR_DN 0.9
# define X_UP 15 * -M_PI / 180
# define X_DOWN 15 * M_PI / 180
# define Y_UP 15 * -M_PI / 180
# define Y_DOWN 15 * M_PI / 180
# define Z_UP 15 * -M_PI / 180
# define Z_DOWN 15 * M_PI / 180
# define STRETCH_X_UP 106
# define STRETCH_X_DN 64
# define STRETCH_Y_UP 79
# define STRETCH_Y_DN 80
# define ZOOM_Z 1.7

typedef struct	s_pixel
{
	double		x;
	double		y;
	double		z;
	double		s;
	int			z_color;
}				t_pixel;

typedef struct	s_line
{
	t_pixel		**pixels;
	int			len;
}				t_line;

typedef struct	s_map
{
	t_line		**lines;
	int			len;
}				t_map;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		*map;
	char		*pix;
	int			bpp;
	int			s_line;
	int			i;
	t_pixel		center;
	double		alfa;
	double		beta;
	double		gama;
}				t_env;

typedef struct	s_matrix
{
	double		m1;
	double		m2;
	double		m3;
	double		m4;
	double		m5;
	double		m6;
	double		m7;
	double		m8;
	double		m9;
	double		m10;
	double		m11;
	double		m12;
	double		m13;
	double		m14;
	double		m15;
	double		m16;
}				t_matrix;

t_map			*ft_parse_map(char **argv, int fd);
int				ft_map_line(char *map);
int				ft_pixels(char *line, int nb_line, t_pixel ***arr_pixel);
void			put_map(t_env *e);
void			put_line(t_pixel point1, t_pixel point2, t_env *e);
void			put_pix_img(t_env *e, int x, int y, int color);
void			ft_module(t_pixel *point1, t_pixel *point2, double *arr);
void			isometric(t_pixel *pt, t_matrix *mtr, t_env *e);
void			ft_mtr_to_map(t_matrix *mtr, t_env *e);
t_matrix		*ft_mtr_move(double x1, double y1, double z1);
t_matrix		*ft_zoom_data(double s);
void			ft_move(t_env *e, double x, double y, double z);
void			ft_zoom(t_env *e, double s);
int				key_hook(int key, t_env *e);
void			create_window(char *header, int weight, int height, t_env *e);
void			put_img(t_env *e);
void			ft_present_map(t_env *e);
void			put_to_center(t_env *e);
void			ft_rotate(t_env *e, double beta, char type);
t_matrix		*rotation_z(double beta);
t_matrix		*rotation_y(double beta);
t_matrix		*rotation_x(double beta);
int				ft_color(t_pixel *pt1, t_pixel *pt2);
void			ft_stretch(t_env *e, double s, char type);
void			ft_menu(t_env *e);
t_matrix		*ft_stretch_x(double s);
t_matrix		*ft_stretch_y(double s);

#endif
