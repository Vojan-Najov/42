NAME			= minishell

INCLUDES		= ./includes/

DIR_PRS			= ./srcs/parser/
SRCS_F_PRS		= check_duplicate_tokens.c \
				  check_tokens.c \
				  counters.c \
				  expansion_word.c \
				  expansion_words.c \
				  free_cmds.c \
				  ft_isblank.c \
				  ft_istoken.c \
				  get_fd.c \
				  init_cmds.c \
				  init_command.c \
				  malloc_list_error.c \
				  new_word_length.c \
				  parse.c \
				  preparse.c \
				  set_words_flags.c \
				  split_into_commands.c \
				  split_into_tokens.c \
				  split_into_words.c

DIR_EXC			= ./srcs/executer/
SRCS_F_EXC		= execute_pipeline.c \
				  execute_simple.c \
				  get_paths.c \
				  get_pathname.c \
				  isbiltin.c \
				  redirect_fds.c \
				  restore_std_fds.c \
				  std_fds.c \
				  handle_pipeline_fds.c \
				  handle_heredoc.c \
				  kill_all_childs.c \
				  unlink_heredoc_tmp_file.c \
				  read_heredoc.c \
				  heredoc_event.c \
				  execution.c

DIR_BLTN		= ./srcs/builtin/
SRCS_F_BLTN		= cd.c \
				  pwd.c \
				  echo.c \
				  env.c \
				  exit.c \
				  export.c \
				  unset.c

DIR_ERR			= ./srcs/errors/
SRCS_F_ERR		= print_str_error.c \
				  print_err.c

DIR_UTILS		= ./srcs/utils/
SRCS_F_UTILS	= utils.c \
				  prepare_env.c

DIR_SRCS		= ./srcs/
SRCS_F			= minishell.c

DIR_ENVP		= ./srcs/envp/
SRCS_F_ENVP		= exit_status.c \
				  free_exit_status_str.c \
				  env_create.c \
				  env_getter.c \
				  env_setter.c

SRCS_PRS		= $(addprefix $(DIR_PRS), $(SRCS_F_PRS))
SRCS_EXC		= $(addprefix $(DIR_EXC), $(SRCS_F_EXC))
SRCS_ERR		= $(addprefix $(DIR_ERR), $(SRCS_F_ERR))
SRCS_ENVP		= $(addprefix $(DIR_ENVP), $(SRCS_F_ENVP))
SRCS_BLTN		= $(addprefix $(DIR_BLTN), $(SRCS_F_BLTN))
SRCS_UTILS		= $(addprefix $(DIR_UTILS), $(SRCS_F_UTILS))
SRCS			= $(addprefix $(DIR_SRCS), $(SRCS_F))

OBJS_PRS		= $(SRCS_PRS:.c=.o)
OBJS_EXC		= $(SRCS_EXC:.c=.o)
OBJS_ERR		= $(SRCS_ERR:.c=.o)
OBJS_ENVP		= $(SRCS_ENVP:.c=.o)
OBJS_BLTN		= $(SRCS_BLTN:.c=.o)
OBJS_UTILS		= $(SRCS_UTILS:.c=.o)
OBJS			= $(SRCS:.c=.o)

DF_PRS			= $(SRCS_PRS:.c=.d)
DF_EXC			= $(SRCS_EXC:.c=.d)
DF_ERR			= $(SRCS_ERR:.c=.d)
DF_ENVP			= $(SRCS_ENVP:.c=.d)
DF_BLTN			= $(SRCS_BLTN:.c=.d)
DF_UTILS		= $(SRCS_UTILS:.c=.d)
DF				= $(SRCS:.c=.d)

CC			= gcc

CC_FLAGS	= -Wall -Wextra -Werror -I ${INCLUDES} -I ~/.brew/opt/readline/include

RM			= rm -f

.c.o:
			make -sC ./libft/ bonus
			$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o) -MD

$(NAME):	$(OBJS_PRS) $(OBJS_EXC) $(OBJS_ERR) $(OBJS) $(OBJS_ENVP) $(OBJS_BLTN) \
$(OBJS_UTILS)
			$(CC) $(CC_FLAGS) $(OBJS_PRS) $(OBJS_EXC) $(OBJS_ERR) $(OBJS_ENVP) \
			   	$(OBJS_BLTN) $(OBJS_UTILS) $(OBJS) \
				-o $(NAME) -L ./libft -lft -lreadline -L ~/.brew/opt/readline/lib

all:		$(NAME)

include $(wildcard $(DF))
include $(wildcard $(DF_PRS))
include $(wildcard $(DF_EXC))
include $(wildcard $(DF_ERR))
include $(wildcard $(DF_ENVP))
include $(wildcard $(DF_BLTN))
include $(wildcard $(DF_UTILS))

clean:
			make -sC ./libft/ clean
			$(RM) $(OBJS_PRS) $(OBJS_EXC) $(OBJS_ERR) $(OBJS_ENVP) \
				$(OBJS_BLTN) $(OBJS_UTILS) $(OBJS) \
				$(DF_PRS) $(DF_EXC) $(DF_ERR) $(DF_ENVP) \
				$(DF_BLTN) $(DF_UTILS) $(DF)

fclean:		clean
			make -sC ./libft/ fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
