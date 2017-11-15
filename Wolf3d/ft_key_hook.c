/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:56:30 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/10/18 11:57:34 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_rt_right(t_env *e)
{
	double	ox;
	double	px;

	ox = e->object.play_dir.x;
	e->object.play_dir.x = e->object.play_dir.x * cos(-(e->object.step_rotate))
		- e->object.play_dir.y * sin(-(e->object.step_rotate));
	e->object.play_dir.y = ox * sin(-(e->object.step_rotate))
		+ e->object.play_dir.y * cos(-(e->object.step_rotate));
	px = e->object.plane.x;
	e->object.plane.x = e->object.plane.x * cos(-(e->object.step_rotate))
		- e->object.plane.y * sin(-(e->object.step_rotate));
	e->object.plane.y = px * sin(-(e->object.step_rotate))
		+ e->object.plane.y * cos(-(e->object.step_rotate));
}

void	ft_rt_left(t_env *e)
{
	double	ox;
	double	px;

	ox = e->object.play_dir.x;
	e->object.play_dir.x = e->object.play_dir.x * cos(e->object.step_rotate)
		- e->object.play_dir.y * sin(e->object.step_rotate);
	e->object.play_dir.y = ox * sin(e->object.step_rotate)
		+ e->object.play_dir.y * cos(e->object.step_rotate);
	px = e->object.plane.x;
	e->object.plane.x = e->object.plane.x * cos(e->object.step_rotate)
		- e->object.plane.y * sin(e->object.step_rotate);
	e->object.plane.y = px * sin(e->object.step_rotate)
		+ e->object.plane.y * cos(e->object.step_rotate);
}

void	ft_rotate(int key, t_env *e)
{
	if (key == RIGHT)
		ft_rt_right(e);
	else if (key == LEFT)
		ft_rt_left(e);
}

void	ft_move(int keycode, t_env *e)
{
	if (keycode == W)
	{
		if (e->map[(int)(e->object.play_pos.x + e->object.play_dir.x *
			e->object.step_move)][(int)(e->object.play_pos.y)] == 0)
			e->object.play_pos.x += e->object.play_dir.x * e->object.step_move;
		if (e->map[(int)(e->object.play_pos.x)][(int)(e->object.play_pos.y +
			e->object.play_dir.y * e->object.step_move)] == 0)
			e->object.play_pos.y += e->object.play_dir.y * e->object.step_move;
	}
	if (keycode == S)
	{
		if (e->map[(int)(e->object.play_pos.x - e->object.play_dir.x *
			e->object.step_move)][(int)(e->object.play_pos.y)] == 0)
			e->object.play_pos.x -= e->object.play_dir.x * e->object.step_move;
		if (e->map[(int)(e->object.play_pos.x)][(int)(e->object.play_pos.y -
			e->object.play_dir.y * e->object.step_move)] == 0)
			e->object.play_pos.y -= e->object.play_dir.y * e->object.step_move;
	}
}

int		key_hook_init(int key, t_env *e)
{
	if (key == LEFT || key == RIGHT)
		ft_rotate(key, e);
	if (e->smoke_off == 1)
		system("afplay grim.mp3&");
	if (key == ENTER)
		e->start = 1;
	if (key == Q)
		e->start = 0;
	if (key == MINUS)
		e->iter1 = 1;
	if (key == PLUS)
		e->iter1 = 2;
	ft_move(key, e);
	esc_key_funct(key);
	ft_lightning(e);
	return (0);
}
