/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:17:45 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 00:29:34 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_vect_norm(t_vector vec)
{
	t_vector	res;
	double		len;

	len = sqrt(ft_vect_scale(vec, vec));
	len = 1 / len;
	res.x *= len;
	res.y *= len;
	res.z *= len;
	return (res);
}
