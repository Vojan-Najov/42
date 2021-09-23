/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 15:58:46 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	contact_server(pid_t spid, char *msg);

void	redefine_signals(sigset_t *set, struct sigaction *act);

void	usr1action(int sig, siginfo_t *info, void *ucontext);

int	main(int argc, char **argv)
{
	pid_t				spid;
	struct sigaction	act;
	sigset_t			set;

	if (argc != 3)
		return (print_args_error());
	spid = ft_getpid(argv[1]);
	if (spid <= 0)
		return (print_pid_error());
	redefine_signals(&set, &act);
	contact_server(spid, argv[2]);
	return (0);
}

void	redefine_signals(sigset_t *set, struct sigaction *act)
{
	sigemptyset(set);
	sigaddset(set, SIGUSR1);
	act->sa_mask = *set;
	act->sa_flags = SA_RESTART | SA_SIGINFO;
	act->sa_sigaction = usr1action;
	sigaction(SIGUSR1, act, NULL);
}

void	contact_server(pid_t spid, char *msg)
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
			{
				print_signal_error();
				exit(EXIT_FAILURE);
			}
			b >>= 1;
		}
		if (!*msg)
			break ;
		++msg;
	}
}

void	usr1action(int sig, siginfo_t *info, void *ucontext)
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
