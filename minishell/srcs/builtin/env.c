/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoan <jjoan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:39:33 by jjoan             #+#    #+#             */
/*   Updated: 2022/02/17 11:50:04 by jjoan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_envp.h"
#include "libft.h"
#include <stdio.h>

int	ft_env(char **s)
{
	char	**env;
	size_t	i;

	(void) s;
	i = 0;
	env = get_envp();
	while (env[i])
	{
		if (ft_strchr(env[i], '='))
			printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
