/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:09:15 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/20 14:50:11 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include "minishell.h"
# include "libft.h"
# include "minishell_envp.h"
# include "minishell_errors.h"

# define EXECUTE_ERROR 1
# define FILE_ERROR 126
# define CMD_ERROR 127
# define FIRST_ELEM 1
# define MIDDLE_ELEM 2
# define LAST_ELEM 3
# define HRDC_TMPFILE "/tmp/minishell_heredoc"
# define HEREDOC_PROMPT "> "

typedef int(*t_biltin_ptr)(char **argv);

int				save_std_fds(void);

int				*get_fd_address(int fd_num);

void			restore_std_fds(void);

void			close_saved_fds(void);

char			**get_paths(void);

char			*get_pathname(const char *name);

int				redirect_fds(t_redirect **redirect);

int				unlink_heredoc_tmp_file(t_command **command);

t_biltin_ptr	isbiltin(const char *name);

void			execute_simple(t_command *command);

void			execute_pipeline_cycle(t_command **command, pid_t *pid);

int				handle_pipeline_fds(int *fd, int *fd_for_close, \
												int flag, pid_t *pid);

void			kill_all_childs(pid_t *pid, int *fdp, int fd);

int				handle_heredocuments(t_command **cmd);

int				read_heredoc(int fd, char *stop);

int				heredoc_event(void);

#endif
