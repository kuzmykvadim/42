/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:39:14 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/03 23:48:08 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init(t_env *e, char *file)
{
	if (!(e->fd = open(file, O_RDONLY)))
	{
		printf("scene error");
		exit(1);
	}
	e->obj = (t_object*)malloc(sizeof(t_object));
	e->nb_obj = 0;
	e->fieldofview = 60;
	e->shd = 1;
	ft_parsing(e);
}
