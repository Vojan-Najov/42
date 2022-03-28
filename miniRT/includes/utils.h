/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:49:51 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/25 17:55:19 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

# define MALLOC "malloc"
# define WRONG_NAME "wrong name of file. File name must end with \".rt\""
# define WRONG_IDENT "wrong name of identificator in file"
# define WRONG_IDENT_LIGHT "wrong identificator in LIGHT"
# define WRONG_IDENT_CAMERA "wrong identificator in CAMERA"
# define WRONG_IDENT_AMB "wrong identificator in AMBIENT"
# define WRONG_IDENT_SP "wrong identificator in SPHERE"
# define WRONG_IDENT_CY "wrong identificator in CYLINDRE"
# define WRONG_IDENT_PL "wrong identificator in PLANE"
# define WRONG_IDENT_COO "wrong identificator in COORD"
# define WRONG_IDENT_VEC "wrong identificator in VECTOR"
# define WRONG_IDENT_COL "wrong identificator in COLOR"
# define WRONG_IDENT_AL "wrong identificator in ALBEDO"
# define UNIQ_AMB "must be uniq amb_light"
# define UNIQ_CAMERA "must be uniq camera"
# define UNIQ_LIGHT "must be uniq light"
# define NOT_DOUBLE "must be a double type"
# define NOT_INT "must be int type"
# define WRONG_RANGE_SP_R "wrong range of R in sphere (0, MAX_DOUBLE]"
# define WRONG_RANGE_CY_R_H "wrong range of R or H in cylindre"
# define WRONG_RANGE_RATIO "wrong range in LIGHT RATIO"
# define WRONG_RANGE_AMBIENT_RATIO "wrong range in AMBIENT RATIO"
# define WRONG_RANGE_CAM_FOV "wrong range in CAMERA FOV [0,180]"
# define WRONG_RANGE_VECTOR "wrong range in VECTOR [-1,1]"
# define WRONG_RANGE_VECTOR_3_0 "wrong range in VECTOR three of 0 [-1,1]"
# define WRONG_RANGE__ALBEDO "wrong range in ALBEDO [0, 255]"
# define WRONG_RANGE_COLOR "wrong range in COLOR [0, 255]"

# define WRONG_NUM_ARGS "wrong number of arguments"

void	print_err(const char *s);
void	print_err_open(const char *file_name);
void	free_str_tab(char **tab);
size_t	str_tab_len(char **tab);
void	free_ambient(void);
void	free_camera(void);
void	free_light(void);

#endif
