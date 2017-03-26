/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:29:31 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/24 18:57:45 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_color		random_color(t_color c)
{
	int		rnd;
	int		rnd1;

	srand(time(NULL));
	rnd = rand() % 100 + 0;
	rnd1 = rand() % 200 + 100;
	c.center = rnd;
	c.width = rnd1;
	return (c);
}

void		freq_color(t_env *e, t_pixel pt, double i, double m_iter)
{
	t_color c;

	c.center = 185;
	c.width = 70;
	c.phase = 1;
	if (e->colorscheme == 2)
	{
		c.center = 20;
		c.width = 235;
		c.phase = 3;
	}
	if (e->colorscheme == 3)
	{
		c.center = 135;
		c.width = 110;
		c.phase = 2;
	}
	if (e->colorscheme == 4)
		c = random_color(c);
	c.freq = M_PI * 2 / m_iter;
	c.r = sin(c.freq * i + 4 + c.phase) * c.width + c.center;
	c.g = sin(c.freq * i + 2 + c.phase) * c.width + c.center;
	c.b = sin(c.freq * i + 1 + c.phase) * c.width + c.center;
	put_pix_img(e, pt.x, pt.y, &c);
}
