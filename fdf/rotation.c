/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 13:24:33 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:32:42 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*rotation_x(double beta)
{
	t_matrix *mtr;

	mtr = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	if (!mtr)
		puts("malloc error");
	mtr->m1 = 1;
	mtr->m6 = cos(beta);
	mtr->m7 = sin(beta);
	mtr->m10 = -sin(beta);
	mtr->m11 = cos(beta);
	mtr->m16 = 1;
	return (mtr);
}

t_matrix	*rotation_y(double beta)
{
	t_matrix *mtr;

	mtr = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	if (!mtr)
		puts("malloc error");
	mtr->m1 = cos(beta);
	mtr->m3 = sin(beta);
	mtr->m9 = -sin(beta);
	mtr->m11 = cos(beta);
	mtr->m6 = 1;
	mtr->m16 = 1;
	return (mtr);
}

t_matrix	*rotation_z(double beta)
{
	t_matrix *mtr;

	mtr = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	if (!mtr)
		puts("malloc error");
	mtr->m1 = cos(beta);
	mtr->m2 = -sin(beta);
	mtr->m5 = sin(beta);
	mtr->m6 = cos(beta);
	mtr->m11 = 1;
	mtr->m16 = 1;
	return (mtr);
}

void		ft_rotate(t_env *e, double beta, char type)
{
	t_matrix *mtr;

	if (type == 'x')
		mtr = rotation_x(beta);
	else if (type == 'y')
		mtr = rotation_y(beta);
	else
		mtr = rotation_z(beta);
	ft_mtr_to_map(mtr, e);
	free(mtr);
}
