/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:39:29 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/10/18 11:52:36 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				get_color(t_env *e)
{
	if (e->object.hit_side_dist == 1 && e->object.step.y == -1)
		return (e->color1);
	else if ((e->object.hit_side_dist == 1 && e->object.step.y == 1))
		return (e->color2);
	else if (e->object.step.x == -1)
		return (e->color3);
	else
		return (e->color4);
}

unsigned int	ft_smoke(unsigned int c, double dist, int area)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	if (area == 1)
		dist = dist / 300;
	else
		dist = dist / 6;
	if (dist > 0.85)
		dist = 0.85;
	r = r - (r * dist);
	g = g - (g * dist);
	b = b - (b * dist);
	return ((r << 16) + (g << 8) + b);
}

void			put_pixel_img(t_env *e, int x, int y, unsigned int color)
{
	int		x0;

	if (x < 0 || y < 0 || x >= W_SIZE_W || y >= W_SIZE_H)
		return ;
	x0 = (x * 4) + (y * e->s_line);
	e->pix[x0] = color;
	e->pix[++x0] = color >> 8;
	e->pix[++x0] = color >> 16;
}
