/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:07:05 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/10/20 16:07:08 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dda_algorithm(t_env *e)
{
	while (e->object.hit == 0)
	{
		if (e->object.side_dist.x < e->object.side_dist.y)
		{
			e->object.side_dist.x += e->object.delta_dist.x;
			e->object.map.x += e->object.step.x;
			e->object.hit_side_dist = 0;
		}
		else
		{
			e->object.side_dist.y += e->object.delta_dist.y;
			e->object.map.y += e->object.step.y;
			e->object.hit_side_dist = 1;
		}
		if ((e->map[(int)e->object.map.x][(int)e->object.map.y]) > 0)
		{
			e->object.hit = 1;
			if (e->object.hit_side_dist == 0)
				e->object.dist = (e->object.map.x - e->object.ray_pos.x +
					(1 - e->object.step.x) / 2) / e->object.ray_dir.x;
			else
				e->object.dist = (e->object.map.y - e->object.ray_pos.y +
					(1 - e->object.step.y) / 2) / e->object.ray_dir.y;
		}
	}
}

void	calculate_step(t_env *e)
{
	if (e->object.ray_dir.x < 0)
	{
		e->object.step.x = -1;
		e->object.side_dist.x = (e->object.ray_pos.x -
			(int)e->object.ray_pos.x) * e->object.delta_dist.x;
	}
	else
	{
		e->object.step.x = 1;
		e->object.side_dist.x = ((int)e->object.ray_pos.x + 1
			- e->object.ray_pos.x) * e->object.delta_dist.x;
	}
	if (e->object.ray_dir.y < 0)
	{
		e->object.step.y = -1;
		e->object.side_dist.y = (e->object.ray_pos.y
			- (int)e->object.ray_pos.y) * e->object.delta_dist.y;
	}
	else
	{
		e->object.step.y = 1;
		e->object.side_dist.y = ((int)e->object.ray_pos.y + 1
			- e->object.ray_pos.y) * e->object.delta_dist.y;
	}
}

void	ray_and_dir(t_env *e, int x)
{
	e->object.map.x = (int)e->object.ray_pos.x;
	e->object.map.y = (int)e->object.ray_pos.y;
	e->object.cam = 2 * x / (double)e->win_width - 1;
	e->object.ray_dir.x = e->object.play_dir.x + e->object.plane.x
		* e->object.cam;
	e->object.ray_dir.y = e->object.play_dir.y + e->object.plane.y
		* e->object.cam;
	e->object.delta_dist.x = sqrt(1 + (e->object.ray_dir.y
		* e->object.ray_dir.y) / (e->object.ray_dir.x *
		e->object.ray_dir.x));
	e->object.delta_dist.y = sqrt(1 + (e->object.ray_dir.x
		* e->object.ray_dir.x) / (e->object.ray_dir.y *
		e->object.ray_dir.y));
	e->object.hit = 0;
	e->object.dist = -1;
	e->object.hit_side_dist = -1;
}

void	ft_raycasting(t_env *e)
{
	int		x;

	x = 0;
	e->object.ray_pos.x = e->object.play_pos.x;
	e->object.ray_pos.y = e->object.play_pos.y;
	while (x < e->win_width)
	{
		ray_and_dir(e, x);
		calculate_step(e);
		dda_algorithm(e);
		low_and_hight_pix(e, x);
		x += e->iter1;
	}
}
