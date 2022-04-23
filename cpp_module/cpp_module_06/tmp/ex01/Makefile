#################
##  VARIABLES  ##
#################

#  Sources
SRC         =	main.cpp \
				Data.cpp

#  Output
NAME		=	serialization

#  Dependencies
DEPFLAGS	=	-MT $@ -MMD -MP -MF $*.d

#  Compiler
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
CC			=	c++

#################
##    AUTO     ##
#################

OBJ			=	$(addsuffix .o, $(basename $(SRC)))
DEPFILES	=	$(addsuffix .d, $(basename $(SRC)))

#################
##  TARGETS    ##
#################

default_target: all

.PHONY: default_target

#  Build target
all: $(NAME)

.PHONY: all

#  Removing objects
clean:
	rm -rf $(OBJ)
	rm -rf $(DEPFILES)

.PHONY: clean

#  Removing objects and exe
fclean: clean
	rm -f $(NAME)

.PHONY: fclean

#  All removing then compiling
re:    fclean all

.PHONY: re

#  Objects compilation
%.o:  %.cpp Makefile %.d
	$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ -c $<

#  Linking
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

#  Dependencies
$(DEPFILES):
include $(wildcard $(DEPFILES))
