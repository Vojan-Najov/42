/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/22 19:02:54 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_count = 0;;

int		ft_getpid(char *str);

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
			if (*msg & b)
				ret = kill(spid, SIGUSR2);
			else
				ret = kill(spid, SIGUSR1);
			printf("client before pause:\n");
			pause();
			printf("client after pause\n");
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
	printf("bits = %d (%d bytes)\n", g_count, g_count / 8);
}

int	ft_getpid(char *str)
{
	static int	n;
	char		*s;

	if (str == NULL)
		return(n);
	s = str - 1;
	while (*++s)
		if (*s < '0' || *s > '9')
			return (-1);
	while (*str == '0')
		++str;
	n = 0;
	while (*str)
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	if (kill(n, 0) == -1)
		return (-1);
	return (n);
}

void	usr1action(int sig, siginfo_t *info, void *ucontext)
{
	pid_t	spid;

	(void) ucontext;
	(void) sig;
	spid = ft_getpid(NULL);
	if (info->si_pid == spid)
		++g_count;
	else
		exit(0);
}
