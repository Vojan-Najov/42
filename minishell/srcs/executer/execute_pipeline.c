/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:03:40 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/15 19:30:38 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include <stdio.h> //

static pid_t	execute_cmd(t_command *command, int fd_for_close);

static void		execute_in_child_proccess(t_command *command, int fd_for_close);

void	execute_pipeline_cycle(t_command **command, pid_t *pid)
{
	size_t	i;
	int		flag;
	int		fd[2];
	int		fd_for_close;

	i = -1;
	while (command[++i])
	{
		fd_for_close = -1;
		if (i == 0)
			flag = FIRST_ELEM;
		else if (!command[i + 1])
			flag = LAST_ELEM;
		else
			flag = MIDDLE_ELEM;
		if (!handle_pipeline_fds(fd, &fd_for_close, flag, pid))
			return ;
		pid[i] = execute_cmd(command[i], fd_for_close);
		if (pid[i] == -1)
			return (kill_all_childs(pid, fd, fd_for_close));
	}
}

static pid_t	execute_cmd(t_command *command, int fd_for_close)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		print_str_error("fork");
		return (-1);
	}	
	else if (pid == 0)
	{
		std_signals();
		execute_in_child_proccess(command, fd_for_close);
	}
	return (pid);
}

static void	execute_in_child_proccess(t_command *command, int fd_for_close)
{
	t_biltin_ptr	biltin;
	int				status;
	char			*pathname;
	char			**envp;

	if (fd_for_close != -1)
		close (fd_for_close);
	if (!redirect_fds(command->redirect))
		exit(EXIT_FAILURE);
	if (!command->argv[0])
		exit(EXIT_SUCCESS);
	biltin = isbiltin(command->argv[0]);
	if (biltin)
	{
		status = biltin(command->argv + 1);
		exit(status);
	}
	pathname = get_pathname(command->argv[0]);
	if (!pathname)
		exit(CMD_ERROR);
	envp = get_envp();
	execve(pathname, command->argv, envp);
	print_str_error(pathname);
	exit(EXIT_FAILURE);
}
