NAME		= megaphone

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

CC			= g++
CC_FLAGS	= -Wall -Wextra -Werror -std=c++98

RM			= rm -f

.cpp.o:		
			$(CC) $(CC_FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
