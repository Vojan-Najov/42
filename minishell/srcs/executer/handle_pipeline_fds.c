/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipeline_fds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:43:47 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/14 13:43:50 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int		handle_first_elem(int *fd, int *fd_for_close);

static int		handle_middle_elem(int *fd, int *fd_for_close);

static int		handle_last_elem(int *fd, int *fd_for_close);

int	handle_pipeline_fds(int *fd, int *fd_for_close, int flag, pid_t *pid)
{	
	if (flag == FIRST_ELEM)
	{
		if (!handle_first_elem(fd, fd_for_close))
		{
			set_exit_status(EXECUTE_ERROR);
			return (0);
		}
	}
	else if (flag == LAST_ELEM)
	{
		if (!handle_last_elem(fd, fd_for_close))
		{
			kill_all_childs(pid, fd, *fd_for_close);
			return (0);
		}
	}
	else if (flag == MIDDLE_ELEM)
	{
		if (!handle_middle_elem(fd, fd_for_close))
		{	
			kill_all_childs(pid, fd, *fd_for_close);
			return (0);
		}
	}
	return (1);
}

static int	handle_first_elem(int *fd, int *fd_for_close)
{
	if (pipe(fd) == -1)
	{
		print_str_error("pipe");
		return (0);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		print_str_error("dup2");
		return (0);
	}
	close(fd[1]);
	*fd_for_close = fd[0];
	return (1);
}

static int	handle_middle_elem(int *fd, int *fd_for_close)
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		print_str_error("dup2");
		return (0);
	}
	close(fd[0]);
	if (pipe(fd) == -1)
	{
		print_str_error("pipe");
		return (0);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		print_str_error("dup2");
		return (0);
	}
	close(fd[1]);
	*fd_for_close = fd[0];
	return (1);
}

static int	handle_last_elem(int *fd, int *fd_for_close)
{
	restore_std_fds();
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		print_str_error("dup2");
		return (0);
	}
	close(fd[0]);
	*fd_for_close = -1;
	return (1);
}
