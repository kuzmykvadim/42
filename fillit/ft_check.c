/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:18:20 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 17:06:28 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check(char *str)
{
	int		hash;
	int		dot;
	int		ends;
	char	*tmp;

	hash = 0;
	dot = 0;
	ends = 0;
	tmp = str;
	while (*str)
	{
		if (*str == '#')
			hash++;
		else if (*str == '.')
			dot++;
		else if (*str == '\n')
			ends++;
		else
			return (0);
		str++;
	}
	if ((str - tmp) > 545 || hash % 4 || dot % 12 || (ends + 1) % 5)
		return (0);
	return (1);
}

static int	sizes(char *s)
{
	return (ft_strlen(s));
}

int			ft_finalcheck(char *s)
{
	int		len;
	int		cont;

	if (ft_check(s) == 0 || ft_check4(s, 0) == 1)
	{
		return (0);
	}
	len = sizes(s);
	cont = 0;
	while (cont < len)
	{
		if (ft_blockcheck(&s[cont], '1') == 0)
		{
			return (0);
		}
		cont += 21;
	}
	return (1);
}
