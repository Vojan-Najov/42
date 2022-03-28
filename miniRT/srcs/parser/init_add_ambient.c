/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_ambient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:33:12 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/11 13:54:42 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "minirt_types.h"
#include "utils.h"
#include "libft.h"
#include "parser.h"

static t_ambient	**get_ambient_adress(void)
{
	static t_ambient	*ambient;

	return (&ambient);
}

t_ambient	*get_ambient(void)
{
	t_ambient	**ambient;

	ambient = get_ambient_adress();
	return (*ambient);
}

void	add_ambient(char **tab)
{
	t_ambient	**ambient;

	if (str_tab_len(tab) != 2)
		print_err(WRONG_IDENT_AMB);
	ambient = get_ambient_adress();
	if (*ambient)
		print_err(UNIQ_AMB);
	*ambient = malloc(sizeof(t_ambient));
	if (!ambient)
		print_err(MALLOC);
	if (!check_float(tab[0]))
		print_err(NOT_DOUBLE);
	(*ambient)->ratio = ft_atof(tab[0]);
	if ((*ambient)->ratio < 0.0 && (*ambient)->ratio > 1.0)
		print_err(WRONG_RANGE_AMBIENT_RATIO);
	add_color_amb((*ambient)->color, tab[1]);
}

void	free_ambient(void)
{
	t_ambient	**amb;

	amb = get_ambient_adress();
	free((*amb));
	*amb = NULL;
}
