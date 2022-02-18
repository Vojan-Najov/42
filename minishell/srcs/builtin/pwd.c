/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:29:07 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:51:26 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell_envp.h"
#include "minishell_errors.h"
#include <stdio.h>

int	ft_pwd(char **str)
{
	char	*s;

	(void) str;
	s = getcwd(0, 0);
	if (s)
	{
		printf("%s\n", s);
		free(s);
		return (0);
	}
	print_str_error("malloc");
	return (1);
}
