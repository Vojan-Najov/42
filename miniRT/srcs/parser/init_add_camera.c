/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:41:04 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/18 01:10:57 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_struct.h"
#include "minirt_types.h"
#include "utils.h"
#include "libft.h"
#include "parser.h"
#include "geometry.h"

static t_camera	**get_camera_adress(void)
{
	static t_camera	*camera;

	return (&camera);
}

t_camera	*get_camera(void)
{
	t_camera	**camera;

	camera = get_camera_adress();
	return (*camera);
}

void	add_camera(char **tab)
{
	t_camera	**camera;
	t_coord		coord;
	t_vector	vector;
	int			fov;

	if (str_tab_len(tab) != 3)
		print_err(WRONG_IDENT_CAMERA);
	camera = get_camera_adress();
	if (*camera)
		print_err(UNIQ_CAMERA);
	*camera = malloc(sizeof(t_camera));
	if (!camera)
		print_err(MALLOC);
	add_coord(&coord, tab[0]);
	(*camera)->orig = vec3(coord.x, coord.y, coord.z);
	add_vector(&vector, tab[1]);
	(*camera)->dir = vec3(vector.x, vector.y, vector.z);
	vec3_normalize((*camera)->dir);
	if (!check_int(tab[2]))
		print_err(NOT_INT);
	fov = ft_atoi(tab[2]);
	if (fov < 0 || fov > 180)
		print_err(WRONG_RANGE_CAM_FOV);
	(*camera)->fovhalf = deg2rad(fov) / 2.;
}

void	free_camera(void)
{
	t_camera	**cam;

	cam = get_camera_adress();
	free((*cam)->dir);
	(*cam)->dir = NULL;
	free((*cam)->orig);
	(*cam)->orig = NULL;
	free(*cam);
	*cam = NULL;
}
