/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:23:08 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:19:27 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	expose_hook(t_env *e)
{
	put_img(e);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_env	*e;

	if (argc == 2)
	{
		e = (t_env*)malloc(sizeof(t_env));
		if (!e)
			puts("malloc error");
		map = ft_parse_map(argv, 0);
		if (map->len == 0 || map->lines[0]->len == 0)
			puts("error map");
		e->map = map;
		create_window("UNIT Factory", W_SIZE_W, W_SIZE_H, e);
		put_to_center(e);
		ft_present_map(e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, 2, 5, key_hook, e);
		mlx_loop(e->mlx);
	}
	else
		puts("usage: ./fdf source_file");
	return (0);
}
