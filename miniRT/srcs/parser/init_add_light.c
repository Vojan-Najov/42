/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:33:02 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/18 01:07:00 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "utils.h"
#include "libft.h"
#include "parser.h"
#include "geometry.h"

t_light	**get_light_adress(void)
{
	static t_light	*light;

	return (&light);
}

t_light	*get_light(void)
{
	t_light	**light;

	light = get_light_adress();
	return (*light);
}

void	add_light(char **tab)
{
	t_light	**light;
	t_coord	coord;

	if (str_tab_len(tab) != 2)
		print_err(WRONG_IDENT_LIGHT);
	light = get_light_adress();
	if (*light)
		print_err(UNIQ_LIGHT);
	*light = malloc(sizeof(t_light));
	if (!light)
		print_err(MALLOC);
	add_coord(&coord, tab[0]);
	(*light)->orig = vec3(coord.x, coord.y, coord.z);
	if (check_float(tab[1]))
		(*light)->ratio = ft_atof(tab[1]);
	else
		print_err(NOT_DOUBLE);
	if ((*light)->ratio < 0.0 || (*light)->ratio > 1.0)
		print_err(WRONG_RANGE_RATIO);
}

void	free_light(void)
{
	t_light	**light;

	light = get_light_adress();
	free((*light)->orig);
	(*light)->orig = NULL;
	free(*light);
}
