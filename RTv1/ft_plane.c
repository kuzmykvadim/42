/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:58:35 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 00:04:42 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_plane(t_object obj, t_ray ray, double *t)
{
	double		t1;
	double		res;
	t_vector	vect;

	if (obj.rot.flag)
	{
		ray.position = ft_rotate(ray.position, obj.inv);
		ray.direct = ft_rotate(ray.direct, obj.inv);
	}
	t1 = ft_vect_scale(ray.direct, obj.norm);
	if (t1)
	{
		vect = ft_vect_sub(obj.center, ray.position);
		res = ft_vect_scale(vect, obj.norm);
		res /= t1;
		if (res > 0)
		{
			*t = res;
			return (1);
		}
		return (0);
	}
	return (0);
}
