/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 17:12:10 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_alfa;

static void	usraction(int sig, siginfo_t *info, void *ucontext);

static void	redefine_signals(struct sigaction *act);

static void	print_client_msg(void);

static void	send_sigusr1(void);

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
		send_sigusr1();
	}
}

static void	send_sigusr1(void)
{
	usleep(100);
	if (kill(client_pid(0), SIGUSR1) == -1)
		print_signal_error();
}

static void	redefine_signals(struct sigaction *act)
{
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGUSR1);
	sigaddset(&act->sa_mask, SIGUSR2);
	act->sa_flags = SA_RESTART | SA_SIGINFO;
	act->sa_sigaction = usraction;
	if (sigaction(SIGUSR1, act, NULL) == -1)
		print_sigact_error();
	if (sigaction(SIGUSR2, act, NULL) == -1)
		print_sigact_error();
}

static void	usraction(int sig, siginfo_t *info, void *ucontext)
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
	client_pid(info->si_pid);
}
