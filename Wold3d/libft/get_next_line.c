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

int		fu_fu(char **l, char **blc)
{
	char	*tmp;

	tmp = (*l);
	if (((*blc) = ft_strchr((*l), '\n')))
	{
		*(*blc) = 0;
		(*l) = ft_strdup((*l));
		(*blc) = ft_strdup((*blc + 1));
		free(tmp);
		return (1);
	}
	return (0);
}

int		fu_read(const int fd, char **l, char **blc)
{
	char	tmp[BUFF_SIZE + 1];
	int		res;

	ft_bzero(tmp, BUFF_SIZE + 1);
	if (fu_fu(l, blc))
		return (1);
	while ((res = read(fd, &tmp, BUFF_SIZE)) != 0 && res != -1)
	{
		*blc = *l;
		(*l) = ft_strjoin((*l), tmp);
		free(*blc);
		if (fu_fu(l, blc))
			return (1);
		ft_bzero(tmp, BUFF_SIZE + 1);
	}
	(*blc) = ft_strdup("\0");
	if (!(*l) || !(*l)[0])
		return (res);
	return (1);
}

void	kostil(t_list **lst, char *tmp, int fd)
{
	ft_lstadd(lst, ft_lstnew("\0", 0));
	free((*lst)->content);
	(*lst)->content = (void *)ft_strdup(tmp);
	(*lst)->content_size = fd;
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tlst;
	char			*tmp;
	int				res;

	if (!line)
		return (-1);
	tlst = lst;
	while (tlst && (const int)tlst->content_size != fd)
		tlst = tlst->next;
	(*line) = ft_strdup(tlst != 0 ? tlst->content : "\0");
	if ((res = fu_read((int)fd, line, &tmp)) == -1 || res == 0)
	{
		free(tmp);
		return (res);
	}
	if (tlst)
	{
		free(tlst->content);
		tlst->content = (void *)ft_strdup(tmp == 0 ? "\0" : tmp);
	}
	else
		kostil(&lst, tmp, fd);
	free(tmp);
	return (1);
}
