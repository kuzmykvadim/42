/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:55:17 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 13:44:13 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# define RAY_RANGE 2000
# define A(a) (a < 0 ? -1 : 1)
# define W_SIZE_W 900
# define W_SIZE_H 900
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
# define ROT_Z_UP 83
# define ROT_Z_DN 92
# define ENTER 36
# define SHIFT 258
# define SPACE 49
# define SPHERE 1
# define CYLINDER 2
# define CONE 3
# define PLANE 4

typedef struct		s_rotate
{
	double			j;
	double			p;
	double			y;
}					t_rotate;

typedef struct		s_matrix
{
	int				flag;
	t_vector		m1;
	t_vector		m2;
	t_vector		m3;
}					t_matrix;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_object
{
	double			radius;
	t_vector		center;
	t_color			color;
	t_vector		norm;
	t_matrix		inv;
	t_matrix		rot;
	int				type;
}					t_object;

typedef struct		s_ray
{
	t_vector		direct;
	t_vector		position;
}					t_ray;

typedef struct		s_light
{
	t_vector		direct;
	t_vector		norm;
	t_vector		position;
	t_ray			shadow;
}					t_light;

typedef struct		s_cam
{
	t_vector		pos;
	t_rotate		rot;
	t_matrix		mat;
}					t_cam;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	char			*pix;
	int				s_line;
	int				i;
	t_vector		vecdir;
	double			tmin;
	double			fieldofview;
	t_object		*obj;
	t_light			light;
	t_cam			cam;
	t_ray			ray;
	int				nb_obj;
	int				redraw;
	int				last;
	int				size;
	int				current;
	int				hit;
	int				shd;
	int				fd;
}					t_env;

void				create_window(char *header, int wegt, int hegt, t_env *e);
void				put_img(t_env *e);
void				put_pix_img(t_env *e, int x, int y, t_color c);
void				ft_init(t_env *e, char *file);
void				ft_init(t_env *e, char *file);
void				ft_parsing(t_env *e);
char				*ft_read_file(t_env *e);
void				ft_pars_digit(char **ptr);
void				ft_init_lgt_and_cam(t_env *e, char *file);
void				ft_pars_vect(t_vector *vect, char *pfile);
void				ft_init_objects(t_env *e, char *file);
void				ft_multiobj(t_env *e, t_object add);
int					ft_obj_type(char *ptr);
t_color				ft_get_color(char *ptr);
void				ft_change_obj(t_object *obj, char *prs);
void				ft_ray_trace(t_env *e);
double				ft_light(t_env *e);
int					key_hook_init(int key, t_env *e);
int					ft_sphere(t_object obj, t_ray ray, double *t);
int					ft_math_sphere(t_object obj,
		t_ray ray, double *t1, double *t2);
int					ft_cone(t_object obj, t_ray ray, double *t);
int					ft_math_cone(t_object obj,
		t_ray ray, double *t1, double *t2);
int					ft_cylinder(t_object obj, t_ray ray, double *t);
int					ft_math_cylinder(t_object obj, t_ray ray,
		double *t1, double *t2);
int					ft_plane(t_object obj, t_ray ray, double *t);
t_matrix			ft_matrix_cam(t_rotate rot);
t_matrix			ft_matr_multipl(t_matrix m1, t_matrix m2);
t_matrix			ft_matrix_init(t_matrix mat);
t_matrix			ft_rotate_z(double t);
t_matrix			ft_rotate_y(double t);
t_matrix			ft_rotate_x(double t);
t_vector			ft_rotate_cam(t_vector vec, t_matrix mat);
t_ray				ft_rotate_ray(t_ray ray, t_matrix mat);
t_vector			ft_rotate(t_vector vec, t_matrix mat);
void				ft_costyl(t_env *e);

#endif
