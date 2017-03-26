/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:34:17 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/26 11:54:52 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			expose_hook(t_env *e)
{
	put_img(e);
	return (0);
}

int			menu_key_funct(int key, t_env *e)
{
	if (key == ENTER)
	{
		e->win1 = mlx_new_window(e->mlx, 300, 300, "MENU");
		ft_menu(e);
	}
	return (0);
}

int			set_fractal(char *str, t_env *e)
{
	if (ft_strequ("M", str) || ft_strequ("Mandelbrot", str))
		e->fractal_type = MANDELBROT;
	else if (ft_strequ("J", str) || ft_strequ("Julia", str))
		e->fractal_type = JULIA;
	else if (ft_strequ("T", str) || ft_strequ("Tricorn", str))
		e->fractal_type = TRICORN;
	else if (ft_strequ("B", str) || ft_strequ("Burning_Ship", str))
		e->fractal_type = BURNING_SHIP;
	else if (ft_strequ("N", str) || ft_strequ("Newton", str))
		e->fractal_type = NEWTON;
	return (e->fractal_type == 0 ? 0 : 1);
}

int			main(int argc, char **argv)
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	fractal_create(e);
	if ((argc != 2) || (!set_fractal(argv[1], e)))
	{
		ft_putstr("\e[101mUsage:\e[49m \e[31m./fractal");
		ft_putstr("[M | J | T | B | N]\e[39m");
		ft_putstr("\n   \e[101mor:\e[49m \e[31m./fractal[Mandelbrot | Julia");
		ft_putstr("| Tricorn | Burning_Ship | Newton]\e[39m\n");
		exit(0);
	}
	create_window("UNIT Factory @Fractal project", W_SIZE_W, W_SIZE_H, e);
	put_img(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_hook_init, e);
	mlx_key_hook(e->win, menu_key_funct, e);
	mlx_hook(e->win, 6, 1L << 6, motion_hook, e);
	mlx_hook(e->win, 2, 5, key_hook_init, e);
	ft_putstr("\e[32mClick \e[104mENTER\e[49m to open menu\e[39m\n");
	mlx_loop(e->mlx);
	return (0);
}
