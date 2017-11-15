/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:10:02 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 00:07:07 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_obj_list(t_env *e)
{
	double	j;

	j = RAY_RANGE;
	while (++e->current < e->nb_obj)
	{
		if (e->obj[e->current].type == SPHERE)
			ft_sphere(e->obj[e->current], e->ray, &j);
		if (e->obj[e->current].type == CYLINDER)
			ft_cylinder(e->obj[e->current], e->ray, &j);
		if (e->obj[e->current].type == CONE)
			ft_cone(e->obj[e->current], e->ray, &j);
		if (e->obj[e->current].type == PLANE)
			ft_plane(e->obj[e->current], e->ray, &j);
		if (e->tmin > j)
		{
			e->hit = 1;
			e->tmin = j;
			e->last = e->current;
		}
	}
}

void	ft_ray_intersect(t_env *e, int x, int y)
{
	e->hit = 0;
	e->current = -1;
	ft_obj_list(e);
	if (e->hit)
		put_pix_img(e, x, y, e->obj[e->last].color);
}

void	ft_ray(t_env *e, int x, int y)
{
	t_vector vect;

	e->ray.position = e->cam.pos;
	vect.x = (x + 0.1) / W_SIZE_W;
	vect.y = (y + 0.1) / W_SIZE_H;
	vect.x = (2 * vect.x) - 1;
	vect.y = 1 - (2 * vect.y);
	vect.x *= (W_SIZE_W / (double)W_SIZE_H) *
		tan((e->fieldofview / 2) * M_PI / 180);
	vect.y *= tan((e->fieldofview / 2) * M_PI / 180);
	vect.z = 1;
	e->vecdir = vect;
	if (e->cam.mat.flag)
		e->ray.direct = ft_rotate_cam(vect, e->cam.mat);
	else
		e->ray.direct = vect;
}

void	ft_ray_trace(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < W_SIZE_H)
	{
		x = -1;
		while (++x < W_SIZE_W)
		{
			e->tmin = RAY_RANGE;
			ft_ray(e, x, y);
			ft_ray_intersect(e, x, y);
		}
	}
}
