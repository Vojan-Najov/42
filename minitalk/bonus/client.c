/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 17:56:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	contact_server(pid_t spid, char *msg);

static void	redefine_signals(struct sigaction *act);

static void	usr1action(int sig, siginfo_t *info, void *ucontext);

int	main(int argc, char **argv)
{
	pid_t				spid;
	struct sigaction	act;

	if (argc != 3)
		return (print_args_error());
	spid = ft_getpid(argv[1]);
	if (spid <= 0)
		return (print_pid_error());
	redefine_signals(&act);
	contact_server(spid, argv[2]);
	return (0);
}

static void	redefine_signals(struct sigaction *act)
{
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGUSR1);
	act->sa_flags = SA_RESTART | SA_SIGINFO;
	act->sa_sigaction = usr1action;
	sigaction(SIGUSR1, act, NULL);
}

static void	contact_server(pid_t spid, char *msg)
{
	int	b;
	int	ret;

	while (1)
	{
		b = 0x80;
		while (b)
		{
			usleep(100);
			if (*msg & b)
				ret = kill(spid, SIGUSR2);
			else
				ret = kill(spid, SIGUSR1);
			pause();
			if (ret == -1)
				print_signal_error();
			b >>= 1;
		}
		if (!*msg)
			break ;
		++msg;
	}
}

static void	usr1action(int sig, siginfo_t *info, void *ucontext)
{
	pid_t	spid;

	(void) ucontext;
	(void) sig;
	spid = ft_getpid(NULL);
	if (info->si_pid == spid)
		return ;
	else
		exit(0);
}
