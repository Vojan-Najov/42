NAME		= push_swap
NAME_B		= checker

SRCS_DIR	= ./srcs/

INCLUDES	= ./includes/

SRCS_F		= check_args.c \
		  	  heap_sort.c \
		  	  ft_list1.c \
		  	  ft_list2.c \
		  	  ft_strjoin_and_free_src.c \
		  	  stack_swap.c \
		  	  stack_push.c \
		  	  stack_rotate.c \
		  	  stack_rev_rotate.c \
		  	  stack_sort_utils.c \
		  	  stack_b3_sort.c \
		  	  stack_a3_sort.c \
			  frame_split.c \
		  	  stack_sort.c \
		  	  main.c

BONUS		= srcs/check_args.c \
		  	  srcs/ft_list1.c \
		  	  srcs/ft_strjoin_and_free_src.c \
		  	  bonus/list_utils.c \
		  	  bonus/stack_swap.c \
		  	  bonus/stack_push.c \
		  	  bonus/stack_rotate.c \
		  	  bonus/stack_rev_rotate.c \
			  bonus/get_next_line.c \
			  bonus/instructions.c \
			  bonus/checker.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(BONUS:.c=.o)

SRCS_D		= $(SRCS:.c=.d)
BONUS_D		= $(BONUS:.c=.d)

CC			= gcc

CC_FLAGS	= -Wall -Wextra -Werror -I $(INCLUDES)

RM			= rm -f


.c.o:
			make -sC ./libft/ all
			$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o) -MD

#$(NAME):	$(OBJS)
#		$(CC) -g $? -o $(NAME) -L ./libft -lft
$(NAME):	$(OBJS)
			$(CC) -g $(OBJS) -o $(NAME) -L ./libft -lft

all:		$(NAME)

include $(wildcard $(SRCS_D))

clean:
			make -sC ./libft/ clean
			$(RM) $(OBJS) $(SRCS_D) $(OBJS_B) $(BONUS_D)

fclean:		clean
			make -sC ./libft/ fclean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

bonus:		$(OBJS_B)
			$(CC) -g $(OBJS_B) -o $(NAME_B) -L ./libft -lft


.PHONY:		all clean fclean re bonus
