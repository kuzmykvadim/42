/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:00:02 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/01 21:39:27 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	begin(char const *s)
{
	int b;

	b = 0;
	while ((s[b] == ' ' || s[b] == '\t' || s[b] == '\n') && s[b])
		b++;
	return (b);
}

static int	end(char const *s)
{
	int	e;

	e = 0;
	while (*s)
	{
		e++;
		s++;
	}
	s--;
	while ((*s == ' ' || *s == '\t' || *s == '\n') && --e > 0)
		s--;
	return (e);
}

char		*ft_strtrim(char const *s)
{
	int		bn;
	int		ed;
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	bn = begin(s);
	ed = end(s);
	if (ed-- == 0)
	{
		if (!(str = (char *)malloc(1)))
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (!(str = (char *)malloc((ed - bn + 1) + 1)))
		return (NULL);
	while (bn <= ed)
		str[i++] = s[bn++];
	str[i] = '\0';
	return (str);
}
