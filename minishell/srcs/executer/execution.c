/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:57:49 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 18:01:18 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void		execute_pipeline(t_command **command);

static void		wait_childs(pid_t *pid);

static pid_t	*init_pids(t_command **command);

static void		handle_signal(int sig);

void	execution(t_cmds *cmds)
{
	if (!handle_heredocuments(cmds->command))
	{
		free_cmds(cmds);
		return ;
	}
	if (cmds->type != SIMPLE_COMMAND && cmds->type != PIPELINE)
	{
		free_cmds(cmds);
		return ;
	}
	if (!save_std_fds())
	{
		free(cmds);
		return ;
	}
	if (cmds->type == SIMPLE_COMMAND)
		execute_simple(cmds->command[0]);
	else
		execute_pipeline(cmds->command);
	restore_std_fds();
	close_saved_fds();
	unlink_heredoc_tmp_file(cmds->command);
	free_cmds(cmds);
}

static void	execute_pipeline(t_command **command)
{
	pid_t	*pid;

	pid = init_pids(command);
	if (!pid)
		return ;
	execute_pipeline_cycle(command, pid);
	restore_std_fds();
	wait_childs(pid);
	free(pid);
}

static void	wait_childs(pid_t *pid)
{
	size_t	i;
	int		status;
	int		flag_nl;

	i = -1;
	flag_nl = 0;
	status = 0;
	while (pid[++i] != -1 && pid[i] != 0)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			set_exit_status(status);
		}
		else if (WIFSIGNALED(status))
		{
			status = WTERMSIG(status);
			set_exit_status(status + 128);
			if (flag_nl)
				continue ;
			flag_nl = 1;
			handle_signal(status);
		}
	}
}

static void	handle_signal(int sig)
{
	if (sig == SIGQUIT)
		write(STDOUT_FILENO, "Quit: 3\n", 8);
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
}

static pid_t	*init_pids(t_command **command)
{
	size_t	n;
	pid_t	*pid;

	n = 0;
	while (command[n])
		++n;
	pid = (pid_t *) ft_calloc(n + 1, sizeof(pid_t));
	if (!pid)
	{
		print_str_error("malloc");
		return (NULL);
	}
	return (pid);
}
