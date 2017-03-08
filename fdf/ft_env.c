/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:58:17 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:10:51 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_to_center(t_env *e)
{
	t_pixel	ct;
	int		x1;
	int		y1;

	ct = e->center;
	y1 = e->map->len;
	x1 = e->map->lines[y1 - 1]->len;
	ct.x = ((e->map->lines[y1 - 1]->pixels[x1 - 1]->x)
			+ (e->map->lines[0]->pixels[0]->x)) / 2;
	ct.y = ((e->map->lines[y1 - 1]->pixels[x1 - 1]->y)
			+ (e->map->lines[0]->pixels[0]->y)) / 2;
	e->center = ct;
}

void	create_window(char *header, int weight, int height, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, weight, height, header);
}

void	put_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, W_SIZE_W, W_SIZE_H);
	e->pix = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->i));
	put_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_menu(e);
	mlx_destroy_image(e->mlx, e->img);
}

void	ft_present_map(t_env *e)
{
	int		width;
	int		height;
	double	s;

	width = (W_SIZE_W) / 2;
	height = (W_SIZE_H) / 2;
	e->center.x == 0 ? e->center.x = 10 : e->center.x;
	s = (width - 500) / (e->center.x);
	ft_move(e, -e->center.x + width, -e->center.y + height, 0);
	ft_rotate(e, -50 * M_PI / 180, 'x');
	ft_rotate(e, -30 * M_PI / 180, 'y');
	ft_rotate(e, -15 * M_PI / 180, 'z');
	ft_zoom(e, s);
}

int		ft_color(t_pixel *pt1, t_pixel *pt2)
{
	int		color;
	int		z;

	if (pt2->z_color > pt1->z_color)
		z = pt2->z_color;
	else
		z = pt1->z_color;
	if (z < 0)
		color = 0x80FFBBFF;
	else if (z >= 0 && z < 5)
		color = 0xEDBBFF;
	else if (z >= 5 && z < 10)
		color = 0x60D2D2FF;
	else if (z >= 10 && z < 20)
		color = 0xBBBBFF;
	else if (z >= 20 && z < 60)
		color = 0x9FBBFF;
	else if (z >= 60)
		color = 0x7ABBFF;
	else
		color = 0;
	return (color);
}
