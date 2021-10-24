# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccartman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 16:58:51 by ccartman          #+#    #+#              #
#    Updated: 2021/10/24 18:23:42 by ccartman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

SRCS_DIR 	= ./srcs/

INCLUDES	=./includes/

SRCS_F		= colors/colors.c \
			  colors/color_blue.c \
			  colors/color_red.c \
			  colors/color_gray.c \
			  colors/color_other.c \
			  pixel_put.c \
			  ft_strcmp.c \
			  float.c \
			  area.c \
			  completion.c \
			  complex.c \
			  draw_fractal.c \
			  draw_mandelbrot.c \
			  draw_julia.c \
			  draw_burning_ship.c \
			  draw_tricorn.c \
			  hooks.c \
			  fractol.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_F))

SRCS_D		= $(SRCS:.c=.d)

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror -O3

RM			= rm -f

.c.o:
	$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -MD -I includes -I ./minilibx


$(NAME):	$(OBJS) Makefile
	make -sC ./minilibx all
	$(CC) $(CC_GLAGS) $(OBJS) -o $(NAME) -L ./minilibx -lmlx \
								-framework OpenGL -framework AppKit -lm

all:		$(NAME)

include $(wildcard $(SRCS_D))

bonus:		$(NAME)

clean:
	make -sC ./minilibx clean
	$(RM) $(OBJS) $(SRCS_D)

fclean:		clean
	$(RM) $(NAME) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re bonus
