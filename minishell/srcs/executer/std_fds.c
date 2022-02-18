/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:03:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 21:18:29 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	save_stderr(void);

static int	save_stdout(void);

static int	save_stdin(void);

int	*get_fd_address(int fd_num)
{
	static int	save0;
	static int	save1;
	static int	save2;

	if (fd_num == STDIN_FILENO)
		return (&save0);
	else if (fd_num == STDOUT_FILENO)
		return (&save1);
	else if (fd_num == STDERR_FILENO)
		return (&save2);
	return (NULL);
}

int	save_std_fds(void)
{
	if (!save_stdin())
		return (0);
	if (!save_stdout())
		return (0);
	if (!save_stderr())
		return (0);
	return (1);
}

static int	save_stdin(void)
{
	int	*save0;

	save0 = get_fd_address(STDIN_FILENO);
	*save0 = dup(STDIN_FILENO);
	if (*save0 == -1)
	{
		*save0 = 0;
		print_str_error("dup");
		return (0);
	}
	return (1);
}

static int	save_stdout(void)
{
	int	*save0;
	int	*save1;

	save0 = get_fd_address(STDIN_FILENO);
	save1 = get_fd_address(STDOUT_FILENO);
	*save1 = dup(STDOUT_FILENO);
	if (*save1 == -1)
	{
		close(*save0);
		*save0 = 0;
		*save1 = 0;
		print_str_error("dup");
		return (0);
	}
	return (1);
}

static int	save_stderr(void)
{
	int	*save0;
	int	*save1;
	int	*save2;

	save0 = get_fd_address(STDIN_FILENO);
	save1 = get_fd_address(STDOUT_FILENO);
	save2 = get_fd_address(STDERR_FILENO);
	*save2 = dup(STDERR_FILENO);
	if (*save1 == -1)
	{
		close(*save0);
		*save0 = 0;
		close(*save1);
		*save1 = 0;
		*save2 = 0;
		print_str_error("dup");
		return (0);
	}
	return (1);
}
