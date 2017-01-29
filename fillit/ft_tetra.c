/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:52:00 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 16:38:50 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_tetra(char **argv, int count)
{
	char	s[40];
	int		fd;
	char	**arr;
	char	**mas;
	char	block[4096];

	fd = 0;
	ft_bzero(s, 40);
	ft_bzero(block, 4096);
	fd = open(argv[1], O_RDWR);
	read(fd, block, 2048);
	close(fd);
	fd = open(argv[1], O_RDWR);
	mas = (char**)malloc(sizeof(char*) * (ft_count_block(block, '#') + 1));
	while (read(fd, s, 21))
	{
		ft_shift(s);
		arr = ft_strsplit(s, '\n');
		mas[count] = (char*)malloc(10);
		mas[count] = ft_coordinate(arr, 'A' + count);
		count++;
	}
	close(fd);
	return (mas);
}
