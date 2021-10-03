NAME_S 		= server
NAME_C		= client

SRCS_DIR	= ./srcs/
BNS_DIR		= ./bonus/

INCLUDES	= ./includes/

SRCS_FS		= server.c \
			  errors.c
SRCS_FC		= client.c \
			  errors.c
BNS_FS		= errors.c \
			  pid_utills.c \
			  server.c
BNS_FC		= errors.c \
			  pid_utills.c \
			  client.c

SRCS_S		= $(addprefix $(SRCS_DIR), $(SRCS_FS))
SRCS_C		= $(addprefix $(SRCS_DIR), $(SRCS_FC))
BNS_S		= $(addprefix $(BNS_DIR), $(BNS_FS))
BNS_C		= $(addprefix $(BNS_DIR), $(BNS_FC))

OBJS_S		= $(SRCS_S:.c=.o)
OBJS_C		= $(SRCS_C:.c=.o)
OBJS_BS		= $(BNS_S:.c=.o)
OBJS_BC		= $(BNS_C:.c=.o)

SRCS_DS		= $(SRCS_S:.c=.d)
SRCS_DC		= $(SRCS_C:.c=.d)
BNS_DS		= $(BNS_S:.c=.d)
BNS_DC		= $(BNS_C:.c=.d)

CC			= gcc

CC_FLAGS		= -fsanitize=address -Wall -Wextra -Werror -I $(INCLUDES)

RM			= rm -f

.c.o:
			$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o) -MD

all:		$(NAME_C) $(NAME_S)

$(NAME_C):	$(OBJS_C)
			$(CC) $(CC_FLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_S):	$(OBJS_S)
			$(CC) $(CC_FLAGS) $(OBJS_S) -o $(NAME_S)

bonus:		bonus_server bonus_client

bonus_server:	$(OBJS_BS)
				$(CC) $(CC_FLAGS) $(OBJS_BS) -o $(NAME_S)

bonus_client:	$(OBJS_BC)
				$(CC) $(CC_FLAGS) $(OBJS_BC) -o $(NAME_C)
			


include $(wildcard $(SRCS_DC))
include $(wildcard $(SRCS_DS))

clean:
			$(RM) $(OBJS_S) $(OBJS_C) $(SRCS_DS) $(SRCS_DC) \
					$(OBJS_BS) $(OBJS_BC) $(BNS_DS) $(BNS_DC)

fclean:		clean
			$(RM) $(NAME_S) $(NAME_C)

re:			fclean all

.PHONY:		all clean fclean re bonus
