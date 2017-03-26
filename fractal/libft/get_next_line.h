/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:33:10 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/02/11 22:33:42 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 3

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int					get_next_line(const int fd, char **line);

typedef	struct		s_data
{
	char			*buff;
	int				fd;
	struct s_data	*next;
}					t_data;

#endif
