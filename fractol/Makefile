NAME			=	fractol

SRCS_DIR		=	./srcs/

INCLUDES		=	./includes/

SRCS_F			=	/colors/colors.c \
					/colors/color_blue.c \
					/colors/color_red.c \
					/colors/color_gray.c \
					/colors/color_other.c \
					area.c \
					completion.c \
					complex.c \
					draw_mandelbrot.c \
					draw_julia.c \
					hooks.c \
					fractol.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

SRCS_D			=	$(SRCS:.c=.d)

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror -I $(INCLUDES)

RM				=	rm -f

.c.o:
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o)  -L ./minilibx-linux -lmx -lXext -X11 -lm

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

all:			$(NAME)

bonus:			$(NAME)

$clean:
				$(RM) $(OBJS) $(SRCS_D)

fclean:			clean
				$(RM) $(NAME) $(NAME_B)

re:				fclean all

.PHONY:			all clean fclean re bonus
