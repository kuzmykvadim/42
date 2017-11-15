/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:25:29 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/11/29 12:13:22 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	if ((d - s) >= 0)
	{
		i = len - 1;
		while ((int)i != -1)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	return (dest);
}
