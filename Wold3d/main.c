/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 11:58:36 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 00:26:33 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_parse_error(char *str)
{
	ft_putstr(str);
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(1);
}

int		close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(1);
	return (1);
}

int		esc_key_funct(int key)
{
	if (key == ESC)
	{
		system("killall afplay 2&>/dev/null >/dev/null");
		exit(1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env *e;

	if (argc != 2)
		ft_parse_error("Error. Use ./Wolf3D <map>");
	e = (t_env*)malloc(sizeof(t_env));
	if (ft_map_init(e, argv[1]) == 0)
		ft_parse_error("Map error");
	create_window("Wolf3D @UNIT Factory", W_SIZE_W, W_SIZE_H, e);
	system("afplay BIGGIE.mp3&");
	mlx_loop_hook(e->mlx, put_img, e);
	mlx_hook(e->win, 17, 18, close_win, e);
	mlx_hook(e->win, 2, 5, key_hook_init, e);
	mlx_loop(e->mlx);
	system("killall afplay 2&>/dev/null >/dev/null");
	return (0);
}
