NAME		= philo

SRCS_DIR	= ./srcs/

INCLUDES	= ./includes/

SRCS_F		= ft_atoi.c \
			  ft_isdigit.c \
			  check_args.c \
			  init.c \
			  completion.c \
			  thread.c \
			  main.c

#BONUS		= srcs/check_args.c \

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(BONUS:.c=.o)

SRCS_D		= $(SRCS:.c=.d)
#BONUS_D		= $(BONUS:.c=.d)

CC			= gcc

CC_FLAGS	= -g -Wall -Wextra -Werror -I $(INCLUDES)

RM			= rm -f


.c.o:
			$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o) -MD

$(NAME):	$(OBJS)
			$(CC) -g $(OBJS) -o $(NAME) -lpthread

all:		$(NAME)

include $(wildcard $(SRCS_D))

clean:
			$(RM) $(OBJS) $(SRCS_D) $(OBJS_B) $(BONUS_D)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

#bonus:		$(OBJS_B)
#			$(CC) -g $(OBJS_B) -o $(NAME_B) -L ./libft -lft


.PHONY:		all clean fclean re bonus
