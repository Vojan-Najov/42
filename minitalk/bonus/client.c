/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:17:19 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/17 13:17:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//static const pid_t	g_spid;

int		ft_getpid(char *str);

void	contact_server(pid_t spid, char *msg);

void	redefine_signals(sigset_t *set, struct sigaction *act);

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
	//g_spid = spid;
	redefine_signals(&set, &act);
	contact_server(spid, argv[2]);
	return (0);
}

void	redefine_signals(sigset_t *set, struct sigaction *act)
{
	sigemptyset(set);
	sigaddset(set, SIGUSR1);
	act->sa_mask = *set;
	act->sa_flags = SA_RESTART;
	act->sa_handler = SIG_IGN; 
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
			if (ret == -1)
			{
				print_signal_error();
				exit(EXIT_FAILURE);
			}
			b >>= 1;
			pause();
		}
		if (!*msg)
			break ;
		++msg;
	}
}

int	ft_getpid(char *str)
{
	int		n;
	char	*s;

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
