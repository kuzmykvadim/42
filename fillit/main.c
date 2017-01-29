/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:54:35 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/28 17:05:09 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	bug(int argc, char **argv)
{
	int		fd;
	char	buf[4096];

	ft_bzero(buf, 4096);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDWR);
	read(fd, buf, 2048);
	if (ft_finalcheck(buf) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

static int	mainc(char **argv, int i, int map_size, int count)
{
	char	**arr;
	char	buf[4096];
	char	**maps;
	int		block[2];
	int		fd;

	maps = NULL;
	ft_bzero(buf, 4096);
	fd = open(argv[1], O_RDWR);
	read(fd, buf, 2048);
	arr = ft_tetra(argv, count);
	block[0] = ft_count_block(buf, '#');
	block[1] = map_size;
	while (block[1] * block[1] < block[0] * 4)
		block[1] = block[1] + 1;
	while (!ft_logic((maps = ft_map_gen(block[1])), arr, 0, block))
		block[1] = block[1] + 1;
	i = 0;
	while (i < block[1])
	{
		ft_putstr(maps[i++]);
		ft_putchar('\n');
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		i;
	int		map_size;
	int		count;

	count = 0;
	i = 0;
	map_size = 2;
	if (bug(argc, argv) == 1)
		return (0);
	else
		mainc(argv, i, map_size, count);
	return (0);
}
