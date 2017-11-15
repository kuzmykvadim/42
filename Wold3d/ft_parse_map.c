/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:06:17 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/10/20 16:06:19 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_parse_control(int fd, t_env *e)
{
	char	*line;
	char	*p;

	line = NULL;
	if (get_next_line(fd, &line) < 1)
		ft_parse_error("Control parsing error");
	if (!(p = ft_strstr(line, "m_width:")))
		ft_parse_error("Wrong parameter m_width");
	e->map_width = ft_atoi(p + 8);
	if (!(p = ft_strstr(line, "m_height:")))
		ft_parse_error("Wrong parameter m_height");
	e->map_height = ft_atoi(p + 9);
	if (!(p = ft_strstr(line, "pos_x:")))
		ft_parse_error("Wrong parameter pos_x");
	e->object.play_pos.x = ft_atoi(p + 6);
	if (!(p = ft_strstr(line, "pos_y:")))
		ft_parse_error("Wrong parameter pos_y");
	e->object.play_pos.y = ft_atoi(p + 6);
	if (e->map_width < 0 || e->map_height < 0 || e->object.play_pos.x < 0 ||
		e->object.play_pos.y < 0 || e->object.play_pos.x >= e->map_width ||
		e->object.play_pos.y >= e->map_height)
		ft_parse_error("Error map in set parameters");
	ft_strdel(&line);
	return (1);
}

void	ft_arrdel(char ***arr)
{
	char	**tmp;
	int		i;

	tmp = *arr;
	i = 0;
	if (!arr)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	*arr = NULL;
}

int		ft_write_map(char **line, int i, t_env *e)
{
	int		x;
	char	**arr;

	x = -1;
	arr = ft_strsplit(*line, ' ');
	if (!(e->map[i] = (int *)ft_memalloc(sizeof(int) * e->map_width)))
		exit(1);
	while (arr[++x])
	{
		if (ft_atoi(arr[x]) > 1 || ft_atoi(arr[x]) < 0 || x > e->map_width)
			ft_parse_error("Wrong map, only 1 or 0");
		e->map[i][x] = ft_atoi(arr[x]);
	}
	if (x != e->map_width)
		ft_parse_error("Error map_width");
	ft_arrdel(&arr);
	return (1);
}

void	print_map(t_env *e)
{
	int	x;
	int	y;

	y = 0;
	while (y < e->map_height)
	{
		x = 0;
		if (e->map[y][0] == 0 || e->map[y][e->map_width - 1] == 0)
			ft_parse_error("border map error");
		while (x < e->map_width)
		{
			if (e->map[0][x] == 0 || e->map[e->map_height - 1][x] == 0)
				ft_parse_error("border map error");
			x++;
		}
		y++;
	}
}
