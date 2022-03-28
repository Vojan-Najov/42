/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_util_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:58 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/22 17:38:57 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "minirt_types.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>

void	add_coord(t_coord *coord, char *s)
{
	char	**tab;

	tab = ft_split(s, ',');
	if (str_tab_len(tab) != 3)
		print_err(WRONG_IDENT_COO);
	if (!check_float(tab[0]))
		print_err(NOT_DOUBLE);
	coord->x = ft_atof(tab[0]);
	if (!check_float(tab[1]))
		print_err(NOT_DOUBLE);
	coord->y = ft_atof(tab[1]);
	if (!check_float(tab[2]))
		print_err(NOT_DOUBLE);
	coord->z = ft_atof(tab[2]);
	free_str_tab(tab);
}

void	add_vector(t_vector *vector, char *s)
{
	char	**tab;

	tab = ft_split(s, ',');
	if (str_tab_len(tab) != 3)
		print_err(WRONG_IDENT_VEC);
	if (!check_float(tab[0]))
		print_err(NOT_DOUBLE);
	vector->x = ft_atof(tab[0]);
	if (vector->x < -1.0 || vector->x > 1.0)
		print_err(WRONG_RANGE_VECTOR);
	if (!check_float(tab[1]))
		print_err(NOT_DOUBLE);
	vector->y = ft_atof(tab[1]);
	if (vector->y < -1.0 || vector->y > 1.0)
		print_err(WRONG_RANGE_VECTOR);
	if (!check_float(tab[2]))
		print_err(NOT_DOUBLE);
	vector->z = ft_atof(tab[2]);
	if (vector->z < -1.0 || vector->z > 1.0)
		print_err(WRONG_RANGE_VECTOR);
	if (fabs(vector->x) < g_eps && fabs(vector->y) < g_eps
		&& fabs(vector->z) < g_eps)
		print_err(WRONG_RANGE_VECTOR_3_0);
	free_str_tab(tab);
}

void	add_color(double *col, char *s)
{
	char	**tab;
	t_color	color;

	tab = ft_split(s, ',');
	if (str_tab_len(tab) != 3)
		print_err(WRONG_IDENT_AL);
	color.red = ft_atoi(tab[0]);
	if (color.red < 0 || color.red > 255)
		print_err(WRONG_RANGE__ALBEDO);
	color.green = ft_atoi(tab[1]);
	if (color.green < 0 || color.green > 255)
		print_err(WRONG_RANGE__ALBEDO);
	color.blue = ft_atoi(tab[2]);
	if (color.blue < 0 || color.blue > 255)
		print_err(WRONG_RANGE__ALBEDO);
	free_str_tab(tab);
	col[er] = (double) color.red / 255.;
	col[eb] = (double) color.blue / 255.;
	col[eg] = (double) color.green / 255.;
}

void	add_color_amb(double *col, char *s)
{
	char	**tab;
	t_color	color;

	tab = ft_split(s, ',');
	if (str_tab_len(tab) != 3)
		print_err(WRONG_IDENT_COL);
	color.red = ft_atoi(tab[0]);
	if (color.red < 0 || color.red > 255)
		print_err(WRONG_RANGE_COLOR);
	color.green = ft_atoi(tab[1]);
	if (color.green < 0 || color.green > 255)
		print_err(WRONG_RANGE_COLOR);
	color.blue = ft_atoi(tab[2]);
	if (color.blue < 0 || color.blue > 255)
		print_err(WRONG_RANGE_COLOR);
	free_str_tab(tab);
	col[er] = (double) color.red;
	col[eb] = (double) color.blue;
	col[eg] = (double) color.green;
}
