/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 17:12:18 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static const char	g_args_error[] = "Usage: ./client [server's pid]"
											"[\"message string\"]\n";

static const char	g_pid_error[] = "Server's PID incorrect.\n";

static const char	g_sig_error[] = "Signal ERROR!\n";

static const char	g_sigact_error[] = "Sigaction ERROR!\n";

static const char	g_write_error[] = "Stdin write ERROR!\n";

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
	exit(EXIT_FAILURE);
}

void	print_sigact_error(void)
{
	write(STDERR_FILENO, g_sigact_error, sizeof(g_sigact_error));
	exit(EXIT_FAILURE);
}

void	print_write_error(void)
{
	write(STDERR_FILENO, g_write_error, sizeof(g_write_error));
	exit(EXIT_FAILURE);
}
