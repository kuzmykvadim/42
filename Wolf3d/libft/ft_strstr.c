/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:51:59 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/11/29 19:14:43 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *lit)
{
	char *a;
	char *b;

	if (*lit == '\0')
		return ((char*)big);
	while (*big)
	{
		a = (char *)big;
		b = (char *)lit;
		while (*b && *a == *b)
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return ((char *)big);
		big++;
	}
	return (NULL);
}
