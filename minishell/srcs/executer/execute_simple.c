/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:01:37 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 18:55:34 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	execute_in_child_proccess(t_command *command);

static int	wait_child(pid_t pid);

void	execute_simple(t_command *command)
{
	t_biltin_ptr	biltin;
	int				status;
	size_t			i;

	status = 0;
	biltin = isbiltin(command->argv[0]);
	if (!command->argv[0] || biltin)
	{
		if (!redirect_fds(command->redirect))
			status = EXECUTE_ERROR;
		if (biltin)
			status = biltin(command->argv + 1);
		i = -1;
		while (command->redirect[++i])
		{
			if (command->redirect[i]->fd > 2)
				close (command->redirect[i]->fd);
		}
	}
	else
		status = execute_in_child_proccess(command);
	set_exit_status(status);
}

static int	execute_in_child_proccess(t_command *command)
{
	pid_t	pid;
	char	*pathname;
	char	**envp;

	envp = get_envp();
	pid = fork();
	if (pid == -1)
	{
		print_str_error("fork");
		return (EXECUTE_ERROR);
	}
	else if (pid == 0)
	{
		std_signals();
		if (!redirect_fds(command->redirect))
			exit(EXECUTE_ERROR);
		pathname = get_pathname(command->argv[0]);
		if (!pathname)
			exit(CMD_ERROR);
		execve(pathname, command->argv, envp);
		print_str_error(pathname);
		exit(EXIT_FAILURE);
	}
	return (wait_child(pid));
}

static int	wait_child(pid_t pid)
{
	int	status;

	status = 0;
	restore_std_fds();
	if (waitpid(pid, &status, 0) == -1)
		print_str_error("waipid");
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == SIGQUIT)
			write(STDOUT_FILENO, "Quit: 3\n", 8);
		if (status == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		status += 128;
	}
	return (status);
}
