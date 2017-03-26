/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:12:06 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/26 11:27:19 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		create_window(char *header, int weight, int height, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, weight, height, header);
}

void		put_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, W_SIZE_W, W_SIZE_H);
	e->pix = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->i));
	if (e->fractal_type == JULIA)
		put_julia(e, e->julia);
	else if (e->fractal_type == MANDELBROT)
		put_mandelbrot(e, e->mandelbrot);
	else if (e->fractal_type == TRICORN)
		put_tricorn(e, e->tricorn);
	else if (e->fractal_type == BURNING_SHIP)
		put_burn_ship(e, e->burn_ship);
	else if (e->fractal_type == NEWTON)
		put_newton(e, e->newton);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void		put_pix_img(t_env *e, int x, int y, t_color *c)
{
	int		x0;

	if (x < 0 || y < 0 || x >= W_SIZE_W || y >= W_SIZE_H)
		return ;
	x0 = (int)y * e->s_line + (int)x * 4;
	e->pix[x0] = c->b;
	e->pix[x0 + 1] = c->g;
	e->pix[x0 + 2] = c->r;
}

void		put_fractal(t_env *e, t_fractal *ftl)
{
	t_pixel	point;

	point.x = ftl->x - ftl->real.x;
	point.y = ftl->y - ftl->real.y;
	freq_color(e, point, ftl->i, ftl->m_iter);
}

void		fractal_create(t_env *e)
{
	e->julia = malloc(sizeof(t_fractal));
	julia(e->julia);
	e->mandelbrot = malloc(sizeof(t_fractal));
	mandelbrot(e->mandelbrot);
	e->tricorn = malloc(sizeof(t_fractal));
	tricorn(e->tricorn);
	e->burn_ship = malloc(sizeof(t_fractal));
	burn_ship(e->burn_ship);
	e->newton = malloc(sizeof(t_fractal));
	newton(e->newton);
}
