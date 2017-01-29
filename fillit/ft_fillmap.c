/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:18:36 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 15:29:40 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fillmap(char **map, char **tetra, int *xy, int k)
{
	char	lit;
	int		x;
	int		y;

	x = xy[0];
	y = xy[1];
	lit = tetra[k][8];
	map[(tetra[k][0] - '0') + y][(tetra[k][1] - '0') + x] = lit;
	map[(tetra[k][2] - '0') + y][(tetra[k][3] - '0') + x] = lit;
	map[(tetra[k][4] - '0') + y][(tetra[k][5] - '0') + x] = lit;
	map[(tetra[k][6] - '0') + y][(tetra[k][7] - '0') + x] = lit;
}
