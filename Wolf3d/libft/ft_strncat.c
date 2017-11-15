/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:31:53 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/11/29 19:36:20 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	i = 0;
	while (str1[i])
		i++;
	j = 0;
	while (str2[j] && j < n)
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return ((char*)str1);
}
