# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccartman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 17:39:46 by ccartman          #+#    #+#              #
#    Updated: 2021/06/11 00:09:01 by ccartman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS	=	$(SRCS:.c=.o)

#NAME	=	libftprintf

#FLAGS	=	-Wall -Wextra -Werror

#$(NAME)	:	$(OBJS)
		#	gcc $? -o printf

#.c.o	:
#			gcc $(FLAGS) -c $< -o $@ -L./libft -lft
#
#

all:
			gcc -Wall -Wextra -Werror \
			   	ft_printf.c buf.c ft_parse.c ft_handle.c ft_realloc.c \
				ft_is_conversion_type.c libft/ft_isdigit.c \
				libft/ft_memcpy.c libft/ft_strlen.c libft/ft_itoa.c \
				ft_utoa.c libft/ft_toupper.c ft_ultoa.c -I libft
