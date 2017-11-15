/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:00:07 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 01:05:59 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_lghtcam(char *p, t_env *e)
{
	if (!(p = ft_strstr(p, "|")))
	{
		puts("bad camera parameter");
		exit(1);
	}
	ft_pars_vect(&e->cam.pos, p);
	p++;
	if (!(p = ft_strstr(p, "/")))
	{
		puts("bad camera parameter");
		exit(1);
	}
	p++;
	e->cam.rot.p = ft_atoi(p);
	p++;
	ft_pars_digit(&p);
	e->cam.rot.j = ft_atoi(p);
	e->cam.rot.p *= M_PI / 180;
	e->cam.rot.j *= M_PI / 180;
	ft_costyl(e);
}

void		ft_init_lgt_and_cam(t_env *e, char *file)
{
	char *p;

	if (!(p = ft_strstr(file, "LIGHT\n")))
	{
		puts("bad light parameter");
		exit(1);
	}
	if (!(p = ft_strstr(p, "|")))
	{
		puts("bad light parameter");
		exit(1);
	}
	ft_pars_vect(&e->light.position, p);
	if (!(p = ft_strstr(file, "CAMERA\n")))
	{
		puts("bad camera parameter");
		exit(1);
	}
	ft_lghtcam(p, e);
}

char		*ft_read_file(t_env *e)
{
	char	*line;
	char	*str;
	char	*tmp;
	int		nb;

	line = NULL;
	if (!(str = (char*)malloc(sizeof(char))))
		return (0);
	while ((nb = get_next_line(e->fd, &line)))
	{
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, "\n\0");
		free(tmp);
		free(line);
	}
	free(line);
	if (nb < 0)
	{
		printf("fd error");
		exit(0);
	}
	return (str);
}

void		ft_parsing(t_env *e)
{
	char	*file;

	file = ft_read_file(e);
	ft_init_lgt_and_cam(e, file);
	ft_init_objects(e, file);
}
