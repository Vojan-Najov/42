/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_std_fds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:29:38 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/11 14:44:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	restore_std_fds(void)
{
	int	*save0;
	int	*save1;
	int	*save2;

	save0 = get_fd_address(STDIN_FILENO);
	if (dup2(*save0, STDIN_FILENO) == -1)
		print_str_error("dup2");
	save1 = get_fd_address(STDOUT_FILENO);
	if (dup2(*save1, STDOUT_FILENO) == -1)
		print_str_error("dup2");
	save2 = get_fd_address(STDERR_FILENO);
	if (dup2(*save2, STDERR_FILENO) == -1)
		print_str_error("dup2");
}

void	close_saved_fds(void)
{
	int	*save0;
	int	*save1;
	int	*save2;

	save0 = get_fd_address(STDIN_FILENO);
	if (*save0)
		if (close(*save0) == -1)
			print_str_error("close");
	save1 = get_fd_address(STDOUT_FILENO);
	if (*save1)
		if (close(*save1) == -1)
			print_str_error("close");
	save2 = get_fd_address(STDERR_FILENO);
	if (*save2)
		if (close(*save2) == -1)
			print_str_error("close");
}
