/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:13:04 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/06 15:24:09 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				size;
	int				i;
	unsigned int	k;

	if (!s || !f)
		return (NULL);
	i = 0;
	k = 0;
	size = ft_strlen(s);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(k, s[i]);
		i++;
		k++;
	}
	return (str);
}
