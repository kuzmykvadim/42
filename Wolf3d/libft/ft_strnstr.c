/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:29:37 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/08 16:29:44 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int		r;
	char	*str;

	str = (char *)big;
	if (!(*lit))
		return (str);
	while (*str != '\0' && len != 0)
	{
		if (*str == *lit)
		{
			r = 0;
			while (str[r] == lit[r] && r < (int)len && lit[r] != '\0')
				r++;
			if (lit[r] == '\0')
				return (str);
		}
		str++;
		len--;
	}
	return (NULL);
}
