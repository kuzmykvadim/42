/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:01:52 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 16:01:17 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_logic(char **map, char **arr, int k, int *block)
{
	int		xy[3];

	xy[2] = block[1];
	xy[1] = 0;
	if (k == block[0])
		return (1);
	while (xy[1] < xy[2])
	{
		xy[0] = 0;
		while (xy[0] < xy[2])
		{
			if (ft_checkmap(map, arr, xy, k))
			{
				ft_fillmap(map, arr, xy, k);
				if (ft_logic(map, arr, k + 1, block))
					return (1);
				ft_remap(map, arr, xy, k);
			}
			xy[0] = xy[0] + 1;
		}
		xy[1] = xy[1] + 1;
	}
	return (0);
}
