# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 18:59:23 by ccartman          #+#    #+#              #
#    Updated: 2022/03/11 13:02:59 by ccartman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS_DIR	= ./srcs/

SRCS_F		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
			  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
			  ft_strndup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c ft_strcpy.c \
			  ft_strjoin_and_free_s1.c get_next_line.c ft_atof.c fswap.c

BONUS_F		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_F))
SRCS_B		= $(addprefix $(SRCS_DIR), $(BONUS_F))

OBJS		= $(SRCS:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

FLAGS		= -Wall -Wextra -Werror -I ../includes/

$(NAME) : $(OBJS)
	ar rcs $(NAME) $?

.c.o :
	gcc $(FLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : $(NAME) $(OBJS_B)
	ar rcs $(NAME) $?

.PHONY : all clean fclean re bonus
