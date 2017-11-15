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

#include "wolf3d.h"

void	draw_line(t_env *e, int x, int start, int end)
{
	unsigned int	color;
	int				i;

	i = -1;
	color = get_color(e);
	while (++i < start + e->object.i)
		put_pixel_img(e, x, i, e->sky_col);
	i--;
	while (++i <= end + e->object.i && i < e->win_height)
		put_pixel_img(e, x, i, color);
	i--;
	while (++i < e->win_height)
		put_pixel_img(e, x, i, e->ground_col);
}

void	draw_line_with_smoke(t_env *e, int x, int start, int end)
{
	unsigned int	color;
	int				i;

	i = -1;
	color = get_color(e);
	color = ft_smoke(color, e->object.dist, 0);
	while (++i < start + e->object.i)
		put_pixel_img(e, x, i, ft_smoke(e->sky_col, e->win_height - i, 2));
	i--;
	while (++i <= end + e->object.i && i < e->win_height)
		put_pixel_img(e, x, i, color);
	i--;
	while (++i < e->win_height)
		put_pixel_img(e, x, i, ft_smoke(e->ground_col, e->win_height - i, 1));
}

void	low_and_hight_pix(t_env *e, int x)
{
	int		height;
	int		start;
	int		end;

	height = (int)(e->win_height / e->object.dist);
	start = -height / 2 + e->win_height / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + e->win_height / 2;
	if (end >= e->win_height)
		end = e->win_height - 1;
	if (e->smoke_off == 1)
		draw_line(e, x, start, end);
	else
		draw_line_with_smoke(e, x, start, end);
}

void	create_window(char *header, int weight, int height, t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, weight, height, header);
}

int		put_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, W_SIZE_W, W_SIZE_H);
	e->pix = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->i));
	e->img2 = mlx_xpm_file_to_image(e->mlx, "main_menu.xpm",
		&(e->size_h), &(e->size_w));
	ft_raycasting(e);
	if (e->start != 1)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->img2, 0, 0);
		mlx_string_put(e->mlx, e->win, 280, 620, 0xffffff, "ENTER TO START");
		mlx_string_put(e->mlx, e->win, 480, 620, 0xffffff, "Q - BACK TO MENU");
		mlx_string_put(e->mlx, e->win, 660, 620, 0xffffff, "ESC - EXIT");
	}
	if (e->start == 1)
	{
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}
