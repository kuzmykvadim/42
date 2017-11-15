/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:39:14 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/10/18 11:55:48 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_lightning(t_env *e)
{
	int k;

	k = rand() % 30;
	e->smoke_off = k;
}

void		ft_check_map(t_env *e)
{
	int x;
	int y;

	y = 0;
	while (y < e->map_height - 1)
	{
		x = 0;
		while (x < e->map_width - 1)
		{
			if (e->map[y][x] != 0 && e->map[y][x] != 1)
				ft_parse_error("Map error. Use 1 or 0 only");
			x++;
		}
		y++;
	}
}

int			ft_read_file(t_env *e)
{
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	if (!(ft_parse_control(e->fd, e)))
		ft_parse_error("Control parsing error");
	e->map = (int**)ft_memalloc(sizeof(int*) * e->map_height);
	while (get_next_line(e->fd, &line) == 1)
	{
		if (!(ft_write_map(&line, ++i, e)))
			return (0);
		ft_strdel(&line);
	}
	if (e->map[(int)e->object.play_pos.x][(int)e->object.play_pos.y] == 1)
		ft_parse_error("Error. Player position on wall");
	ft_strdel(&line);
	print_map(e);
	ft_check_map(e);
	return (1);
}

void		ft_parsing(t_env *e)
{
	int		read;

	e->object.play_pos.x = 0;
	e->object.play_pos.y = 0;
	e->object.play_dir.x = -1;
	e->object.play_dir.y = 0;
	e->object.i = 0;
	e->object.plane.x = 0;
	e->object.plane.y = 0.66;
	e->object.step_move = 0.30;
	e->object.step_rotate = 0.20;
	e->win_width = W_SIZE_W;
	e->win_height = W_SIZE_H;
	e->color1 = COLOR1;
	e->color2 = COLOR2;
	e->color3 = COLOR3;
	e->color4 = COLOR4;
	e->sky_col = SKY;
	e->ground_col = GROUND;
	e->iter1 = 1;
	read = ft_read_file(e);
}

int			ft_map_init(t_env *e, char *file)
{
	if (open(file, O_DIRECTORY) >= 0)
		ft_parse_error("Open file map error");
	if (!(e->fd = open(file, O_RDONLY)))
		ft_parse_error("Open file map error");
	ft_parsing(e);
	return (1);
}
