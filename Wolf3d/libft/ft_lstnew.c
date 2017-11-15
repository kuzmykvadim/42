/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:36:52 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/08 15:59:10 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mylist;

	mylist = (t_list*)malloc(sizeof(t_list));
	if (!mylist)
		return (NULL);
	if (content)
	{
		if (!(mylist->content = malloc(content_size)))
			return (NULL);
		mylist->content_size = content_size;
		ft_memcpy(mylist->content, content, content_size);
	}
	else
	{
		mylist->content = NULL;
		mylist->content_size = 0;
	}
	mylist->next = NULL;
	return (mylist);
}
