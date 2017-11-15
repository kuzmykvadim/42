/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:22:03 by vkuzmyk           #+#    #+#             */
/*   Updated: 2016/12/05 16:37:38 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newl;

	if (lst)
	{
		newl = (t_list*)malloc(sizeof(t_list));
		if (newl)
		{
			newl = f(lst);
			newl->next = ft_lstmap(lst->next, f);
			return (newl);
		}
	}
	return (NULL);
}
