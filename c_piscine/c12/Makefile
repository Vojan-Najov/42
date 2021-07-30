NAME	= listcheck

SRCS	= ft_create_elem.c \
	  ft_list_push_front.c \
	  ft_list_size.c \
	  ft_list_last.c \
	  ft_list_push_back.c \
	  ft_list_push_strs.c \
	  ft_list_clear.c \
	  ft_list_at.c \
	  ft_list_reverse.c \
	  ft_list_foreach.c \
	  ft_list_foreach_if.c \
	  ft_list_remove_if.c \
	  ft_list_find.c \
	  ft_list_merge.c \
	  ft_list_sort.c \
	  ft_sorted_list_insert.c \
	  ft_sorted_list_merge.c \
	  main.c
OBJS	= $(SRCS:.c=.o)
SRCS_D	= $(SRCS:.c=.d)

CC	= gcc
C_FLAGS	= -Wall -Wextra -Werror
RM	= rm -f

.c.o:
	$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -MD

all:	$(OBJS)
	gcc $? -o $(NAME)

$(NAME): all

include $(wildcard $(SRCS_D))

clean:
	$(RM) $(OBJS) $(SRCS_D)
	
fclean:	clean
	$(RM) $(NAME)

re:	fclean all
