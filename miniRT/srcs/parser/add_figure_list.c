/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_figure_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:45:51 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/14 19:37:37 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "utils.h"
#include "libft.h"
#include "parser.h"
#include "obj_list.h"
#include "geometry.h"
#include "ray_tracer.h"
#include <stdlib.h>
#include <math.h>

void	add_sphere(t_obj **obj, char **tab)
{
	t_obj	*sp;
	t_coord	coord;

	if (str_tab_len(tab) != 3)
		print_err(WRONG_IDENT_SP);
	sp = *obj;
	add_coord(&coord, tab[0]);
	sp->orig = vec3(coord.x, coord.y, coord.z);
	sp->dir = NULL;
	if (!check_float(tab[1]))
		print_err(WRONG_IDENT_SP);
	sp->r = ft_atof(tab[1]) / 2.;
	if (sp->r <= g_eps)
		print_err(WRONG_RANGE_SP_R);
	sp->r2 = sp->r * sp->r;
	add_color(sp->albedo, tab[2]);
	sp->intersect = intersect_sphere;
	sp->surface = surface_sphere;
	sp->inside = 0;
}

void	add_plane(t_obj **obj, char **tab)
{
	t_obj		*pl;
	t_coord		coord;
	t_vector	vector;

	if (str_tab_len(tab) != 3)
		print_err(WRONG_IDENT_PL);
	pl = *obj;
	add_coord(&coord, tab[0]);
	pl->orig = vec3(coord.x, coord.y, coord.z);
	add_vector(&vector, tab[1]);
	pl->dir = vec3(vector.x, vector.y, vector.z);
	vec3_normalize(pl->dir);
	add_color(pl->albedo, tab[2]);
	pl->intersect = intersect_plane;
	pl->surface = surface_plane;
	pl->inside = 0;
}

void	add_cylindre(t_obj **obj, char **tab)
{
	t_obj		*cy;
	t_coord		coord;
	t_vector	vector;

	if (str_tab_len(tab) != 5)
		print_err(WRONG_IDENT_CY);
	cy = *obj;
	add_coord(&coord, tab[0]);
	cy->orig = vec3(coord.x, coord.y, coord.z);
	add_vector(&vector, tab[1]);
	cy->dir = vec3(vector.x, vector.y, vector.z);
	vec3_normalize(cy->dir);
	if (!check_float(tab[2]) || !check_float(tab[3]))
		print_err(WRONG_IDENT_CY);
	cy->r = ft_atof(tab[2]) / 2.;
	cy->h = ft_atof(tab[3]);
	if (cy->r <= g_eps || cy->h <= g_eps)
		print_err(WRONG_RANGE_CY_R_H);
	cy->r2 = cy->r * cy->r;
	add_color(cy->albedo, tab[4]);
	cy->intersect = intersect_cylinder;
	cy->surface = surface_cylinder;
	cy->inside = 0;
}

void	add_figure(char **tab)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (!obj)
		print_err(MALLOC);
	if (get_type_of_figure(tab[0]) == SPHERE)
		add_sphere(&obj, tab + 1);
	else if (get_type_of_figure(tab[0]) == PLANE)
		add_plane(&obj, tab + 1);
	else if (get_type_of_figure(tab[0]) == CYLINDRE)
		add_cylindre(&obj, tab + 1);
	ft_objlst_add_back(ft_objlst_new(obj));
}
