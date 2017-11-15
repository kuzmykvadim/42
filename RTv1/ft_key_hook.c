/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 16:56:30 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/03 23:50:23 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	key_hook_fov(int key, t_env *e)
{
	if (key == 75)
		e->fieldofview *= 0.9;
	else if (key == 67)
		e->fieldofview *= 1.1;
}

void	key_hook_cam(int key, t_env *e)
{
	if (key == UP)
		e->cam.pos.y -= 1;
	else if (key == DOWN)
		e->cam.pos.y += 1;
	else if (key == LEFT)
		e->cam.pos.x += 1;
	else if (key == RIGHT)
		e->cam.pos.x -= 1;
	else if (key == ZOOM_PL)
		e->cam.pos.z += 1;
	else if (key == ZOOM_MN)
		e->cam.pos.z -= 1;
}

void	key_hk(int key, t_env *e)
{
	if (key == 18)
	{
		e->cam.rot.p += 1 * M_PI / 180;
		ft_costyl(e);
	}
	else if (key == 19)
	{
		e->cam.rot.p -= 1 * M_PI / 180;
		ft_costyl(e);
	}
	else if (key == 20)
	{
		e->cam.rot.j += 1 * M_PI / 180;
		ft_costyl(e);
	}
	else if (key == 21)
	{
		e->cam.rot.j -= 1 * M_PI / 180;
		ft_costyl(e);
	}
}

void	key_hook_lght(int key, t_env *e)
{
	if (key == 279)
		e->light.position.x += 1;
	else if (key == 117)
		e->light.position.x -= 1;
	else if (key == 115)
		e->light.position.y += 1;
	else if (key == 119)
		e->light.position.y -= 1;
	else if (key == 116)
		e->light.position.z += 1;
	else if (key == 121)
		e->light.position.z -= 1;
}

int		key_hook_init(int key, t_env *e)
{
	key_hook_cam(key, e);
	key_hook_fov(key, e);
	key_hook_lght(key, e);
	key_hk(key, e);
	put_img(e);
	return (0);
}
