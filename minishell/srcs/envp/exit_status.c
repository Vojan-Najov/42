/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:18:27 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 11:54:14 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell_errors.h"

int	*get_exit_status_int_address(void)
{
	static int	exit_status_int;

	return (&exit_status_int);
}

char	**get_exit_status_str_address(void)
{
	static char	*exit_status_str;

	return (&exit_status_str);
}

int	get_exit_status_int(void)
{
	int	*status;

	status = get_exit_status_int_address();
	return (*status);
}

char	*get_exit_status_str(void)
{
	char	**status;

	status = get_exit_status_str_address();
	return (*status);
}

void	set_exit_status(int status)
{
	int		*status_int;
	char	**status_str;
	char	*tmp;

	status_int = get_exit_status_int_address();
	*status_int = status;
	status_str = get_exit_status_str_address();
	tmp = *status_str;
	*status_str = ft_itoa(status);
	if (!*status_str)
	{
		print_str_error("malloc");
		*status_str = "0";
		return ;
	}
	free(tmp);
}
