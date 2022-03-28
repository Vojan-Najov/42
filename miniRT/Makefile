NAME			= miniRT

INCLUDES		= ./includes/

DIR_PRS			= ./srcs/parser/
SRCS_F_PRS 		= add_figure_list.c \
				  add_util_structs.c \
				  init_add_ambient.c \
				  init_add_camera.c \
				  init_add_light.c \
				  parsing.c

DIR_GMTR		= ./srcs/geometry/
SRCS_F_GMTR		= deg2rad.c \
				  inverse.c \
				  inverse_utils.c \
				  mtrx44.c \
				  mtrx44_print.c \
				  mtrx44_round.c \
				  vec3_0.c \
				  vec3_1.c \
				  vec3_2.c \
				  vec3_print.c \
				  vec_mtrx.c

DIR_LIST		= ./srcs/list/
SRCS_F_LIST		= ft_objlst_add_back.c \
				  ft_objlst_add_front.c \
				  ft_objlst_clear.c \
				  ft_objlst_iter.c \
				  ft_objlst_last.c \
				  ft_objlst_new.c \
				  ft_objlst_size.c \
				  init_objlst.c

DIR_MLX			= ./srcs/mlx/
SRCS_F_MLX		= mlx_module.c \
				  hooks.c \
				  deal_expose.c \
				  deal_mouse.c \
				  deal_key.c \
				  get_color.c

DIR_RT			= ./srcs/ray_tracer/
SRCS_F_RT		= compute_ray.c \
				  lookat.c \
				  transfer.c \
				  render.c \
				  cast_ray.c \
				  solve_quadratic.c \
				  plane.c \
				  sphere.c \
				  cylinder_intersection.c \
				  cylinder_surface.c \
				  base_intersection.c \
				  base_surface.c \
				  select_obj.c \
				  translation.c \
				  rotation.c \
				  translation_camera.c \
				  translation_light.c \
				  rotation_camera.c \
				  resize.c \
				  get_help.c

DIR_UTILS		= ./srcs/utils/
SRCS_F_UTILS	= free_str_tab.c \
				  print_err.c \
				  str_tab_len.c \
				  completion.c

DIR_SRCS		= ./srcs/
SRCS_F			= minirt.c

SRCS_PRS		= $(addprefix $(DIR_PRS), $(SRCS_F_PRS))
SRCS_GMTR		= $(addprefix $(DIR_GMTR), $(SRCS_F_GMTR))
SRCS_LIST		= $(addprefix $(DIR_LIST), $(SRCS_F_LIST))
SRCS_MLX		= $(addprefix $(DIR_MLX), $(SRCS_F_MLX))
SRCS_RT			= $(addprefix $(DIR_RT), $(SRCS_F_RT))
SRCS_UTILS		= $(addprefix $(DIR_UTILS), $(SRCS_F_UTILS))
SRCS			= $(addprefix $(DIR_SRCS), $(SRCS_F))

OBJS_PRS		= $(SRCS_PRS:.c=.o)
OBJS_GMTR		= $(SRCS_GMTR:.c=.o)
OBJS_LIST		= $(SRCS_LIST:.c=.o)
OBJS_MLX		= $(SRCS_MLX:.c=.o)
OBJS_RT			= $(SRCS_RT:.c=.o)
OBJS_UTILS		= $(SRCS_UTILS:.c=.o)
OBJS			= $(SRCS:.c=.o)

DF_PRS			= $(SRCS_PRS:.c=.d)
DF_GMTR			= $(SRCS_GMTR:.c=.d)
DF_LIST			= $(SRCS_LIST:.c=.d)
DF_MLX			= $(SRCS_MLX:.c=.d)
DF_RT			= $(SRCS_RT:.c=.d)
DF_UTILS		= $(SRCS_UTILS:.c=.d)
DF				= $(SRCS:.c=.d)

CC			= gcc

CC_FLAGS	= -Wall -Wextra -Werror -I ${INCLUDES} -I ./minilibx

RM			= rm -f

.c.o:
			make -sC ./minilibx/ all
			make -sC ./libft/ bonus
			$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o) -MD

$(NAME):	$(OBJS_PRS) $(OBJS_GMTR) $(OBJS_LIST) $(OBJS) $(OBJS_MLX) $(OBJS_RT) \
$(OBJS_UTILS)
			$(CC) $(CC_FLAGS) $(OBJS_PRS) $(OBJS_GMTR) $(OBJS_LIST) $(OBJS_MLX) \
			   	$(OBJS_RT) $(OBJS_UTILS) $(OBJS) \
				-o $(NAME) -L ./libft -L ./minilibx -lft -lm \
				-lmlx -framework OpenGl -framework AppKit

all:		$(NAME)

include $(wildcard $(DF))
include $(wildcard $(DF_PRS))
include $(wildcard $(DF_GMTR))
include $(wildcard $(DF_LIST))
include $(wildcard $(DF_MLX))
include $(wildcard $(DF_RT))
include $(wildcard $(DF_UTILS))

clean:
			make -sC ./libft/ clean
			make -sC ./minilibx/ clean
			$(RM) $(OBJS_PRS) $(OBJS_GMTR) $(OBJS_LIST) $(OBJS_MLX) \
				$(OBJS_RT) $(OBJS_UTILS) $(OBJS) \
				$(DF_PRS) $(DF_GMTR) $(DF_LIST) $(DF_MLX) \
				$(DF_RT) $(DF_UTILS) $(DF)

fclean:		clean
			make -sC ./libft/ fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
