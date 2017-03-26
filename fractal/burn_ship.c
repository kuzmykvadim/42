/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:02:07 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/24 19:36:59 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	burn_ship(t_fractal *ftl)
{
	ftl->pt1.x = -1.8;
	ftl->pt1.y = -1.5;
	ftl->m_iter = ITERATIONS;
	ftl->zoom = ZOOM * 100;
	ftl->image.x = 2.7 * ftl->zoom;
	ftl->image.y = 2.4 * ftl->zoom;
	ftl->real.x = ftl->image.x / 2 - (double)W_SIZE_W / 2;
	ftl->real.y = ftl->image.y / 2 - (double)W_SIZE_H / 2;
}

void	calc_burn_ship(t_env *e, t_fractal *ftl)
{
	ftl->c.r = ftl->x / ftl->zoom + ftl->pt1.x;
	ftl->c.i = ftl->y / ftl->zoom + ftl->pt1.y;
	ftl->z.r = 0;
	ftl->z.i = 0;
	ftl->i = 0;
	while (((ftl->z.r * ftl->z.r + ftl->z.i * ftl->z.i) < 4)
			&& (ftl->i < ftl->m_iter))
	{
		ftl->old.r = ftl->z.r * ftl->z.r;
		ftl->old.i = ftl->z.i * ftl->z.i;
		ftl->z.i = fabs(ftl->z.r * ftl->z.i) * 2.0 + ftl->c.i;
		ftl->z.r = ftl->old.r - ftl->old.i + ftl->c.r;
		++ftl->i;
	}
	if (ftl->i < ftl->m_iter)
		put_fractal(e, ftl);
}

void	put_burn_ship(t_env *e, t_fractal *ftl)
{
	ftl->x = ftl->real.x;
	ftl->y = ftl->real.y;
	while (ftl->y < ftl->image.y - ftl->real.y)
	{
		while (ftl->x < ftl->image.x - ftl->real.x)
		{
			calc_burn_ship(e, ftl);
			++ftl->x;
		}
		ftl->x = ftl->real.x;
		++ftl->y;
	}
}
