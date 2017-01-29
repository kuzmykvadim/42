/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:46:43 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/27 19:20:28 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	*s;

	s = str;
	i = 0;
	while (len > 0)
	{
		s[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (str);
}
