/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:19:13 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:11:50 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*ft_mtr_move(double x1, double y1, double z1)
{
	t_matrix	*mtr;

	mtr = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	mtr->m4 = x1;
	mtr->m8 = y1;
	mtr->m12 = z1;
	mtr->m1 = 1;
	mtr->m6 = 1;
	mtr->m11 = 1;
	mtr->m16 = 1;
	return (mtr);
}

t_matrix	*ft_zoom_data(double s)
{
	t_matrix	*mtr;

	mtr = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	mtr->m1 = s;
	mtr->m6 = s;
	mtr->m11 = s;
	mtr->m16 = 1;
	return (mtr);
}

t_matrix	*ft_stretch_x(double s)
{
	t_matrix	*mtr;

	mtr = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	mtr->m1 = s;
	mtr->m6 = 1;
	mtr->m11 = 1;
	mtr->m16 = s;
	return (mtr);
}

t_matrix	*ft_stretch_y(double s)
{
	t_matrix	*mtr;

	mtr = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	mtr->m1 = 1;
	mtr->m6 = s;
	mtr->m11 = 1;
	mtr->m16 = s;
	return (mtr);
}
