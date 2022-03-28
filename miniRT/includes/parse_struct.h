/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:56:21 by jjoan             #+#    #+#             */
/*   Updated: 2022/03/10 22:10:37 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_STRUCT_H
# define PARSE_STRUCT_H

# define SPHERE 1
# define PLANE 2
# define CYLINDRE 3

//utiles_types
typedef struct s_triple_double	t_coord;
typedef struct s_triple_double	t_vector;
typedef struct s_color			t_color;

struct s_triple_double
{
	double	x;
	double	y;
	double	z;
};

struct s_color
{
	int	red;
	int	green;
	int	blue;
};

#endif
