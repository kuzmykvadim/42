/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 19:57:02 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 02:14:43 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	ft_matrix_init(t_matrix mat)
{
	t_matrix	res;

	res.m1 = ft_vect_new((mat.m2.y * mat.m3.z)
			- (mat.m2.z * mat.m3.y), (mat.m1.z * mat.m3.y)
			- (mat.m1.y * mat.m3.z), (mat.m1.y * mat.m2.z)
			- (mat.m1.z * mat.m2.y));
	res.m2 = ft_vect_new((mat.m2.z * mat.m3.x)
			- (mat.m2.x * mat.m3.z), (mat.m1.x * mat.m3.z)
			- (mat.m1.z * mat.m3.x), (mat.m1.z * mat.m2.x)
			- (mat.m1.x * mat.m2.z));
	res.m3 = ft_vect_new((mat.m2.x * mat.m3.y)
			- (mat.m2.y * mat.m3.x), (mat.m1.y * mat.m3.x)
			- (mat.m1.x * mat.m3.y), (mat.m1.x * mat.m2.y)
			- (mat.m1.y * mat.m2.x));
	res.flag = 1;
	return (res);
}

t_matrix	ft_matr_multipl(t_matrix mt1, t_matrix mt2)
{
	t_matrix	res;
	double		a;
	double		b;
	double		c;

	a = (mt1.m1.x * mt2.m1.x) + (mt1.m1.y * mt2.m2.x) + (mt1.m1.z * mt2.m3.x);
	b = (mt1.m1.x * mt2.m1.y) + (mt1.m1.y * mt2.m2.y) + (mt1.m1.z * mt2.m3.y);
	c = (mt1.m1.x * mt2.m1.z) + (mt1.m1.y * mt2.m2.z) + (mt1.m1.z * mt2.m3.z);
	res.m1 = ft_vect_new(a, b, c);
	a = (mt1.m2.x * mt2.m1.x) + (mt1.m2.y * mt2.m2.x) + (mt1.m2.z * mt2.m3.x);
	b = (mt1.m2.x * mt2.m1.y) + (mt1.m2.y * mt2.m2.y) + (mt1.m2.z * mt2.m3.y);
	c = (mt1.m2.x * mt2.m1.z) + (mt1.m2.y * mt2.m2.z) + (mt1.m2.z * mt2.m3.z);
	res.m2 = ft_vect_new(a, b, c);
	a = (mt1.m3.x * mt2.m1.x) + (mt1.m3.y * mt2.m2.x) + (mt1.m3.z * mt2.m3.x);
	b = (mt1.m3.x * mt2.m1.y) + (mt1.m3.y * mt2.m2.y) + (mt1.m3.z * mt2.m3.y);
	c = (mt1.m3.x * mt2.m1.z) + (mt1.m3.y * mt2.m2.z) + (mt1.m3.z * mt2.m3.z);
	res.m3 = ft_vect_new(a, b, c);
	res.flag = 1;
	return (res);
}

t_vector	ft_rotate_cam(t_vector vec, t_matrix mat)
{
	t_vector	res;

	res.x = mat.m1.x + vec.x * mat.m1.y + vec.y * mat.m1.z;
	res.y = mat.m2.x + vec.x * mat.m2.y + vec.y * mat.m2.z;
	res.z = mat.m3.x + vec.x * mat.m3.y + vec.y * mat.m3.z;
	return (res);
}

t_matrix	ft_matrix_cam(t_rotate rot)
{
	t_matrix	mat;

	mat.m1 = ft_vect_new(-cos(rot.p) * sin(rot.j), cos(rot.j),
			sin(rot.p) * sin(rot.j));
	mat.m2 = ft_vect_new(sin(rot.p), 0, cos(rot.p));
	mat.m3 = ft_vect_new(cos(rot.p) * cos(rot.j), sin(rot.j),
			-sin(rot.p) * cos(rot.j));
	mat.flag = 1;
	return (mat);
}
