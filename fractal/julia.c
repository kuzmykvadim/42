/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 19:33:37 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/24 19:36:20 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia(t_fractal *ftl)
{
	ftl->c.r = -0.70176;
	ftl->c.i = -0.3842;
	ftl->pt1.x = -1;
	ftl->pt1.y = -1.2;
	ftl->m_iter = ITERATIONS;
	ftl->zoom = ZOOM * 100;
	ftl->image.x = 2 * ftl->zoom;
	ftl->image.y = 2.4 * ftl->zoom;
	ftl->real.x = ftl->image.x / 2 - (double)W_SIZE_W / 2;
	ftl->real.y = ftl->image.y / 2 - (double)W_SIZE_H / 2;
}

void	put_julia(t_env *e, t_fractal *ftl)
{
	ftl->x = ftl->real.x;
	ftl->y = ftl->real.y;
	while (ftl->y < ftl->image.y - ftl->real.y)
	{
		while (ftl->x < ftl->image.x - ftl->real.x)
		{
			ftl->z.r = ftl->x / ftl->zoom + ftl->pt1.x;
			ftl->z.i = ftl->y / ftl->zoom + ftl->pt1.y;
			ftl->i = 0;
			while (((ftl->z.r * ftl->z.r + ftl->z.i * ftl->z.i) < 4)
					&& (ftl->i < ftl->m_iter))
			{
				ftl->tmp = ftl->z.r;
				ftl->z.r = ftl->z.r * ftl->z.r - ftl->z.i * ftl->z.i + ftl->c.r;
				ftl->z.i = 2 * ftl->tmp * ftl->z.i + ftl->c.i;
				++ftl->i;
			}
			if (ftl->i < ftl->m_iter)
				put_fractal(e, ftl);
			++ftl->x;
		}
		ftl->x = ftl->real.x;
		++ftl->y;
	}
}
