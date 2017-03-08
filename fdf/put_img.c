/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:55:34 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:30:44 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pix_img(t_env *e, int x, int y, int color)
{
	int		x0;

	if (x < 0 || y < 0 || x >= W_SIZE_W || y >= W_SIZE_H)
		return ;
	x0 = (int)y * e->s_line + (int)x * 4;
	e->pix[x0] = color;
	e->pix[x0 + 1] = color >> 8;
	e->pix[x0 + 2] = color >> 16;
}

void	put_line(t_pixel point1, t_pixel point2, t_env *e)
{
	double	tmp;
	double	difx;
	double	dify;
	double	x;
	double	y;

	x = point1.x;
	y = point1.y;
	difx = point2.x - point1.x;
	dify = point2.y - point1.y;
	tmp = sqrt((difx * difx) + (dify * dify));
	difx /= tmp;
	dify /= tmp;
	while (tmp >= 0)
	{
		put_pix_img(e, x, y, ft_color(&point1, &point2));
		x += difx;
		y += dify;
		tmp--;
	}
}

void	put_map(t_env *e)
{
	int		x;
	int		y;
	t_pixel	point;

	y = 0;
	while (y < e->map->len)
	{
		x = 0;
		while (x < (e->map->lines[y]->len))
		{
			point = (*e->map->lines[y]->pixels[x]);
			if (x + 1 < e->map->lines[y]->len
					&& e->map->lines[y]->pixels[x + 1])
				put_line(point, (*e->map->lines[y]->pixels[x + 1]), e);
			if (y + 1 < e->map->len && e->map->lines[y + 1]->pixels[x])
				put_line(point, (*e->map->lines[y + 1]->pixels[x]), e);
			x++;
		}
		y++;
	}
}
