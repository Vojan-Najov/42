/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:15:19 by ccartman          #+#    #+#             */
/*   Updated: 2022/02/17 16:52:09 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell_envp.h"
#include "minishell_errors.h"
#include "libft.h"

int	prepare_env(char **ev)
{
	int		lvl;
	char	*new_lvl;
	char	*tmp;

	set_exit_status(0);
	if (init_envp(ev))
		return (1);
	if (!ft_getenv_with_name("SHLVL"))
		return (0);
	lvl = ft_atoi(ft_getenv("SHLVL"));
	++lvl;
	tmp = ft_itoa(lvl);
	if (!tmp)
		return (print_str_error_with_return("malloc"));
	new_lvl = ft_strjoin("SHLVL=", tmp);
	free(tmp);
	if (!new_lvl)
		return (print_str_error_with_return("malloc"));
	ft_setenv(new_lvl);
	free(new_lvl);
	return (0);
}
