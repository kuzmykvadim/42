/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:13:51 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/03 23:44:23 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_math_cone(t_object obj, t_ray ray, double *t1, double *t2)
{
	t_vector	v;
	double		a;
	double		b;
	double		c;
	double		discr;

	if (obj.rot.flag)
		ray = ft_rotate_ray(ray, obj.inv);
	v = ft_vect_sub(ray.position, obj.center);
	a = (ray.direct.x * ray.direct.x + ray.direct.z * ray.direct.z)
		- (obj.radius * ray.direct.y * ray.direct.y);
	b = 2 * ((ray.direct.x * v.x + ray.direct.z * v.z)
			- (obj.radius * ray.direct.y * v.y));
	c = (v.x * v.x + v.z * v.z) - (obj.radius * v.y * v.y);
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (0);
	else
	{
		*t1 = (-b - sqrt(discr)) / (2 * a);
		*t2 = (-b + sqrt(discr)) / (2 * a);
		return (1);
	}
}

int		ft_cone(t_object obj, t_ray ray, double *t)
{
	double	t1;
	double	t2;

	if (ft_math_cone(obj, ray, &t1, &t2))
	{
		if (t1 < 0.001f && t2 < 0.001f)
			return (0);
		else if (t1 < 0 && t2 >= 0)
			*t = t2;
		else if (t2 < 0 && t1 >= 0)
			*t = t1;
		else
			*t = (t1 < t2) ? t1 : t2;
		return (1);
	}
	return (0);
}
