/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:47:32 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:50:31 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "minishell_errors.h"

static int	ft_check_exit(const char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
	{
		if (i == 0)
		{
			if (!(str[i] == '-' || str[i] == '+' || ft_isdigit(str[i])))
				return (255);
		}
		else
		{
			if (!ft_isdigit(str[i]))
				return (255);
		}
	}
	return (0);
}

static int	ft_exit_atoi(const char *str)
{
	short			sign;
	unsigned char	result;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while ('0' <= *str && *str <= '9')
	{
		result = 10 * result + (*str - '0');
		++str;
	}
	return (result * sign);
}

int	ft_exit(char **s)
{
	size_t	len;

	write(STDERR_FILENO, "exit\n", 5);
	len = mas_size(s);
	if (!len)
		exit (0);
	else if (ft_check_exit(s[0]))
	{
		print_err("exit", s[0], NUM_ERR);
		exit(255);
		return (1);
	}
	else if (len > 1)
	{
		print_err("exit", NULL, ARG_ERR);
		return (1);
	}
	exit(ft_exit_atoi(s[0]));
	return (1);
}
