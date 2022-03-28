/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:25:19 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 21:27:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

# define WIDTH 1024
# define HEIGHT 768

static const double	g_eps = 1.E-14;

static const double	g_inf = 1.E100;

static const double	g_light = 255.0;

static const double	g_bias = 1.E-5;

static const double	g_dwidth = (double) WIDTH;

static const double	g_dheight = (double) HEIGHT;

static const double	g_resize_ratio_plus = 1.1;

static const double	g_resize_ratio_minus = 0.9;

static const double	g_translation_ratio = 0.1;

static const double	g_rotcos = 0.965926;

static const double	g_rotsin = 0.258819;

static const double	g_mtrx_rotx[16] = {1., 0., 0., 0., \
										0., g_rotcos, -g_rotsin, 0., \
										0., g_rotsin, g_rotcos, 0., \
										0., 0., 0., 1.};

static const double	g_mtrx_rotx_con[16] = {1., 0., 0., 0., \
											0., g_rotcos, g_rotsin, 0., \
											0., -g_rotsin, g_rotcos, 0., \
											0., 0., 0., 1.};

static const double	g_mtrx_roty[16] = {g_rotcos, 0., g_rotsin, 0., \
										0., 1., 0., 0., \
										-g_rotsin, 0., g_rotcos, 0., \
										0., 0., 0., 1.};

static const double	g_mtrx_roty_con[16] = {g_rotcos, 0., -g_rotsin, 0., \
											0., 1., 0., 0., \
											g_rotsin, 0., g_rotcos, 0., \
											0., 0., 0., 1.};

static const double	g_mtrx_rotz[16] = {g_rotcos, -g_rotsin, 0., 0., \
										g_rotsin, g_rotcos, 0., 0., \
										0., 0., 1., 0., \
										0., 0., 0., 1.};

static const double	g_mtrx_rotz_con[16] = {g_rotcos, g_rotsin, 0., 0., \
											-g_rotsin, g_rotcos, 0., 0., \
											0., 0., 1., 0., \
											0., 0., 0., 1.};

typedef double *	t_vec3;

typedef double *	t_mtrx44;

enum	e_coord
{
	ex = 0,
	ey = 1,
	ez = 2
};

enum	e_color
{
	er = 0,
	eg = 1,
	eb = 2
};

typedef struct s_ray
{
	double	orig[3];
	double	dir[3];
}			t_ray;

typedef struct s_light
{
	t_vec3	orig;
	double	ratio;
}			t_light;

typedef struct s_ambient
{
	double	ratio;
	double	color[3];
}			t_ambient;

typedef struct s_camera
{
	t_vec3	orig;
	t_vec3	dir;
	double	fovhalf;
}			t_camera;

typedef struct s_obj
{
	int		(*intersect)(struct s_obj *self, t_ray *ray, double *t);
	void	(*surface)(struct s_obj *self, t_ray *ray, double *t);
	t_vec3	orig;
	t_vec3	dir;
	double	r2;
	double	h;
	double	point[3];
	double	normal[3];
	double	t[4];
	double	albedo[3];
	double	r;
	int		inside;
}			t_obj;

#endif
