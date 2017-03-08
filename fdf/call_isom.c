/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_isom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:00:05 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:08:27 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_env *e, double s)
{
	t_matrix *mtr1;

	mtr1 = ft_zoom_data(s);
	ft_mtr_to_map(mtr1, e);
	free(mtr1);
}

void	ft_stretch(t_env *e, double s, char type)
{
	t_matrix *mtr1;

	if (type == 'x')
		mtr1 = ft_stretch_x(s);
	else
		mtr1 = ft_stretch_y(s);
	ft_mtr_to_map(mtr1, e);
	free(mtr1);
}

void	ft_move(t_env *e, double x, double y, double z)
{
	t_matrix *mtr1;

	mtr1 = ft_mtr_move(x, y, z);
	ft_mtr_to_map(mtr1, e);
	put_to_center(e);
	free(mtr1);
}

void	ft_mtr_to_map(t_matrix *mtr, t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e->map->len)
	{
		x = 0;
		while (x < e->map->lines[y]->len)
		{
			isometric(e->map->lines[y]->pixels[x], mtr, e);
			x++;
		}
		y++;
	}
}

void	isometric(t_pixel *pt, t_matrix *mtr, t_env *e)
{
	double	x1;
	double	y1;
	double	z1;

	pt->x -= e->center.x;
	pt->y -= e->center.y;
	x1 = pt->x * mtr->m1 + pt->y * mtr->m2 + pt->z * mtr->m3 + pt->s * mtr->m4;
	y1 = pt->x * mtr->m5 + pt->y * mtr->m6 + pt->z * mtr->m7 + pt->s * mtr->m8;
	z1 = pt->x * mtr->m9 + pt->y * mtr->m10 + pt->z
		* mtr->m11 + pt->s * mtr->m12;
	pt->x = x1;
	pt->y = y1;
	pt->z = z1;
	pt->x += e->center.x;
	pt->y += e->center.y;
}
