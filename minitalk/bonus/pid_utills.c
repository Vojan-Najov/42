/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_utills.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:10:49 by ccartman          #+#    #+#             */
/*   Updated: 2021/09/23 17:12:20 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static const char				g_server_msg[] = "Server's PID: ";

pid_t	client_pid(pid_t pid)
{
	static pid_t	cpid;

	if (pid)
		cpid = pid;
	return (cpid);
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
	i = write(STDIN_FILENO, g_server_msg, sizeof(g_server_msg));
	i += write(STDIN_FILENO, s, n);
	if (i != sizeof(g_server_msg) + n)
		print_write_error();
}

int	ft_getpid(char *str)
{
	static int	n;
	char		*s;

	if (str == NULL)
		return (n);
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
