/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 16:57:09 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 13:36:16 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_shadow1(t_env *env, int h, double t, double len)
{
	while (++env->current < env->nb_obj)
	{
		h = 0;
		if (env->obj[env->current].type == SPHERE
				&& env->current != env->last)
			h = ft_sphere(env->obj[env->current], env->light.shadow, &t);
		else if (env->obj[env->current].type == CYLINDER
				&& env->current != env->last)
			h = ft_cylinder(env->obj[env->current], env->light.shadow, &t);
		else if (env->obj[env->current].type == CONE
				&& env->current != env->last)
			h = ft_cone(env->obj[env->current], env->light.shadow, &t);
		if (h && t > 0 && t < len)
			return (0);
	}
	return (1);
}

int		ft_shadow(t_env *env)
{
	int		h;
	double	t;
	double	len;

	t = 0;
	h = 0;
	env->current = -1;
	env->light.shadow.position = env->light.direct;
	env->light.shadow.direct = ft_vect_sub(env->light.position,
			env->light.shadow.position);
	len = ft_vect_len(env->light.shadow.direct);
	env->light.shadow.direct = ft_vect_norm(env->light.shadow.direct);
	return (ft_shadow1(env, h, t, len));
}

double	ft_light(t_env *e)
{
	t_vector	direct;
	double		result;

	e->light.direct = ft_vect_add(e->ray.position,
			ft_vect_mult_scal(e->ray.direct, e->tmin));
	direct = ft_vect_sub(e->light.direct, e->light.position);
	direct = ft_vect_norm(direct);
	e->light.norm = ft_vect_norm(ft_vect_sub(e->light.direct,
				e->obj[e->last].center));
	e->light.norm = ft_neg_vect(e->light.norm);
	if (e->obj[e->last].rot.flag)
		e->light.norm = ft_rotate(e->light.norm, e->obj[e->last].rot);
	else if (e->obj[e->last].type == PLANE)
		e->light.norm = ft_vect_new(0, 0, A(e->ray.direct.z));
	result = ft_vect_scale(direct, e->light.norm);
	if (result < 0.2)
		result = 0.2;
	if (e->shd)
	{
		if (!ft_shadow(e))
			result = 0.14;
	}
	if (result > 1)
		result = 1;
	return (result);
}
