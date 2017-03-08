/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:39:32 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:16:04 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_h_esc(int key, t_env *e)
{
	if (key == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
}

static void	key_h_rot(int key, t_env *e)
{
	if (key == ROT_X_UP)
		ft_rotate(e, X_UP, 'x');
	else if (key == ROT_X_DN)
		ft_rotate(e, X_DOWN, 'x');
	else if (key == ROT_Y_UP)
		ft_rotate(e, Y_UP, 'y');
	else if (key == ROT_Y_DN)
		ft_rotate(e, Y_DOWN, 'y');
	else if (key == ROT_Z_UP || key == 89)
		ft_rotate(e, Z_UP, 'z');
	else if (key == ROT_Z_DN || key == 85)
		ft_rotate(e, Z_DOWN, 'z');
}

static void	key_h_move(int key, t_env *e)
{
	if (key == UP)
		ft_move(e, 0, GO_UP, 0);
	else if (key == DOWN)
		ft_move(e, 0, GO_DOWN, 0);
	else if (key == LEFT)
		ft_move(e, GO_LEFT, 0, 0);
	else if (key == RIGHT)
		ft_move(e, GO_RIGHT, 0, 0);
}

static void	key_h_stretch(int key, t_env *e)
{
	if (key == STRETCH_X_UP)
		ft_stretch(e, STR_UP, 'x');
	else if (key == STRETCH_X_DN)
		ft_stretch(e, STR_DN, 'x');
	else if (key == STRETCH_Y_UP)
		ft_stretch(e, STR_UP, 'y');
	else if (key == STRETCH_Y_DN)
		ft_stretch(e, STR_DN, 'y');
	else if (key == ZOOM_IN)
		ft_zoom(e, ZOOM_PLUS);
	else if (key == ZOOM_OUT)
		ft_zoom(e, ZOOM_MINUS);
}

int			key_hook(int key, t_env *e)
{
	key_h_rot(key, e);
	key_h_move(key, e);
	key_h_esc(key, e);
	key_h_stretch(key, e);
	put_img(e);
	return (0);
}
