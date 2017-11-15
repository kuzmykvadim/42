/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:12:06 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 00:11:26 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		create_window(char *header, int weight, int height, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, weight, height, header);
}

void		put_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, W_SIZE_W, W_SIZE_H);
	e->pix = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->i));
	ft_ray_trace(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void		put_pix_img(t_env *e, int x, int y, t_color c)
{
	int		x0;

	if (x < 0 || y < 0 || x >= W_SIZE_W || y >= W_SIZE_H)
		return ;
	c.r *= ft_light(e);
	c.g *= ft_light(e);
	c.b *= ft_light(e);
	x0 = (int)y * e->s_line + (int)x * 4;
	e->pix[x0] = c.b;
	e->pix[x0 + 1] = c.g;
	e->pix[x0 + 2] = c.r;
}
