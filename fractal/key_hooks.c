/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:39:32 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/26 11:27:25 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	key_h_env(int key, t_env *e)
{
	if (key == ESC)
	{
		free(e);
		exit(0);
	}
	if (key == SPACE)
		fractal_create(e);
}

void	key_h_zoom(int key, t_fractal *ftl)
{
	if (key == ZOOM_PL)
	{
		ftl->zoom *= 1.1;
		ftl->image.x = 2.7 * ftl->zoom;
		ftl->image.y = 2.4 * ftl->zoom;
	}
	else if (key == ZOOM_MN)
	{
		ftl->zoom *= 0.9;
		ftl->image.x = 2.7 * ftl->zoom;
		ftl->image.y = 2.4 * ftl->zoom;
	}
	ftl->real.x = ftl->image.x / 2 - (float)W_SIZE_W / 2;
	ftl->real.y = ftl->image.y / 2 - (float)W_SIZE_H / 2;
}

void	key_h_mv_and_iter(int key, t_fractal *ftl)
{
	if (key == UP)
		ftl->pt1.y += 25 / ftl->zoom;
	else if (key == DOWN)
		ftl->pt1.y -= 25 / ftl->zoom;
	else if (key == LEFT)
		ftl->pt1.x += 25 / ftl->zoom;
	else if (key == RIGHT)
		ftl->pt1.x -= 25 / ftl->zoom;
	else if (key == ITER_PLUS)
		ftl->m_iter += 5;
	else if (key == ITER_MINUS)
		ftl->m_iter -= 5;
	key_h_zoom(key, ftl);
}

void	calc_hook(int key, t_fractal *ftl)
{
	if (key == ROT_Y_UP)
		ftl->c.r += 0.01;
	else if (key == ROT_Y_DN)
		ftl->c.r -= 0.01;
	else if (key == ROT_X_UP)
		ftl->c.i += 0.01;
	else if (key == ROT_X_DN)
		ftl->c.i -= 0.01;
}

void	key_h_color(int key, t_env *e)
{
	if (key == COLOR_1)
		e->colorscheme = 1;
	else if (key == COLOR_2)
		e->colorscheme = 2;
	else if (key == COLOR_3)
		e->colorscheme = 3;
	else if (key == COLOR_4)
		e->colorscheme = 4;
}
