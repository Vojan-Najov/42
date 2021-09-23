/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 15:41:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

static const char	g_args_error[] = "Usage: ./client [server's pid]"
											"[\"message string\"]\n";

static const char	g_pid_error[] = "Server's PID incorrect.\n";

static const char	g_sig_error[] = "Signal ERROR!\n";

int		print_args_error(void);

int		print_pid_error(void);

void	print_signal_error(void);

int	print_args_error(void)
{
	write(STDERR_FILENO, g_args_error, sizeof(g_args_error));
	return (1);
}

int	print_pid_error(void)
{
	write(STDERR_FILENO, g_pid_error, sizeof(g_pid_error));
	return (2);
}

void	print_signal_error(void)
{
	write(STDERR_FILENO, g_sig_error, sizeof(g_sig_error));
}
