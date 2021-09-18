NAME_S 		= server
NAME_C		= client

SRCS_DIR	= ./srcs/

INCLUDES	= ./includes/

SRCS_FS		= server.c
SRCS_FC		= client.c \
			  errors.c

SRCS_S		= $(addprefix $(SRCS_DIR), $(SRCS_FS))
SRCS_C		= $(addprefix $(SRCS_DIR), $(SRCS_FC))

OBJS_S		= $(SRCS_S:.c=.o)
OBJS_C		= $(SRCS_C:.c=.o)

SRCS_DS		= $(SRCS_S:.c=.d)
SRCS_DC		= $(SRCS_C:.c=.d)

CC			= gcc

CC_FLAGS	= -Wall -Wextra -Werror -I $(INCLUDES)

RM			= rm -f

.c.o:
			$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o) -MD

$(NAME_S):	$(OBJS_S)
			$(CC) $(CC_FLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C):	$(OBJS_C)
			$(CC) $(CC_FLAGS) $(OBJS_C) -o $(NAME_C)

all:		$(NAME_S) $(NAME_C)

include $(wildcard $(SRCS_DC))
include $(wildcard $(SRCS_DS))

clean:
			$(RM) $(OBJS_S) $(OBJS_C) $(SRCS_DS) $(SRCS_DC)

fclean:		clean
			$(RM) $(NAME_S) $(NAME_C)

re:			fclean all

.PHONY:		all clean fclean re bonus
