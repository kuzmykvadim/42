/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:30:37 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/05 15:31:00 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_dich(char *buff, int i)
{
	unsigned char	*str;
	unsigned int	ntmp;

	ntmp = 0;
	str = ft_memalloc(i + 1);
	if (!str)
		return (NULL);
	while (--i >= 0)
	{
		str[ntmp] = buff[i];
		ntmp++;
	}
	str[ntmp] = '\0';
	return ((char*)str);
}

char		*ft_itoa(int n)
{
	char			buff[100];
	char			*str;
	int				i;
	unsigned int	ntmp;

	i = 0;
	ntmp = n;
	if (n < 0)
		ntmp = -n;
	while (ntmp > 0)
	{
		buff[i++] = (ntmp % 10) + 48;
		ntmp = ntmp / 10;
	}
	if (n < 0)
		buff[i++] = '-';
	if (n == 0)
	{
		str = malloc(2);
		str[0] = '0';
		str[1] = '\0';
	}
	else
		str = ft_dich(buff, i);
	return ((char*)str);
}
