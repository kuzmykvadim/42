/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:02:29 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 01:05:37 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_pars_vect(t_vector *vect, char *pfile)
{
	pfile++;
	vect->x = ft_atoi(pfile);
	ft_pars_digit(&pfile);
	vect->y = ft_atoi(pfile);
	ft_pars_digit(&pfile);
	vect->z = ft_atoi(pfile);
}

void	ft_costyl(t_env *e)
{
	e->cam.mat = ft_matrix_cam(e->cam.rot);
}

void	ft_pars_digit(char **ptr)
{
	while (**ptr == '-' || ft_isdigit((int)**ptr))
	{
		(*ptr)++;
		if (!**ptr)
			puts("bad map");
	}
	while (**ptr != '-' && !(ft_isdigit((int)**ptr)))
	{
		(*ptr)++;
		if (!**ptr)
			puts("bad map");
	}
}

int		ft_obj_type(char *ptr)
{
	if (!(ft_strncmp(ptr, "SPHERE", 6)))
		return (SPHERE);
	else if (!(ft_strncmp(ptr, "CYLINDER", 8)))
		return (CYLINDER);
	else if (!(ft_strncmp(ptr, "CONE", 4)))
		return (CONE);
	else if (!(ft_strncmp(ptr, "PLANE", 5)))
		return (PLANE);
	return (0);
}

t_color	ft_get_color(char *ptr)
{
	t_color	color;

	color.r = ft_atoi(ptr);
	ft_pars_digit(&ptr);
	color.g = ft_atoi(ptr);
	ft_pars_digit(&ptr);
	color.b = ft_atoi(ptr);
	return (color);
}
