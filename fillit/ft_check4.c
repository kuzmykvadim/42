/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:45:31 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 16:45:38 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check4(char *s, int i)
{
	int	count_hash;
	int	n;

	while (s[i])
	{
		if (s[i] == '\n' && s[i])
			i++;
		count_hash = 0;
		n = 0;
		while (n < 4 && s[i])
		{
			if (s[i] == '#')
				count_hash++;
			if (s[i] == '\n')
				n++;
			i++;
		}
		if (count_hash != 4)
			return (1);
		if (s[i])
			return (ft_check4(s, i));
	}
	return (0);
}
