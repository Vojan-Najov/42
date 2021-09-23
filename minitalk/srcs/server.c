/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:37:15 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 14:37:37 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static const char				g_server_msg[] = "Server's PID: ";

static volatile sig_atomic_t	g_alfa;

static void	print_pid(void);

static void	usrhdl(int sig);

static void	redefine_signals(sigset_t *set, struct sigaction *act);

static void	print_client_msg(void);

int	main(void)
{
	sigset_t			set;
	struct sigaction	act;

	g_alfa = 0;
	redefine_signals(&set, &act);
	print_pid();
	print_client_msg();
	return (0);
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
				write(STDIN_FILENO, buf, count);
				count = 0;
			}
			if (g_alfa)
				buf[count++] = (char) g_alfa;
			bits = 0;
			g_alfa = 0;
		}
	}
}

static void	redefine_signals(sigset_t *set, struct sigaction *act)
{
	sigemptyset(set);
	sigaddset(set, SIGUSR1);
	sigaddset(set, SIGUSR2);
	act->sa_mask = *set;
	act->sa_flags = SA_RESTART;
	act->sa_handler = usrhdl;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
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
	write(STDIN_FILENO, g_server_msg, sizeof(g_server_msg));
	write(STDIN_FILENO, s, n);
}
