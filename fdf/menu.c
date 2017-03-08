/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:47:34 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:21:18 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu1(t_env *e)
{
	M(e->mlx, e->win, 710, 860, 0xB277B1, "[F17]");
	M(e->mlx, e->win, 760, 860, 0xB277B1, "[F18]");
	M(e->mlx, e->win, 810, 860, 0xB277B1, "[F19]");
	M(e->mlx, e->win, 540, 860, 0xE38690, "[esc]");
	M(e->mlx, e->win, 860, 860, 0xB277B1, "-stretch");
	M(e->mlx, e->win, 780, 930, 0xEFC050, "rotate z");
	M(e->mlx, e->win, 780, 910, 0x5B5EA6, "rotate y");
	M(e->mlx, e->win, 780, 890, 0x98B4D4, "rotate x");
	M(e->mlx, e->win, 910, 890, 0xE38690, "[-]");
	M(e->mlx, e->win, 910, 910, 0xE38690, "[+]");
	M(e->mlx, e->win, 880, 930, 0xE38690, "(zoom)");
	M(e->mlx, e->win, 575, 905, 0xE38690, "[^]");
	M(e->mlx, e->win, 575, 930, 0xE38690, "[v]");
}

void	ft_menu(t_env *e)
{
	M(e->mlx, e->win, 540, 930, 0xE38690, "[<]");
	M(e->mlx, e->win, 610, 930, 0xE38690, "[>]");
	M(e->mlx, e->win, 780, 830, 0xE38690, "NUMPAD");
	M(e->mlx, e->win, 660, 930, 0xEFC050, "[1]");
	M(e->mlx, e->win, 700, 930, 0x98B4D4, "[2]");
	M(e->mlx, e->win, 740, 930, 0xEFC050, "[3]");
	M(e->mlx, e->win, 660, 910, 0x5B5EA6, "[4]");
	M(e->mlx, e->win, 740, 910, 0x5B5EA6, "[6]");
	M(e->mlx, e->win, 740, 890, 0xEFC050, "[9]");
	M(e->mlx, e->win, 700, 890, 0x98B4D4, "[8]");
	M(e->mlx, e->win, 660, 890, 0xEFC050, "[7]");
	M(e->mlx, e->win, 660, 860, 0xB277B1, "[F16]");
	ft_menu1(e);
}
