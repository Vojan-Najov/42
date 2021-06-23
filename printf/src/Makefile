# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccartman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 17:39:46 by ccartman          #+#    #+#              #
#    Updated: 2021/06/16 21:01:49 by ccartman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c \
			ft_buf.c \
			ft_parse.c \
			ft_handle.c \
			ft_handle_perc.c \
			ft_handle_c.c \
			ft_handle_s.c \
			ft_handle_p.c \
			ft_handle_u.c \
			ft_handle_x.c \
			ft_handle_o.c \
			ft_handle_xx.c \
			ft_handle_d.c \
			ft_handle_n.c \
			ft_realloc.c \
			ft_is_conversion_type.c \
			ft_max.c \
			ft_ultoa.c \
			ft_lltoa.c \
			libft/ft_isdigit.c \
			libft/ft_memcpy.c \
			libft/ft_memset.c \
			libft/ft_strlen.c \
			libft/ft_toupper.c \
			libft/ft_itoa.c \
			#ft_utoa.c libft/ft_toupper.c ft_ultoa.c ft_max.c \
			ft_p_handle.c ft_u_handle.c ft_x_handle.c ft_xx_handle.c \
			ft_d_handle.c



OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJS)
			ar -rcs $(NAME) $?
.c.o	:
			#norminette $<
			gcc $(FLAGS) -c $< -o $@ -I libft/

all		:	$(NAME)

bonus	:	$(NAME)

clean	:
			rm -f *.o

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

m		:
				gcc \
				-g \
				-Wall -Wextra -Werror main.c \
			   	ft_printf.c \
				ft_buf.c \
				ft_parse.c \
				ft_handle.c \
				ft_handle_perc.c \
				ft_handle_c.c \
				ft_handle_s.c \
				ft_handle_p.c \
				ft_handle_u.c \
				ft_handle_o.c \
				ft_handle_x.c \
				ft_handle_xx.c \
				ft_handle_d.c \
				ft_handle_n.c \
				ft_realloc.c \
				ft_is_conversion_type.c \
				ft_max.c \
				ft_ultoa.c \
				ft_lltoa.c \
				libft/ft_isdigit.c \
				libft/ft_memcpy.c \
				libft/ft_memset.c \
				libft/ft_strlen.c \
				libft/ft_toupper.c \
				libft/ft_itoa.c \
				-I libft
