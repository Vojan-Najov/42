/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:29:38 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/23 14:09:23 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "minirt_types.h"

/*	VECTORS */

t_vec3		vec3(double x, double y, double z);

void		vec3_add(t_vec3 v, t_vec3 u);

t_vec3		vec3_sum(t_vec3 v, t_vec3 u);

void		vec3_sub(t_vec3 v, t_vec3 u);

t_vec3		vec3_diff(t_vec3 v, t_vec3 u);

void		vec3_diff_vec3(t_vec3 v, t_vec3 u, t_vec3 w);

void		vec3_print(t_vec3 v);

void		vec3_mult_by(t_vec3 v, double k);

t_vec3		vec3_mult(t_vec3 v, double k);

double		vec3_dot(t_vec3 v, t_vec3 u);

void		vec3_cross_by(t_vec3 v, t_vec3 u);

t_vec3		vec3_cross(t_vec3 v, t_vec3 u);

double		vec3_norm(t_vec3 v);

double		vec3_length(t_vec3 v);

void		vec3_normalize(t_vec3 v);

int			vec3_collinearity(t_vec3 v, t_vec3 u);

/*	MATRIX */

t_mtrx44	mtrx44(double *m0, double *m1, double *m2, double *m3);

t_mtrx44	mtrx44_mult(t_mtrx44 a, t_mtrx44 b);

void		mtrx44_mult_by(t_mtrx44 *a, t_mtrx44 b);

t_mtrx44	mtrx44_transpose(t_mtrx44 m);

void		mtrx44_transpose_self(t_mtrx44 m);

t_mtrx44	mtrx44_inverse(t_mtrx44 m);

void		gauss_backward(double *b);

void		gauss_forward_row(double *b, int row);

void		mtrx48_swap_rows(double *b, int i, int j);

void		mtrx44_round(t_mtrx44 m);

void		mtrx44_print(t_mtrx44 m);

/*	VECTORS/POINTS MULT MATRIX */

t_vec3		vec_mult_mtrx(t_vec3 v, t_mtrx44 m);

t_vec3		vec_mult_proj_mtrx(t_vec3 v, t_mtrx44 m);

t_vec3		vec_dir_mult_mtrx(t_vec3 v, t_mtrx44 m);

/*	DEGREES */

double		deg2rad(int degree);

#endif

/*	



t_vec3		*spherical_to_cartesian(double theta, double phi);

double		spherical_theta(t_vec3 *v);

double		spherical_phi(t_vec3 *v);

double		cos_theta(t_vec3 *v);

double		sin2_theta(t_vec3 *v);

double		sin_theta(t_vec3 *v);

double		cos_phi(t_vec3 *v);

double		sin_phi(t_vec3 *v);

#endif
*/
