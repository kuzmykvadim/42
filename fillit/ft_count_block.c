/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:39:38 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 16:41:29 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_block(char *s, char c)
{
	int	i;
	int	h;
	int	bl;

	i = 0;
	h = 0;
	while (s[i])
	{
		if (s[i] == c)
			h++;
		i++;
	}
	bl = h / 4;
	return (bl);
}
