/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:30:10 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:49:02 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	ft_echo(char **s)
{
	size_t	i;
	size_t	len;
	short	flag;

	if ((!s[0] || !s[0][0]) && mas_size(s) == 0)
		return ((int) write(STDOUT_FILENO, "\n", 1) - 1);
	len = mas_size(s);
	flag = 0;
	i = -1;
	if (!ft_strcmp("-n", s[0]))
		flag = 1;
	while (s[++i + flag])
	{
		if (!ft_strlen(s[i + flag]))
			continue ;
		write(STDOUT_FILENO, s[i + flag], ft_strlen(s[i + flag]));
		if (i + flag != len - 1)
			write(STDOUT_FILENO, " ", 1);
	}
	if (!flag)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
