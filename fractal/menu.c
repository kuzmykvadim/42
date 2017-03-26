/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:47:34 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/26 11:52:13 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_menu(t_env *e)
{
	ML(e->mlx, e->win1, 10, 40, 0xE38690, "[<]");
	ML(e->mlx, e->win1, 60, 40, 0xE38690, "[>]      move");
	ML(e->mlx, e->win1, 35, 25, 0xE38690, "[^]");
	ML(e->mlx, e->win1, 35, 40, 0xE38690, "[V]");
	ML(e->mlx, e->win1, 10, 60, 0xE38690, "[SHIFT]       change fractal");
	ML(e->mlx, e->win1, 10, 80, 0xE38690, "[1]");
	ML(e->mlx, e->win1, 35, 80, 0xE38690, "[2]");
	ML(e->mlx, e->win1, 60, 80, 0xE38690, "[3]");
	ML(e->mlx, e->win1, 85, 80, 0xE38690, "[4]   colorscheme");
	ML(e->mlx, e->win1, 10, 100, 0xE38690, "[mouse roll]  zoom");
	ML(e->mlx, e->win1, 10, 120, 0xE38690, "[*]");
	ML(e->mlx, e->win1, 35, 120, 0xE38690, "[/]        iterations");
	ML(e->mlx, e->win1, 10, 140, 0xE38690, "[B]           Burning ship");
	ML(e->mlx, e->win1, 10, 160, 0xE38690, "[N]           Newton");
	ML(e->mlx, e->win1, 10, 180, 0xE38690, "[M]           Mandelbrot");
	ML(e->mlx, e->win1, 10, 200, 0xE38690, "[T]           Tricorn");
	ML(e->mlx, e->win1, 10, 220, 0xE38690, "[J]           Julia");
	ML(e->mlx, e->win1, 10, 240, 0xE38690, "[SPACE]       reset");
	ML(e->mlx, e->win1, 10, 260, 0xE38690, "[ESC]         exit");
}
