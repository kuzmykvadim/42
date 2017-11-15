/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:51:47 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/11/29 19:41:20 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s;
	char	*d;

	s = (char*)src;
	d = (char*)dst;
	while (n > 0 && *s != c)
	{
		*d++ = *s++;
		n--;
	}
	if (n > 0)
	{
		*d++ = *s++;
		return ((unsigned char*)d);
	}
	else
		return (NULL);
}
