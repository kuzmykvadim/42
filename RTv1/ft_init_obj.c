/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:43:45 by vkuzmyk           #+#    #+#             */
/*   Updated: 2017/06/04 02:16:27 by vkuzmyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_rotate_objects(t_object *obj, char *prs)
{
	char	*ptr;
	double	t;

	obj->rot.flag = 0;
	if (!(ptr = ft_strchr(prs, '<')))
		exit(1);
	ptr++;
	t = ft_atoi(ptr) * M_PI / 180;
	if (t)
		obj->rot = ft_rotate_x(t);
	ft_pars_digit(&ptr);
	t = ft_atoi(ptr) * M_PI / 180;
	if (obj->rot.flag && t)
		obj->rot = ft_matr_multipl(obj->rot, ft_rotate_y(t));
	else if (t)
		obj->rot = ft_rotate_y(t);
	ft_pars_digit(&ptr);
	t = ft_atoi(ptr) * M_PI / 180;
	if (obj->rot.flag && t)
		obj->rot = ft_matr_multipl(obj->rot, ft_rotate_z(t));
	else if (t)
		obj->rot = ft_rotate_z(t);
	if (obj->rot.flag)
		obj->inv = ft_matrix_init(obj->rot);
}

void	ft_change_obj(t_object *obj, char *prs)
{
	char	*ptr;

	if (obj->type == PLANE)
	{
		if (!(ptr = ft_strstr(prs, "{")))
		{
			puts("Specify the coordinate for the plane");
			exit(1);
		}
		ft_pars_vect(&obj->norm, ptr);
	}
	ft_rotate_objects(obj, prs);
	if (obj->type == CONE)
		obj->radius *= M_PI / 180;
	obj->radius *= obj->radius;
}

void	ft_multiobj(t_env *e, t_object add)
{
	int			i;
	t_object	*new;

	i = -1;
	new = (t_object*)malloc(sizeof(t_object) * (e->nb_obj + 1));
	while (++i < e->nb_obj)
		new[i] = e->obj[i];
	new[i] = add;
	free(e->obj);
	e->obj = new;
	e->nb_obj++;
}

void	ft_init_obj1(char *p, t_object *obj)
{
	if (!(p = ft_strstr(p, "[")))
	{
		puts("object radius error");
		exit(1);
	}
	p++;
	if ((obj->radius = ft_atoi(p)) < 0)
	{
		puts("radius error");
		exit(1);
	}
	if (!(p = ft_strstr(p, "|")))
	{
		puts("color error");
		exit(1);
	}
	obj->color = ft_get_color(++p);
}

void	ft_init_objects(t_env *e, char *file)
{
	char		*p;
	t_object	obj;

	p = file;
	while ((p = ft_strstr(p, "#")))
	{
		while (!(ft_isalpha((int)*p)))
			p++;
		if (!(obj.type = ft_obj_type(p)))
		{
			puts("object type error");
			exit(1);
		}
		if (!(p = ft_strstr(p, "|")))
		{
			puts("object position error");
			exit(1);
		}
		ft_pars_vect(&obj.center, p);
		ft_init_obj1(p, &obj);
		ft_change_obj(&obj, p);
		ft_multiobj(e, obj);
	}
}
