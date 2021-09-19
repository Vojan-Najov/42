/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:17:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static const char				g_server_msg[] = "Server's PID: ";

static volatile sig_atomic_t	g_alfa;

void	print_pid(void);

void	usraction(int sig, siginfo_t *info, void *ucontext);

void	redefine_signals(sigset_t *set, struct sigaction *act);

void	print_client_msg(void);

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

void	print_client_msg(void)
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

void	redefine_signals(sigset_t *set, struct sigaction *act)
{
	sigemptyset(set);
	sigaddset(set, SIGUSR1);
	sigaddset(set, SIGUSR2);
	act->sa_mask = *set;
	act->sa_flags = SA_RESTART | SA_SIGINFO;
	act->sa_sigaction = usraction;
	sigaction(SIGUSR1, act, NULL);
	sigaction(SIGUSR2, act, NULL);
}

void	usraction(int sig, siginfo_t *info, void *ucontext)
{
	(void) ucontext;

	if (sig == SIGUSR1)
	{
		g_alfa <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		g_alfa <<= 1;
		g_alfa |= 1;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		print_signal_error();
		exit(EXIT_FAILURE);
	}	
}

void	print_pid(void)
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
