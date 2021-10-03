/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:37:15 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 17:05:25 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static const char				g_server_msg[] = "Server's PID: ";

static volatile sig_atomic_t	g_alfa;

static void	print_pid(void);

static void	usrhdl(int sig);

static void	redefine_signals(struct sigaction *act);

static void	print_client_msg(void);

int	main(void)
{
	struct sigaction	act;

	g_alfa = 0;
	redefine_signals(&act);
	print_pid();
	print_client_msg();
}

static void	print_client_msg(void)
{
	char	buf[BUFSIZE];
	int		count;
	int		bits;

	count = 0;
	bits = 0;
	while (1)
	{
		pause();
		++bits;
		if (bits == 8)
		{
			if (count == BUFSIZE - 1 || !g_alfa)
			{
				if (write(STDIN_FILENO, buf, count) != count)
					print_write_error();
				count = 0;
			}
			if (g_alfa)
				buf[count++] = (char) g_alfa;
			bits = 0;
			g_alfa = 0;
		}
	}
}

static void	redefine_signals(struct sigaction *act)
{
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGUSR1);
	sigaddset(&act->sa_mask, SIGUSR2);
	act->sa_flags = SA_RESTART;
	act->sa_handler = usrhdl;
	if (sigaction(SIGUSR1, act, NULL) == -1)
		print_sigact_error();
	if (sigaction(SIGUSR2, act, NULL) == -1)
		print_sigact_error();
}

static void	usrhdl(int sig)
{
	if (sig == SIGUSR1)
	{
		g_alfa <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		g_alfa <<= 1;
		g_alfa |= 1;
	}
}

static void	print_pid(void)
{
	pid_t	pid;
	char	s[20];
	int		i;
	int		n;

	pid = getpid();
	n = (int) pid;
	i = 0;
	while (n)
	{
		n /= 10;
		++i;
	}
	n = i + 1;
	s[i] = '\n';
	while (pid)
	{
		s[--i] = pid % 10 + '0';
		pid /= 10;
	}
	i = write(STDIN_FILENO, g_server_msg, sizeof(g_server_msg));
	i += write(STDIN_FILENO, s, n);
	if (i != n + sizeof(g_server_msg))
		print_write_error();
}
