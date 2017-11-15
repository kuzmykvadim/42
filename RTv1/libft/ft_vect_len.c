/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:14:36 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 13:36:37 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_vect_len(t_vector vec)
{
	t_vector	tmp;
	double		res;

	tmp = vec;
	res = sqrt(ft_vect_scale(tmp, tmp));
	return (res);
}
