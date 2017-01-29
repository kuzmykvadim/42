/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:31:23 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/27 19:15:37 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	arrcount(char const *s, char c)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (!s)
		return (b);
	while (s[a])
	{
		while (s[a] == c)
		{
			if ((s[a + 1] != c && s[a + 1]) || (s[a] != c && s[a + 1]))
				b++;
			a++;
		}
		if (s[a])
			a++;
	}
	if ((s[a - 1] != c && s[0] != c) || (s[a - 1] == c && s[0] != c))
		b = b + 1;
	return (b);
}

static char	**memory(int arrcn, char const *s, char c, int i)
{
	int		d;
	int		e;
	char	**g;

	d = 0;
	e = 0;
	if (!(g = (char **)malloc(sizeof(char*) * (arrcn + 1))))
		return (NULL);
	while (e < arrcn)
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i++] != c && s[i])
			d++;
		if (!(g[e] = (char*)malloc(d + 1)))
			return (NULL);
		d = 0;
		e++;
	}
	return (g);
}

static char	**fillmem(char **b, char const *s, char c, int arrcn)
{
	int d;
	int e;
	int f;

	d = 0;
	e = 0;
	f = 0;
	while (s[d])
	{
		while (s[d] == c && s[d])
			d++;
		while (s[d] != c && s[d])
			b[f][e++] = s[d++];
		if (f < arrcn)
		{
			b[f][e] = '\0';
			f++;
			e = 0;
		}
	}
	b[f] = NULL;
	return (b);
}

char		**ft_strsplit(char const *s, char c)
{
	int		arrcn;
	int		i;
	char	**mem;
	char	**res;

	i = 0;
	if (!s || !c)
		return (NULL);
	arrcn = arrcount(s, c);
	if (!(mem = memory(arrcn, s, c, i)))
		return (NULL);
	res = fillmem(mem, s, c, arrcn);
	return (res);
}
