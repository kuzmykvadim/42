/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:05:59 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 00:10:11 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_math_sphere(t_object obj, t_ray ray, double *t1, double *t2)
{
	t_vector	v;
	double		a;
	double		b;
	double		c;
	double		disc;

	v = ft_vect_sub(ray.position, obj.center);
	a = ft_vect_scale(ray.direct, ray.direct);
	b = 2.0 * ft_vect_scale(ray.direct, v);
	c = ft_vect_scale(v, v) - obj.radius;
	disc = (b * b) - (4.0 * a * c);
	if (disc < 0.0)
		return (0);
	else
	{
		*t1 = (-b - sqrt(disc)) / (2.0 * a);
		*t2 = (-b + sqrt(disc)) / (2.0 * a);
		return (1);
	}
}

int		ft_sphere(t_object obj, t_ray ray, double *t)
{
	double	t1;
	double	t2;

	if (ft_math_sphere(obj, ray, &t1, &t2))
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
