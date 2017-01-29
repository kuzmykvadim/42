/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:43:37 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 16:43:39 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map_gen(int size)
{
	char	**map;
	int		column;
	int		row;

	row = 0;
	map = (char**)malloc(sizeof(char*) * (size + 1));
	while (row < size)
	{
		map[row] = (char*)malloc(size + 1);
		column = 0;
		while (column < size)
		{
			map[row][column] = '.';
			column++;
		}
		map[row][column] = '\0';
		row++;
	}
	map[row] = NULL;
	return (map);
}
