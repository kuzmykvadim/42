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

#include "rtv1.h"

int	expose_hook(t_env *e)
{
	put_img(e);
	return (0);
}

int	esc_key_funct(int key)
{
	if (key == ESC)
	{
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env *e;

	if (argc != 2)
	{
		puts("bad param");
		exit(1);
	}
	e = (t_env*)malloc(sizeof(t_env));
	ft_init(e, argv[1]);
	create_window("RTV1 @UNIT Factory", W_SIZE_W, W_SIZE_H, e);
	put_img(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, esc_key_funct, e);
	mlx_hook(e->win, 2, 5, key_hook_init, e);
	mlx_loop(e->mlx);
	return (0);
}
