/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:41:16 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 01:07:32 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	ft_rotate_x(double t)
{
	t_matrix	mat;

	mat.flag = 1;
	mat.m1 = ft_vect_new(1, 0, 0);
	mat.m2 = ft_vect_new(0, cos(t), -sin(t));
	mat.m3 = ft_vect_new(0, sin(t), cos(t));
	return (mat);
}

t_matrix	ft_rotate_y(double t)
{
	t_matrix	mat;

	mat.flag = 1;
	mat.m1 = ft_vect_new(cos(t), 0, sin(t));
	mat.m2 = ft_vect_new(0, 1, 0);
	mat.m3 = ft_vect_new(-sin(t), 0, cos(t));
	return (mat);
}

t_matrix	ft_rotate_z(double t)
{
	t_matrix	mat;

	mat.flag = 1;
	mat.m1 = ft_vect_new(cos(t), -sin(t), 0);
	mat.m2 = ft_vect_new(sin(t), cos(t), 0);
	mat.m3 = ft_vect_new(0, 0, 1);
	return (mat);
}

t_ray		ft_rotate_ray(t_ray ray, t_matrix mat)
{
	t_ray	res;

	res.direct = ft_rotate(ray.direct, mat);
	res.position = ft_rotate(ray.position, mat);
	return (res);
}

t_vector	ft_rotate(t_vector vec, t_matrix mat)
{
	t_vector	res;

	res.x = mat.m1.x * vec.x + mat.m1.y * vec.y + mat.m1.z * vec.z;
	res.y = mat.m2.x * vec.x + mat.m2.y * vec.y + mat.m2.z * vec.z;
	res.z = mat.m3.x * vec.x + mat.m3.y * vec.y + mat.m3.z * vec.z;
	return (res);
}
