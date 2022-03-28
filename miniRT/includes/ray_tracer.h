/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:53:47 by ccartman          #+#    #+#             */
/*   Updated: 2022/03/25 22:01:31 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "minirt_types.h"

# define GET_LOOKAT 1
# define INIT_LOOKAT 2
# define OBJ_SELECTED 1
# define CMR_SELECTED 2
# define LGHT_SELECTED 3
# define K_ESC 53
# define K_PLUS1 69
# define K_PLUS2 24
# define K_MINUS1 78
# define K_MINUS2 27
# define K_SQBR1 33
# define K_SQBR2 30
# define K_Q 12
# define K_W 13
# define K_A 0
# define K_S 1
# define K_Z 6
# define K_X 7
# define K_R 15
# define K_T 17
# define K_F 3
# define K_G 5
# define K_V 9
# define K_B 11
# define K_C 8
# define K_L 37
# define K_H 4
# define K_ARROWLEFT 123
# define K_ARROWUP 126
# define K_ARROWDOWN 125
# define B_LEFT 1
# define B_RIGHT 2
# define DESTROY_NOTIFY 17
# define DEFAULT_MASK 0
# define BUTTON_PRESS 4
# define BUTTON_PRESS_MASK 0b100L

static const char	g_err_mlxinit[] = "Error: mlx_init failed\n";

static const char	g_err_mlxnw[] = "Error: mlx_new_window failed\n";

static const char	g_err_mlxni[] = "Error: mlx_new_image failed\n";

static const char	g_help_msg[] = "MiniRT usage.\n\n" \
"To select an object, left- or right-click on its image\n" \
"To select a camera, press the C button\n" \
"To select a light, press the L button\n" \
"  Objects\n" \
"to change the diameter, press '-' or '+'\n" \
"to change the hight, press '{' or '}'\n" \
"to move relative to the x-axis, use the Q and W buttons\n" \
"to move relative to the y-axis, use the A and S buttons\n" \
"to move relative to the z-axis, use the Z and X buttons\n" \
"to rotate relative to the x-axis, use the R and T buttons\n" \
"to rotate relative to the y-axis, use the F and G buttons\n" \
"to rotate relative to the z-axis, use the V and B buttons\n" \
"  Camera\n" \
"to move relative to the x-axis, use the Q and W buttons\n" \
"to move relative to the y-axis, use the A and S buttons\n" \
"to move relative to the z-axis, use the Z and X buttons\n" \
"to rotate relative to the x-axis, use the R and T buttons\n" \
"to rotate relative to the y-axis, use the F and G buttons\n" \
"to rotate relative to the z-axis, use the V and B buttons\n" \
"  Light\n" \
"To change the polar angle, press the Q or W button\n" \
"To change the azimuth angle, press the A or S button\n" \
"To move the light source away or closer, press Z or X button\n";

typedef struct s_mrt
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_help_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		selected;
}			t_mrt;

/*			MLX_MODULE			*/

int			get_color(int r, int g, int b);

t_mrt		*get_mrt(void);

void		mlx_initialization(t_mrt *mrt);

void		pixel_put(t_mrt *mrt, int x, int y, int color);

void		define_hooks(t_mrt *mrt);

int			deal_expose(void *param);

int			deal_button(int button, int x, int y, void *param);

int			deal_key(int keycode, void *param);

/*			RAY_TRACER			*/

t_mtrx44	look_at(int flag);

void		transfer_scene(void);

void		render(t_mrt *mrt);

void		compute_ray(int i, int j, t_vec3 orig, t_vec3 dir);

void		compute_shadow_ray(t_obj *cur_obj, t_vec3 orig, t_vec3 dir);

int			cast_ray(t_ray *ray);

int			trace(t_ray *ray, t_obj **hit_obj);

int			intersect_plane(struct s_obj *self, t_ray *ray, double *t);

void		surface_plane(struct s_obj *self, t_ray *ray, double *t);

int			intersect_sphere(struct s_obj *self, t_ray *ray, double *t);

void		surface_sphere(struct s_obj *self, t_ray *ray, double *t);

int			intersect_cylinder(struct s_obj *self, t_ray *ray, double *t);

void		surface_cylinder(struct s_obj *self, t_ray *ray, double *t);

void		upper_base_origin(t_vec3 orig, t_vec3 point, t_vec3 n, double h);

int			intersect_upper_base(struct s_obj *self, t_ray *ray, double *t);

int			intersect_lower_base(struct s_obj *self, t_ray *ray, double *t);

void		surface_lower_base(struct s_obj *self, t_ray *ray, double *t);

void		surface_upper_base(struct s_obj *self, t_ray *ray, double *t);

void		select_obj(int x, int y);

t_obj		*get_selected_obj(void);

void		resize_radius(t_mrt *mrt, int keycode);

void		resize_height(t_mrt *mrt, int keycode);

void		translation(t_mrt *mrt, int keycode);

void		translation_camera(t_mrt *mrt, int keycode);

void		translation_light(t_mrt *mrt, int keycode);

void		rotation(t_mrt *mrt, int keycode);

void		rotation_camera(t_mrt *mrt, int keycode);

void		get_help(void);

/*		OTHER					*/

int			solve_quadratic(double a, double b, double c, double *t);

int			solve_quadratic_im(double a, double b, double c, double *t);

int			completion(t_mrt *mrt);

#endif
