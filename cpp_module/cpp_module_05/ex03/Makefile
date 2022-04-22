NAME		= at_least_this_beats_coffee_making

SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp \
			  PresidentialPardonForm.cpp \
			  Intern.cpp \
			  Form.cpp

OBJS		= $(SRCS:.cpp=.o)

D_FILE		= $(SRCS:.cpp=.d)

CC			= c++
CC_FLAGS	= -Wall -Wextra -Werror -std=c++98

RM			= rm -f

.cpp.o:		
			$(CC) $(CC_FLAGS) -c $< -o $(<:.cpp=.o) -MD

$(NAME):	$(OBJS)
			$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

include $(wildcard $(D_FILE))

clean:
			$(RM) $(OBJS) $(D_FILE)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
