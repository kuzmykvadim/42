/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:12:46 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/24 19:23:12 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	newton(t_fractal *ftl)
{
	ftl->pt1.x = -1.4;
	ftl->pt1.y = -1.2;
	ftl->m_iter = ITERATIONS;
	ftl->zoom = ZOOM * 100;
	ftl->image.x = 2.7 * ftl->zoom;
	ftl->image.y = 2.4 * ftl->zoom;
	ftl->real.x = ftl->image.x / 2 - (double)W_SIZE_W / 2;
	ftl->real.y = ftl->image.y / 2 - (double)W_SIZE_H / 2;
}

void	calc_newton(t_env *e, t_fractal *ftl)
{
	ftl->z.r = ftl->x / ftl->zoom + ftl->pt1.x;
	ftl->z.i = ftl->y / ftl->zoom + ftl->pt1.y;
	ftl->i = 0;
	ftl->tmp = 3.0;
	ftl->tmp = 3.0;
	while ((ftl->tmp > 0.000001) && (ftl->i < ftl->m_iter))
	{
		ftl->old.r = ftl->z.r;
		ftl->old.i = ftl->z.i;
		ftl->tmp = (ftl->z.r * ftl->z.r + ftl->z.i * ftl->z.i)
			* (ftl->z.r * ftl->z.r + ftl->z.i * ftl->z.i);
		ftl->z.r = (2 * ftl->z.r * ftl->tmp + ftl->z.r
				* ftl->z.r - ftl->z.i * ftl->z.i) / (3.0 * ftl->tmp);
		ftl->z.i = (2 * ftl->z.i * (ftl->tmp - ftl->old.r))
			/ (3.0 * ftl->tmp);
		ftl->tmp = (ftl->z.r - ftl->old.r) * (ftl->z.r - ftl->old.r)
			+ (ftl->z.i - ftl->old.i) * (ftl->z.i - ftl->old.i);
		++ftl->i;
	}
	if (ftl->i < ftl->m_iter)
		put_fractal(e, ftl);
}

void	put_newton(t_env *e, t_fractal *ftl)
{
	ftl->x = ftl->real.x;
	ftl->y = ftl->real.y;
	while (ftl->y < ftl->image.y - ftl->real.y)
	{
		while (ftl->x < ftl->image.x - ftl->real.x)
		{
			calc_newton(e, ftl);
			++ftl->x;
		}
		ftl->x = ftl->real.x;
		++ftl->y;
	}
}
