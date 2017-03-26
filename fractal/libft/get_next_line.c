/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:16:56 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/01/27 15:12:43 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_new_line(char **line, char **tmp)
{
	char	*tmp1;

	tmp1 = *line;
	if ((*tmp = ft_strchr(*line, '\n')) != NULL)
	{
		**tmp = '\0';
		*tmp = ft_strdup(*tmp + 1);
		*line = ft_strdup(*line);
		free(tmp1);
		return (1);
	}
	return (0);
}

static int	ft_read(char **line, char **tmp, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		res;

	if (find_new_line(line, tmp) == 1)
		return (1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		*tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(*tmp);
		if (find_new_line(line, tmp) == 1)
			return (1);
		ft_bzero(buff, BUFF_SIZE);
	}
	*tmp = ft_strdup("\0");
	if (**line)
		return (1);
	return (res);
}

static void	ft_multi(t_data **data, int fd, char **tmp)
{
	t_data	*lst;

	lst = (t_data*)malloc(sizeof(t_data));
	lst->buff = *tmp;
	lst->fd = fd;
	lst->next = *data;
	*data = lst;
}

int			get_next_line(int fd, char **line)
{
	static t_data	*data;
	t_data			*lst;
	char			*tmp;
	int				res;

	if (line == NULL)
		return (-1);
	lst = data;
	while (lst && lst->fd != fd)
		lst = lst->next;
	*line = ft_strdup(lst == 0 ? "\0" : lst->buff);
	if (lst)
		free(lst->buff);
	if ((res = ft_read(line, &tmp, fd)) != 1)
		return (res);
	if (!lst)
		ft_multi(&data, fd, &tmp);
	else
		lst->buff = ft_strdup(tmp);
	return (1);
}
