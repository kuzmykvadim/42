/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_mult_scal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 17:13:11 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/05/10 21:51:18 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_vect_mult_scal(t_vector a, double x)
{
	t_vector vt;

	vt.x = a.x * x;
	vt.y = a.y * x;
	vt.z = a.z * x;
	return (vt);
}
