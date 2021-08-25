# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malison <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 23:02:11 by malison           #+#    #+#              #
#    Updated: 2021/03/10 21:59:58 by malison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ft_draws_and_print_map.c ft_dupx.c ft_read_map.c ft_find.c

OBJS		= ${SRCS:.c=.o}

NAME		= bsq

HEADER		= bsq.h

CC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror

.c.o:		
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS} ${HEADER}
			@${CC} $(CFLAGS) ${OBJS} -o ${NAME} 

all:		${NAME}

clean:
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
