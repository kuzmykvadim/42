/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_cheker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:03:21 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 16:03:26 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkmap(char **map, char **tetra, int *xy, int k)
{
	int	x;
	int y;

	x = xy[0];
	y = xy[1];
	if (y + (tetra[k][0] - '0') >= xy[2] || y + (tetra[k][2] - '0') >=
		xy[2] || y + (tetra[k][4] - '0') >= xy[2] || y +
		(tetra[k][6] - '0') >= xy[2])
		return (0);
	if (x + (tetra[k][1] - '0') >= xy[2] || x + (tetra[k][3] - '0') >=
		xy[2] || x + (tetra[k][5] - '0') >= xy[2] || x + (tetra[k][7] - '0')
		>= xy[2])
		return (0);
	if (map[(tetra[k][0] - '0') + y][(tetra[k][1] - '0') + x] == '.'
			&& map[(tetra[k][2] - '0') + y][(tetra[k][3] - '0') + x] == '.'
			&& map[(tetra[k][4] - '0') + y][(tetra[k][5] - '0') + x] == '.'
			&& map[(tetra[k][6] - '0') + y][(tetra[k][7] - '0') + x] == '.')
		return (1);
	else
		return (0);
}
