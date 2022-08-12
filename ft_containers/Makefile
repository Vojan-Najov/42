NAME     		    = ft_containers
NAME_FT     		= ft_test
NAME_STD	        = std_test
NAME_FT_INTRA		= ft_intra_test
NAME_STD_INTRA		= std_intra_test

SRCS1		= ./test/test.cpp

OBJS1		= $(SRCS1:.cpp=.o)

D_FILE1		= $(SRCS1:.cpp=.d)

CC			= c++
CC_FLAGS	= -Wall -Wextra -Werror -I ./includes/

RM			= rm -f

.cpp.o:		
			$(CC) $(CC_FLAGS) -std=c++98 -c $< -o $(<:.cpp=.o) -MD

$(NAME):	$(OBJS1)
			$(CC) $(CC_FLAGS) -std=c++98 -fsanitize=address $(OBJS1) -o $(NAME)

$(NAME_FT):	$(OBJS1)
			$(CC) $(CC_FLAGS) -std=c++98 -fsanitize=address $(OBJS1) -o $(NAME_FT)

$(NAME_STD):
			 $(CC) $(CC_FLAGS) -std=c++11 -DSTL=1 ./test/test.cpp -o $(NAME_STD)

$(NAME_FT_INTRA):
			 $(CC) $(CC_FLAGS) -std=c++98 ./test/intra_main.cpp -o $(NAME_FT_INTRA)

$(NAME_STD_INTRA):
			 $(CC) $(CC_FLAGS) -std=c++98 -DSTL=1 ./test/intra_main.cpp -o $(NAME_STD_INTRA)

all:		$(NAME)

include $(wildcard $(D_FILE))

clean:
			$(RM) $(OBJS1) $(D_FILE1)

fclean:		clean
			$(RM) $(NAME) $(NAME_FT) $(NAME_STD) $(NAME_FT_INTRA) $(NAME_STD_INTRA)

re:			fclean all

.PHONY:		all clean fclean re
