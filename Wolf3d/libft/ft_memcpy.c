/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:48:17 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/11/29 11:29:45 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	while (len > 0)
	{
		*d = *s;
		s++;
		d++;
		len--;
	}
	return (dest);
}
