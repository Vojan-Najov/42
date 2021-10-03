/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:39:25 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 17:11:05 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_getpid(char *str);

static void	contact_server(pid_t spid, char *msg);

int	main(int argc, char **argv)
{
	pid_t	spid;

	if (argc != 3)
		return (print_args_error());
	spid = ft_getpid(argv[1]);
	if (spid <= 0)
		return (print_pid_error());
	contact_server(spid, argv[2]);
	return (0);
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
			if (*msg & b)
				ret = kill(spid, SIGUSR2);
			else
				ret = kill(spid, SIGUSR1);
			if (ret == -1)
				print_signal_error();
			b >>= 1;
			usleep(200);
		}
		if (!*msg)
			break ;
		++msg;
	}
}

static int	ft_getpid(char *str)
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
