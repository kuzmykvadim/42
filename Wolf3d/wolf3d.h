/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:55:17 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/10/17 16:38:38 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# define W_SIZE_W 1000
# define W_SIZE_H 660
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MINUS 24
# define PLUS 27
# define ENTER 36
# define SHIFT 258
# define SPACE 49
# define W 13
# define S 1
# define A 0
# define D 2
# define Q 12
# define COLOR1 0x53c68c
# define COLOR2 0x990099
# define COLOR3 0xff66cc
# define COLOR4 0x33ff33
# define SKY 0x146c87
# define GROUND 0x404040

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_position
{
	double			x;
	double			y;
}					t_position;

typedef struct		s_object
{
	t_position		play_pos;
	t_position		play_dir;
	t_position		plane;
	int				i;
	double			step_move;
	double			step_rotate;
	t_position		ray_pos;
	t_position		ray_dir;
	t_position		map;
	t_position		side_dist;
	t_position		delta_dist;
	t_position		step;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side_dist;
}					t_object;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img2;
	int				bpp;
	char			*pix;
	int				s_line;
	int				fd;
	int				i;
	int				contl_nmb;
	int				start;
	int				size_h;
	int				size_w;
	t_object		object;
	int				smoke_off;
	int				iter1;
	int				win_width;
	int				win_height;
	int				map_width;
	int				map_height;
	int				**map;
	unsigned int	color1;
	unsigned int	color2;
	unsigned int	color3;
	unsigned int	color4;
	unsigned int	sky_col;
	unsigned int	ground_col;
	int				start_x;
	int				start_y;
}					t_env;

void				create_window(char *header, int wegt, int hegt, t_env *e);
int					put_img(t_env *e);
int					put_start_screen(t_env *e);
int					ft_map_init(t_env *e, char *file);
void				ft_parsing(t_env *e);
int					ft_read_file(t_env *e);
void				ft_draw(t_env *e);
void				ft_raycasting(t_env *e);
int					loop_hook(t_env *e);
int					key_hook_init(int key, t_env *e);
void				ft_parse_error(char *str);
int					get_color(t_env *e);
unsigned int		ft_smoke(unsigned int c, double dist, int area);
void				put_pixel_img(t_env *e, int x, int y, unsigned int color);
void				low_and_hight_pix(t_env *e, int x);
void				draw_line_with_smoke(t_env *e, int x, int start, int end);
void				draw_line(t_env *e, int x, int start, int end);
void				print_map(t_env *e);
int					ft_write_map(char **line, int i, t_env *e);
int					ft_parse_control(int fd, t_env *e);
void				ft_lightning(t_env *e);
int					esc_key_funct(int key);

#endif
