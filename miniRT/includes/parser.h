/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:50:32 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/15 21:16:08 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "parse_struct.h"
# include "minirt_types.h"

void	add_coord(t_coord *coord, char *s);
void	add_color(double *col, char *s);
void	add_color_amb(double *col, char *s);
void	add_vector(t_vector *vector, char *s);
int		get_type_of_figure(char *str);
void	add_sphere(t_obj **obj, char **tab);
void	add_plane(t_obj **obj, char **tab);
void	add_cylindre(t_obj **obj, char **tab);
void	add_ambient(char **tab);
void	add_camera(char **tab);
void	add_light(char **tab);
void	add_figure(char **tab);

#endif
