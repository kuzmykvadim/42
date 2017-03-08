/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:34:13 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/03/06 11:26:57 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_pixels(char *line, int nb_line, t_pixel ***arr_pixel)
{
	char	**arr_str;
	t_pixel	*a_pixel;
	int		i;

	i = 0;
	arr_str = ft_strsplit(line, ' ');
	while (arr_str[i] != 0)
		i++;
	if (!((*arr_pixel) = (t_pixel**)malloc(sizeof(t_pixel) * i)))
		puts("malloc error");
	i = 0;
	while (arr_str[i] != 0)
	{
		a_pixel = (t_pixel*)malloc(sizeof(t_pixel));
		a_pixel->x = i * STEP_X;
		a_pixel->y = nb_line * STEP_Y;
		a_pixel->z = ft_atoi(arr_str[i]) * ZOOM_Z;
		a_pixel->s = 1;
		a_pixel->z_color = a_pixel->z;
		(*arr_pixel)[i] = a_pixel;
		i++;
	}
	return (i);
}

int		ft_map_line(char *map)
{
	int		fd;
	int		new_l;
	char	buff;

	fd = 0;
	new_l = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		puts("map error");
	while (read(fd, &buff, 1))
	{
		if (buff == '\n')
			new_l++;
	}
	close(fd);
	return (new_l);
}

t_map	*ft_parse_map(char **argv, int fd)
{
	char	*line;
	int		nb_line;
	t_map	*map;
	t_line	*m_line;
	t_pixel	**arr_pixel;

	nb_line = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))) ||
			!(map->lines = (t_line**)malloc(sizeof(t_line)
					* ft_map_line(argv[1]))))
		puts("malloc arror");
	map->len = 0;
	if ((fd = open(argv[1], O_RDONLY)) > 0)
	{
		while ((get_next_line(fd, &line)) > 0)
		{
			if (!(m_line = (t_line*)malloc(sizeof(t_line))))
				puts("malloc error");
			m_line->len = ft_pixels(line, nb_line, &arr_pixel);
			m_line->pixels = arr_pixel;
			map->lines[nb_line++] = m_line;
		}
		map->len = nb_line;
	}
	return (map);
}
