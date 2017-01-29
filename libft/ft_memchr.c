/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:26:06 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/08 16:16:03 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (*str && *str != (unsigned char)c && n > 0)
	{
		str++;
		n--;
	}
	if (*str == (unsigned char)c)
		return ((unsigned char*)str);
	else
		return (NULL);
}
