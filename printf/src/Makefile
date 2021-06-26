# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccartman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 17:39:46 by ccartman          #+#    #+#              #
#    Updated: 2021/06/26 11:58:18 by ccartman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS_DIR	=	./srcs/

LIB_DIR		=	./libft/

HEADERS		=	./headers/

SRCS_F		=	ft_printf.c \
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
                ft_max.c \
                ft_realloc.c \
                ft_is_conversion_type.c \
                ft_lltoa.c \
                ft_ultoa.c \
				 ft_handle_n.c \
				ft_handle_f.c \
				ft_handle_f_part2.c \
				ft_dftoa.c \
				ft_intpart_to_ascii.c \
				ft_factpart_to_ascii.c \
				ft_realloc.c \
				ft_is_conversion_type.c \
				ft_max.c \
				ft_ultoa.c \
				ft_lltoa.c \
				ft_degree_of_two.c

LIB_SRCS_F	= 	ft_memset.c \
			  	ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_F))
LIB_SRCS	= $(addprefix $(LIB_DIR), $(LIB_SRCS_F))

SRCS_D		= $(SRCS:.c=.d)

OBJS		= $(SRCS:.c=.o)
LIB_OBJS	= $(LIB_SRCS:.c=.o)

CC			= gcc
C_FLAGS		= -Wall -Wextra -Werror -I $(HEADERS)
AR			= ar
AR_FLAGS	= rcs
RM			= rm -f

.c.o:
			$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -MD


$(NAME):	$(LIB_OBJS) $(OBJS)
			make -sC ./libft/ all
			$(AR) $(AR_FLAGS) $(NAME) $?

all:		$(NAME)

include $(wildcard $(SRCS_D))

clean:
			make -sC ./libft/ clean
			$(RM) $(OBJS) $(SRCS_D) $(OBJS_B) $(SRCS_B_D)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:      all



.PHONY:		all bonus clean fclean re
