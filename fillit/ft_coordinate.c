/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:16:01 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 16:16:25 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_coordinate(char **arr, char lit)
{
	int		i;
	char	*str;
	int		m;
	int		n;

	m = 0;
	i = -1;
	str = (char*)malloc(10);
	while (m < 4)
	{
		n = 0;
		while (n < 4)
		{
			if (arr[m][n] == '#')
			{
				str[++i] = m + '0';
				str[++i] = n + '0';
			}
			n++;
		}
		m++;
	}
	str[++i] = lit;
	str[++i] = '\0';
	return (str);
}
