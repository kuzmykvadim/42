/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_h_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:05:19 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/26 10:05:51 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		key_chang_ftl(int key, t_env *e)
{
	if (key == SHIFT)
	{
		++e->fractal_type;
		if (e->fractal_type > NEWTON)
			e->fractal_type = JULIA;
		expose_hook(e);
	}
	else if (key == T)
		e->fractal_type = TRICORN;
	else if (key == J)
		e->fractal_type = JULIA;
	else if (key == N)
		e->fractal_type = NEWTON;
	else if (key == B)
		e->fractal_type = BURNING_SHIP;
	else if (key == M)
		e->fractal_type = MANDELBROT;
}

int			key_hook_init(int key, t_env *e)
{
	key_h_env(key, e);
	key_h_color(key, e);
	key_chang_ftl(key, e);
	if (e->fractal_type == JULIA)
	{
		key_h_mv_and_iter(key, e->julia);
		calc_hook(key, e->julia);
	}
	else if (e->fractal_type == MANDELBROT)
		key_h_mv_and_iter(key, e->mandelbrot);
	else if (e->fractal_type == BURNING_SHIP)
		key_h_mv_and_iter(key, e->burn_ship);
	else if (e->fractal_type == NEWTON)
		key_h_mv_and_iter(key, e->newton);
	else if (e->fractal_type == TRICORN)
		key_h_mv_and_iter(key, e->tricorn);
	put_img(e);
	return (0);
}

void		mouse_hook(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_R_UP)
	{
		x += 405;
		y += 360;
		f->zoom *= 2;
		f->pt1.x -= ((W_SIZE_W / 2 - x)) / f->zoom;
		f->pt1.y -= ((W_SIZE_H / 2 - y)) / f->zoom;
	}
	else if (key == MOUSE_R_DN)
	{
		x -= 80;
		y -= 40;
		f->zoom *= 0.85;
		f->pt1.x -= ((W_SIZE_W / 2 - x)) / f->zoom;
		f->pt1.y -= ((W_SIZE_H / 2 - y)) / f->zoom;
	}
	f->real.x = f->image.x / 2 - (double)W_SIZE_W / 2;
	f->real.y = f->image.y / 2 - (double)W_SIZE_H / 2;
}

int			mouse_hook_init(int key, int x, int y, t_env *e)
{
	if (e->fractal_type == JULIA)
		mouse_hook(key, x, y, e->julia);
	else if (e->fractal_type == MANDELBROT)
		mouse_hook(key, x, y, e->mandelbrot);
	else if (e->fractal_type == TRICORN)
		mouse_hook(key, x, y, e->tricorn);
	else if (e->fractal_type == BURNING_SHIP)
		mouse_hook(key, x, y, e->burn_ship);
	else if (e->fractal_type == NEWTON)
		mouse_hook(key, x, y, e->newton);
	expose_hook(e);
	return (0);
}

int			motion_hook(int x, int y, t_env *e)
{
	double	new_cr;
	double	new_ci;

	new_cr = (1 / (double)W_SIZE_W * (double)x * 4) - 2;
	new_ci = (1 / (double)W_SIZE_H * (double)y * 4) - 2;
	e->julia->c.r = new_cr;
	e->julia->c.i = new_ci;
	expose_hook(e);
	return (0);
}
