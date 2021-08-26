/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:38:30 by ccartman          #+#    #+#             */
/*   Updated: 2021/08/26 23:26:20 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	search_path(char *str);

int	main(int argc, char **argv, char **env)
{
	char	**paths;

	(void) argc;
	(void) argv;
	while (*env)
	{
		if (search_path(*env))
			break ;
		++env;
	}
	if (*env == NULL)
		return (1);
	paths = ft_split(&(*env)[5], ':');
	while (*paths)
	{
		printf("%s\n", *paths);
		++paths;
	}
	return (0);
}

static int	search_path(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T' && str[3] == 'H' && \
															str[4] == '=')
		return (1);
	return (0);
}

/*
 * int	p;
 * p = fork();
 * if (p == -1)
 * {
 * 		//
 * }
 * else if (p == 0)
 * {
 * 		// child
 * }
 * else
 * {
 * 		// parent
 * 	}
 */
