/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blockcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:00:15 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 17:00:21 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_maincheck(int i, char c, char *s)
{
	if (s[i + 1] == '#')
	{
		s[i + 1] = c;
		ft_maincheck(i + 1, c, s);
	}
	if (s[i - 1] >= 0 && s[i - 1] == '#')
	{
		s[i - 1] = c;
		ft_maincheck(i - 1, c, s);
	}
	if (i + 5 <= 20 && s[i + 5] == '#')
	{
		s[i + 5] = c;
		ft_maincheck(i + 5, c, s);
	}
	if (i - 5 >= 0 && s[i - 5] == '#')
	{
		s[i - 5] = c;
		ft_maincheck(i - 5, c, s);
	}
	return (s);
}

int			ft_countchar(char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int			ft_blockcheck(char *s, char letter)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '#' && s[i])
		i++;
	s[i] = letter;
	str = ft_maincheck(i, letter, s);
	i = ft_countchar(str, letter);
	if (i != 4)
		return (0);
	else
		return (1);
}
